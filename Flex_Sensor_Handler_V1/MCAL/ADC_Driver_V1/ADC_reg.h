
#ifndef MCAL_ADC_DRIVER_V1_ADC_REG_H_
#define MCAL_ADC_DRIVER_V1_ADC_REG_H_

#define ADC_ADMUX_REG		(*(volatile u8*)0x27)
#define ADC_ADCSRA_REG		(*(volatile u8*)0x26)
#define ADC_ADCL_REG		(*(volatile u8*)0x24)
#define	ADC_ADCH_REG		(*(volatile u8*)0x25)
#define	ADC_DATA_REG		(*(volatile u16*)0x24)
#define ADC_SFIOR_REG		(*(volatile u8*)0x50)


#define ADMUX_ADLAR_BIT				5
#define ADMUX_REFS0_BIT				6
#define ADMUX_REFS1_BIT				7

#define ADCSRA_ADIE_BIT				3
#define ADCSRA_ADIF_BIT				4
#define ADCSRA_ADATE_BIT			5
#define ADCSRA_ADSC_BIT				6
#define ADCSRA_ADEN_BIT				7


#endif /* MCAL_ADC_DRIVER_V1_ADC_REG_H_ */
