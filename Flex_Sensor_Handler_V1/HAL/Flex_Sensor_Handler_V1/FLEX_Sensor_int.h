

#include "../../LIB/STD_TYPES.h"

#ifndef HAL_FLEX_SENSOR_HANDLER_V1_FLEX_SENSOR_INT_H_
#define HAL_FLEX_SENSOR_HANDLER_V1_FLEX_SENSOR_INT_H_

/*
 * Use these options for the CONNECTION_TYPE in the configuration file
 */
#define PULL_UP			1
#define PULL_DOWN		2

/*
 * Use these options for each FLEX_SENSOR_STATUS in the configuration file
 */
#define ENABLE 			1
#define DISABLE			2

/*
 *
 */

/*
 * use one of this enum values as a parameter to FLEX_u8GetValue function to specify which sensor's value is required.
 */
typedef enum{
		e_FLEX_sensor_No_0,		//connected to pin_0 of the ADC_Port
		e_FLEX_sensor_No_1,		//connected to pin_1 of the ADC_Port
		e_FLEX_sensor_No_2,		//connected to pin_2 of the ADC_Port
		e_FLEX_sensor_No_3,		//connected to pin_3 of the ADC_Port
		e_FLEX_sensor_No_4,		//connected to pin_4 of the ADC_Port
		e_FLEX_sensor_No_5,		//connected to pin_5 of the ADC_Port
		e_FLEX_sensor_No_6,		//connected to pin_6 of the ADC_Port
		e_FLEX_sensor_No_7		//connected to pin_7 of the ADC_Port
} e_FLEX_sensor_No;

/*
 * use this function first to initiate the FLEX sensors
 *  it takes:
 *  		- void
 *  it returns:
 *  		- void
 */
void FLEX_vidInit(void);

/*
 * Use this function to get the output voltage in millivolt
 * 	it takes:
 * 				1- the flex sensor number   (e_FLEX_sensor_No)
 * 				2- address of an f32 variable where the output voltage value in millivolt will be stored	(f32 *)
 * 	it returns:
 * 				1- FLEX_GET_VALUE_RT_IS_OK (u8)  or
 * 				2- FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED (u8)  or
 * 				3- FLEX_GET_VALUE_RT_IS_WRONG_SENSOR_NUMBER	(u8)
 */
u8 FLEX_u8GetVolageValue_mv(e_FLEX_sensor_No Copy_e_FLEX_sensor_No_FlexNumber, f64 *Copy_f32ValPtr);

/*
 * Use this function to get the value of the flex sensor resistor in ohms
 * 	it takes:
 * 				1- the flex sensor number   (e_FLEX_sensor_No)
 * 				2- address of an f32 variable where the resistor value in ohms will be stored	(f32 *)
 * 	it returns:
 * 				1- FLEX_GET_VALUE_RT_IS_OK (u8)  or
 * 				2- FLEX_GET_VALUE_RT_IS_SENSOR_NOT_ENABLED (u8)  or
 * 				3- FLEX_GET_VALUE_RT_IS_WRONG_SENSOR_NUMBER	(u8)
 */
u8 FLEX_u8GetResValue_ohm(e_FLEX_sensor_No Copy_e_FLEX_sensor_No_FlexNumber,f64 *Copy_f32ValPtr);

#endif /* HAL_FLEX_SENSOR_HANDLER_V1_FLEX_SENSOR_INT_H_ */
