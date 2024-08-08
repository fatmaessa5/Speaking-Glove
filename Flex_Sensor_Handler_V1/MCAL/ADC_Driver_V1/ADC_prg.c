

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../ADC_Driver_V1/ADC_int.h"
#include "../ADC_Driver_V1/ADC_cfg.h"
#include "../ADC_Driver_V1/ADC_reg.h"
#include "avr/interrupt.h"

#define NULL						(void *)0

#define ADC_PRESCALER_MASK			(u8)0b11111000
#define ADC_TRIGGER_SOURCE_MASK		(u8)0b00011111
#define ADC_INPUT_CHANNEL_MASK		(u8)0b11100000

void (* ADC_CALL_BCK_PTR)(void) = NULL;

ISR(ADC_vect){
	if(ADC_CALL_BCK_PTR != NULL){
		ADC_CALL_BCK_PTR();
	}
}

void ADC_vidInit(void){
	//set supply voltage reference
#if VOLTAGE_REFERENCE == ADC_REF_VOLTAGE_AREF
	CLR_BIT(ADC_ADMUX_REG, ADMUX_REFS0_BIT);
	CLR_BIT(ADC_ADMUX_REG, ADMUX_REFS1_BIT);
#elif VOLTAGE_REFERENCE == ADC_REF_VOLTAGE_AVCC
	SET_BIT(ADC_ADMUX_REG, ADMUX_REFS0_BIT);
	CLR_BIT(ADC_ADMUX_REG, ADMUX_REFS1_BIT);
#elif VOLTAGE_REFERENCE == ADC_REF_VOLTAGE_INTERNAL_2_56V
	SET_BIT(ADC_ADMUX_REG, ADMUX_REFS0_BIT);
	SET_BIT(ADC_ADMUX_REG, ADMUX_REFS1_BIT);
#else
#error "Wrong Reference voltage !"
#endif

	//set the prescaler
	ADC_ADCSRA_REG &= ADC_PRESCALER_MASK;
	ADC_ADCSRA_REG |= PRESCALER;

	//enable the ADC
	SET_BIT(ADC_ADCSRA_REG, ADCSRA_ADEN_BIT);

}

void ADC_vidStartSignleConv(e_ADC_channel_opt Copy_e_ADC_channel_opt_channel){
	//choose the input channel
	ADC_ADMUX_REG &= ADC_INPUT_CHANNEL_MASK;
	ADC_ADMUX_REG |= Copy_e_ADC_channel_opt_channel;

	//start a single conversion
	SET_BIT(ADC_ADCSRA_REG, ADCSRA_ADSC_BIT);
}

void ADC_vidStartAutoTriggeredConv(e_ADC_trigger_source Copy_e_ADC_trigger_source_TriggerSrc, e_ADC_channel_opt Copy_e_ADC_channel_opt_channel){
	//choose the input channel
	ADC_ADMUX_REG &= ADC_INPUT_CHANNEL_MASK;
	ADC_ADMUX_REG |= Copy_e_ADC_channel_opt_channel;

	//set the trigger source and start the conversion process
	ADC_SFIOR_REG &= ADC_TRIGGER_SOURCE_MASK;
	ADC_SFIOR_REG |= (Copy_e_ADC_trigger_source_TriggerSrc << 5);

	//enable the auto trigger
	SET_BIT(ADC_ADCSRA_REG, ADCSRA_ADATE_BIT);

	//start the first conversion
	SET_BIT(ADC_ADCSRA_REG, ADCSRA_ADSC_BIT);
}

f32 ADC_f32GetAnalogValue_mv(void){
	f32 local_f32AnalogVoltage_mv = 0;
	f32 local_f32RefVoltage_mv = 0;
	f32 local_f32Step_mv = 0;
#if VOLTAGE_REFERENCE == ADC_REF_VOLTAGE_AVCC
	local_f32RefVoltage_mv = ((f32)AVCC) * 1000;
#elif VOLTAGE_REFERENCE == ADC_REF_VOLTAGE_INTERNAL_2_56V
	local_f32RefVoltage_mv = ((f32)2.56) * 1000;
#elif VOLTAGE_REFERENCE == ADC_REF_VOLTAGE_AREF
	local_f32RefVoltage_mv = ((f32)AREF) * 1000;
#else
#error "Wrong Reference voltage !"
#endif

	//Set the adjustment direction
#if RESOLUTION == ADC_RESOLUTION_10
	CLR_BIT(ADC_ADMUX_REG, ADMUX_ADLAR_BIT);			//the result is right adjusted
	local_f32Step_mv = local_f32RefVoltage_mv / 1024;
	while(ADCSRA_ADIF_BIT == 0);
	local_f32AnalogVoltage_mv = ADC_DATA_REG * local_f32Step_mv;
#elif RESOLUTION == ADC_RESOLUTION_8
	SET_BIT(ADC_ADMUX_REG, ADMUX_ADLAR_BIT);			//the result is left adjusted
	local_f32Step_mv = local_f32RefVoltage_mv / 256;
	while(ADCSRA_ADIF_BIT == 0);
	local_f32AnalogVoltage_mv = ADC_ADCH_REG * local_f32Step_mv;
#else
#error "Wrong Resolution !"
#endif

	return local_f32AnalogVoltage_mv;
}

void ADC_vidADCIrqEnable(void){
	SET_BIT(ADC_ADCSRA_REG, ADCSRA_ADIE_BIT);
}

void ADC_vidADCIrqDisable(void){
	CLR_BIT(ADC_ADCSRA_REG, ADCSRA_ADIE_BIT);
}

void ADC_vidSetCallBckFunc(void (*func_ptr)(void)){
	if(func_ptr != NULL){
		ADC_CALL_BCK_PTR = func_ptr;
	}
}
