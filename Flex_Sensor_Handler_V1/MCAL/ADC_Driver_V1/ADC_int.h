

#ifndef MCAL_ADC_DRIVER_V1_ADC_INT_H_
#define MCAL_ADC_DRIVER_V1_ADC_INT_H_

/*
 * Use these macros in the configuration file for the PRESCALER
 */
#define ADC_PRESCALER_2			(u8)1
#define ADC_PRESCALER_4			(u8)2
#define ADC_PRESCALER_8			(u8)3
#define ADC_PRESCALER_16		(u8)4
#define ADC_PRESCALER_32		(u8)5
#define ADC_PRESCALER_64		(u8)6
#define ADC_PRESCALER_128		(u8)7

/*
 * use these macros in the configuration file for VOLTAGE_REFERENCE
 */
#define ADC_REF_VOLTAGE_AREF				1
#define ADC_REF_VOLTAGE_AVCC				2
#define ADC_REF_VOLTAGE_INTERNAL_2_56V		3

/*
 * use these macros in the configuration file for RESOLTOION
 */
#define ADC_RESOLUTION_8					1
#define ADC_RESOLUTION_10					2

typedef enum {
	e_ADC_channel_opt_ADC0= 					0,
	e_ADC_channel_opt_ADC1=						1,
	e_ADC_channel_opt_ADC2=						2,
	e_ADC_channel_opt_ADC3=						3,
	e_ADC_channel_opt_ADC4=						4,
	e_ADC_channel_opt_ADC5=						5,
	e_ADC_channel_opt_ADC6=						6,
	e_ADC_channel_opt_ADC7=						7,
	e_ADC_channel_opt_ADC0_ADC0_10x=			8,
	e_ADC_channel_opt_ADC1_ADC0_10x=			9,
	e_ADC_channel_opt_ADC0_ADC0_200x=			10,
	e_ADC_channel_opt_ADC1_ADC0_200x=			11,
	e_ADC_channel_opt_ADC2_ADC2_10x=			12,
	e_ADC_channel_opt_ADC3_ADC2_10x=			13,
	e_ADC_channel_opt_ADC2_ADC2_200x=			14,
	e_ADC_channel_opt_ADC3_ADC2_200x=			15,
	e_ADC_channel_opt_ADC0_ADC1_1x=				16,
	e_ADC_channel_opt_ADC1_ADC1_1x=				17,
	e_ADC_channel_opt_ADC2_ADC1_1x=				18,
	e_ADC_channel_opt_ADC3_ADC1_1x=				19,
	e_ADC_channel_opt_ADC4_ADC1_1x=				20,
	e_ADC_channel_opt_ADC5_ADC1_1x=				21,
	e_ADC_channel_opt_ADC6_ADC1_1x=				22,
	e_ADC_channel_opt_ADC7_ADC1_1x=				23,
	e_ADC_channel_opt_ADC0_ADC2_1x=				24,
	e_ADC_channel_opt_ADC1_ADC2_1x=				25,
	e_ADC_channel_opt_ADC2_ADC2_1x=				26,
	e_ADC_channel_opt_ADC3_ADC2_1x=				27,
	e_ADC_channel_opt_ADC4_ADC2_1x=				28,
	e_ADC_channel_opt_ADC5_ADC2_1x=				29,
	e_ADC_channel_opt_VBG=						30,
	e_ADC_channel_opt_GND=						31

}e_ADC_channel_opt;

typedef enum{
	e_ADC_trigger_source_Free_Run_Mod 			=0,
	e_ADC_trigger_source_Analog_Comparator 		=1,
	e_ADC_trigger_source_Ext_Irq_Req_0 			=2,
	e_ADC_trigger_source_Timer0_Compare_Match 	=3,
	e_ADC_trigger_source_Timer0_Overflow 			=4,
	e_ADC_trigger_source_Timer_Compare_Match_B 	=5,
	e_ADC_trigger_source_Timer1_Overflow 			=6,
	e_ADC_trigger_source_Timer1_Capture_Event 	=7,

}e_ADC_trigger_source;

/*
 * Use this function to enable the ADC Peripheral
 *
 * Parameters:
 * 				- void
 *
 * Return:
 * 				- void
 */
void ADC_vidInit(void);

/*
 * Use this function to start a single conversion.
 *
 * Parameters:
 * 				- (ADC_Channel_Opt)	the input channel\channels.
 *
 * Return:
 * 				- void
 */
void ADC_vidStartSignleConv(e_ADC_channel_opt Copy_e_ADC_channel_opt_channel);

/*
 * Use this function to start the first conversion in the auto trigger mode.
 *
 * Parameters:
 * 				- (ADC_Trigger_source)	the trigger source.
 * 				- (ADC_Channel_Opt)	the input channel\channels.
 *
 * Return:
 * 				- void
 */
void ADC_vidStartAutoTriggeredConv(e_ADC_trigger_source Copy_e_ADC_trigger_source_TriggerSrc, e_ADC_channel_opt Copy_e_ADC_channel_opt_channel);

/*
 * Use this function to get the analog voltage.
 *
 * Parameters:
 * 				- void
 *
 * Return:
 * 				- (u32) the analog voltage
 */

f32 ADC_f32GetAnalogValue_mv(void);

/*
 * Use this function to enable the ADC interrupt.
 *
 * Parameters:
 * 				- void
 *
 * Return:
 * 				- void
 */
void ADC_vidADCIrqEnable(void);

/*
 * Use this function to disable the ADC interrupt.
 *
 * Parameters:
 * 				- void
 *
 * Return:
 * 				- void
 */
void ADC_vidADCIrqDisable(void);

/*
 * Use this function to set the call back function in case of using the ADC interrupt.
 *
 * Parameters:
 * 				- void
 *
 * Return:
 * 				- void
 */
void ADC_vidSetCallBckFunc(void (*func_ptr)(void));

#endif /* MCAL_ADC_DRIVER_V1_ADC_INT_H_ */
