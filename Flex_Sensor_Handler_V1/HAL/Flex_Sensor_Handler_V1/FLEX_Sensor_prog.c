
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC_Driver_V1/ADC_int.h"
#include "FLEX_Sensor_cfg.h"
#include "FLEX_Sensor_err.h"
#include "FLEX_Sensor_int.h"

void FLEX_vidInit(void){
	ADC_vidInit();
}

u8 FLEX_u8GetVolageValue_mv(e_FLEX_sensor_No Copy_e_FLEX_sensor_No_FlexNumber, f64 *Copy_f32VolValPtr){
	u8 Local_u8ErrorStatus =  FLEX_GET_VALUE_RT_IS_OK;

	switch (Copy_e_FLEX_sensor_No_FlexNumber){
	case e_FLEX_sensor_No_0:
#if FLEX_SENSOR_0_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC0);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;

	case e_FLEX_sensor_No_1:
#if FLEX_SENSOR_1_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC1);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;
	case e_FLEX_sensor_No_2:
#if FLEX_SENSOR_2_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC2);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;

	case e_FLEX_sensor_No_3:
#if FLEX_SENSOR_3_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC3);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;
	case e_FLEX_sensor_No_4:
#if FLEX_SENSOR_4_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC4);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;
	case e_FLEX_sensor_No_5:
#if FLEX_SENSOR_5_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC5);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;
	case e_FLEX_sensor_No_6:
#if FLEX_SENSOR_6_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC6);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;
	case e_FLEX_sensor_No_7:
#if FLEX_SENSOR_7_STATUS == ENABLE
		ADC_vidStartSignleConv(e_ADC_channel_opt_ADC7);
		*Copy_f32VolValPtr = ADC_f32GetAnalogValue_mv();
#else
		Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED;

#endif
		break;
	default: Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_WRONG_SENSOR_NUMBER ;
	};
	return Local_u8ErrorStatus;
}


u8 FLEX_u8GetResValue_ohm(e_FLEX_sensor_No Copy_e_FLEX_sensor_No_FlexNumber, f64 *Copy_f32ResValPtr){
	u8 Local_u8ErrorStatus = FLEX_GET_VALUE_RT_IS_OK;
	f32 Local_f32OutputVoltageValue_mv = 0;
	Local_u8ErrorStatus = FLEX_u8GetVolageValue_mv(Copy_e_FLEX_sensor_No_FlexNumber, &Local_f32OutputVoltageValue_mv);
#if CONNECTION_TYPE == PULL_UP

	//From the voltage divider rule
	*Copy_f32ResValPtr = (Local_f32OutputVoltageValue_mv * (f64)(FIXED_RESISTOR_VALUE_OHM)) / ( ((f64)(VCC_VALUE_VOLT * 1000)) - Local_f32OutputVoltageValue_mv);

#elif CONNECTION_TYPE == PULL_DOWN

	//From the voltage divider rule
	*Copy_f32ResValPtr = ( ( (f64) (FIXED_RESISTOR_VALUE_OHM ) ) * ((f64)(VCC_VALUE_VOLT * 1000) - Local_f32OutputVoltageValue_mv) ) / Local_f32OutputVoltageValue_mv;

#endif

	return Local_u8ErrorStatus;
}
