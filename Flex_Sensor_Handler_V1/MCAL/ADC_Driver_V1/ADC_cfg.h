

#ifndef MCAL_ADC_DRIVER_V1_ADC_CFG_H_
#define MCAL_ADC_DRIVER_V1_ADC_CFG_H_

/*
 * VOLTAGE_REFERENCE takes:
 * 							- ADC_REF_VOLTAGE_AREF or
 * 							- ADC_REF_VOLTAGE_AVCC or
 * 							- ADC_REF_VOLTAGE_INTERNAL_2.56V
 */
#define 	VOLTAGE_REFERENCE		ADC_REF_VOLTAGE_AVCC

/* Set this configuration if you used the AVCC option as a reference voltage to the ADC.
 *
 * AVCC takes:
 * 				- the VCC voltage
 */
#define AVCC						5

/* Set this configuration if you used the external AREF option as a reference voltage to the ADC.
 *
 * AREF takes:
 * 				- the external AREF voltage
 */
#define AREF

/*
 * PRESCALER takes:
 * 					- ADC_PRESCALER_2	or
 * 					- ADC_PRESCALER_4 	or
 * 					- ADC_PRESCALER_8 	or
 * 					- ADC_PRESCALER_16 	or
 * 					- ADC_PRESCALER_32 	or
 * 					- ADC_PRESCALER_64 	or
 * 					- ADC_PRESCALER_128
 */
#define 	PRESCALER				ADC_PRESCALER_64

/*
 * RESOLUTION takes:
 * 					- ADC_RESOLUTION_8
 * 					- ADC_RESOLUTION_10
 */

#define 	RESOLUTION				ADC_RESOLUTION_10

#endif /* MCAL_ADC_DRIVER_V1_ADC_CFG_H_ */
