
#ifndef HAL_LCD_HANDLER_V1_LCD_CFG_H_
#define HAL_LCD_HANDLER_V1_LCD_CFG_H_

/*
 * LCD_MODE takes:
 * 					- EIGHT_BITS
 * 					- FOUR_BITS
 */
#define LCD_MODE		EIGHT_BITS

/*
 * NO_OF_LINES takes:
 * 					- ONE_LINE
 * 					- TWO_LINES
 */
#define NO_OF_LINES		TWO_LINES


/*
 * DISPLAY_STATE, CURSOR_STATE, CURSOR_BLINKING AND DISPLAY_SHIFT_OPERATION take:
 * 																				- ON
 * 																				- OFF
 */
#define DISPLAY_STATE				ON
#define CURSOR_STATE				ON
#define CURSOR_BLINKING				OFF
#define DISPLAY_SHIFT_OPERATION		OFF

/*
 * CURSOR_MOVE_DIRECTION takes:
 * 					- INCREMENT
 * 					- DECREMENT
 */
#define CURSOR_MOVE_DIRECTION		INCREMENT

/*
 * LCD_DATA_PORT, RS_PORT, RW_PORT and E_PORT take:
 * 					- PORTA
 * 					- PORTB
 * 					- PORTC
 * 					- PORTD
 */
#define LCD_DATA_PORT				PORTC
#define RS_PORT						PORTB
#define RW_PORT						PORTB
#define E_PORT						PORTB



/*
 * DB4_PIN, RS_PIN, RW_PIN and E_PIN take:
 * 					- PIN0
 * 					- PIN1
 * 						.
 * 						.
 * 					- PIN7
 */
#define RS_PIN						PIN0
#define RW_PIN						PIN1
#define E_PIN						PIN2

//Use this configuration in case of 4bits mode to specify the pin of DB4
#define DB4_PIN						PIN0

#endif /* HAL_LCD_HANDLER_V1_LCD_CFG_H_ */
