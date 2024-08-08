
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO_Driver_V1/DIO_int.h"
#include "../LCD_Handler_V1/LCD_cfg.h"
#include "../LCD_Handler_V1/LCD_int.h"
#include "../LCD_Handler_V1/LCD_cmds.h"
#include "../LCD_Handler_V1/LCD_err.h"
#include "avr/delay.h"

//function to initialize the LCD
void LCD_vidInit(void){
	u8 local_u8SetFunction = SET_FUNCTION_CMD;
	u8 local_u8DisplayControl = DISPLAY_CONTROL;
	u8 local_u8EntryModeSet = ENTRY_MODE_SET;

	local_u8SetFunction 	|= ((LCD_MODE<<4) | (NO_OF_LINES<<3));
	local_u8DisplayControl 	|= ((DISPLAY_STATE <<2) | (CURSOR_STATE <<1) | CURSOR_BLINKING);
	local_u8EntryModeSet   	|= ((CURSOR_MOVE_DIRECTION<<1) | (DISPLAY_SHIFT_OPERATION));

	DIO_u8SetPortDir(LCD_DATA_PORT, FULL_OUTPUT);
	DIO_u8SetPinDir(RS_PORT, RS_PIN, OUTPUT);
	DIO_u8SetPinDir(RW_PORT, RW_PIN, OUTPUT);
	DIO_u8SetPinDir(E_PORT, E_PIN, OUTPUT);


#if  LCD_MODE == EIGHT_BITS
	_delay_ms(40);
	LCD_vidSendCmd(local_u8SetFunction);
	_delay_us(50);
	LCD_vidSendCmd(local_u8DisplayControl);
	_delay_us(50);
	LCD_vidSendCmd(DISPLAY_CLEAR);
	_delay_ms(2);
	LCD_vidSendCmd(local_u8EntryModeSet);

#elif LCD_MODE == FOUR_BITS
#else
#error "Wrong Configuration !"
#endif
}

//function to send command
void LCD_vidSendCmd(u8 Copy_u8Cmd){
	DIO_u8SetPinVal(RS_PORT, RS_PIN, LOW);
	DIO_u8SetPinVal(RW_PORT, RW_PIN, LOW);

#if  LCD_MODE == EIGHT_BITS
	DIO_u8SetPinVal(E_PORT, E_PIN, HIGH);
	DIO_u8SetPortVal(LCD_DATA_PORT, Copy_u8Cmd);
	DIO_u8SetPinVal(E_PORT, E_PIN, LOW);
	_delay_us(1);
#elif LCD_MODE == FOUR_BITS

#else
#error "Wrong Configuration !"
#endif
}
//function to send data
void LCD_vidWriteChar(u8 Copy_u8Char){
	DIO_u8SetPinVal(RS_PORT, RS_PIN, HIGH);
	DIO_u8SetPinVal(RW_PORT, RW_PIN, LOW);

#if  LCD_MODE == EIGHT_BITS
	DIO_u8SetPinVal(E_PORT, E_PIN, HIGH);
	DIO_u8SetPortVal(LCD_DATA_PORT, Copy_u8Char);
	DIO_u8SetPinVal(E_PORT, E_PIN, LOW);
	_delay_us(1);
#elif LCD_MODE == FOUR_BITS

#else
#error "Wrong Configuration !"
#endif
}

//function to clear the display
void LCD_vidClear(void){
	LCD_vidSendCmd(DISPLAY_CLEAR);
	_delay_us(100);								//delay to force the next instructions to wait until the clear ins is executed
}

//function to go to specific segment
u8 LCD_u8Goto(u8 Copy_u8Row, u8 Copy_u8Col){
	u8 local_u8ErrorStatus = RT_OK;
	u8 local_u8Set_DDRAM_Address = SET_DDRAM_ADDRESS;

	switch(Copy_u8Row){
	case 1:
		if(Copy_u8Col <= 64){
			local_u8Set_DDRAM_Address += (Copy_u8Col - 1);
			LCD_vidSendCmd(local_u8Set_DDRAM_Address);
		}else{
			local_u8ErrorStatus = RT_WRONG_COLUMN_NUMBER;
		}
		break;
	case 2:
		if(Copy_u8Col <= 16){
			local_u8Set_DDRAM_Address += (64 + (Copy_u8Col-1));
			LCD_vidSendCmd(local_u8Set_DDRAM_Address);
		}else{
			local_u8ErrorStatus = RT_WRONG_COLUMN_NUMBER;
		}
		break;
	default:
		local_u8ErrorStatus = RT_WRONG_ROW_NUMBER;
	}

	return local_u8ErrorStatus;
}

//function to send string
void LCD_vidSendString(u8 * Copy_u8CharPtr){
	u8 i =0;
	while(*(Copy_u8CharPtr + i) != '\0'){
		LCD_vidWriteChar(* (Copy_u8CharPtr + i));
		i++;
	}
}

//function to display integers
void LCD_vidSendInt(u32 Copy_u32IntNumber){
	if(Copy_u32IntNumber != 0){
		u32 local_u32NewNumber = 0;
		u8 local_u8NewDigit = 0;
		u8 counter = 0;
		while(Copy_u32IntNumber !=0){
			local_u8NewDigit = Copy_u32IntNumber % 10;
			local_u32NewNumber = (local_u32NewNumber * 10) + local_u8NewDigit;
			Copy_u32IntNumber /= 10;
			counter++;
		}

		while(local_u32NewNumber !=0 ){
			local_u8NewDigit = local_u32NewNumber % 10;
			local_u32NewNumber /= 10;
			LCD_vidWriteChar('0' + local_u8NewDigit);
			counter--;
		}

		while(counter !=0){
			LCD_vidWriteChar('0');
			counter--;
		}
	}else{
		LCD_vidWriteChar('0');
	}

}

//function to shift right
void LCD_vidShiftDisplayRight(void){
	u8 local_u8ShiftDisplayRightCmd = SHIFT_ENTIRE_DISPLAY ;
	SET_BIT(local_u8ShiftDisplayRightCmd, 2);
	LCD_vidSendCmd(local_u8ShiftDisplayRightCmd);
}

//function to shift left
void LCD_vidShiftDisplayLeft(void){
	u8 local_u8ShiftDisplayLeftCmd = SHIFT_ENTIRE_DISPLAY;
	CLR_BIT(local_u8ShiftDisplayLeftCmd, 2);
	LCD_vidSendCmd(local_u8ShiftDisplayLeftCmd);
}

//function to shift the cursor left
void LCD_vidShiftCursorLeft(void){
	u8 local_u8ShiftCursorLeftCmd = SHIFT_CURSOR;
	CLR_BIT(local_u8ShiftCursorLeftCmd, 2);
	LCD_vidSendCmd(local_u8ShiftCursorLeftCmd);
}
//function to shift the cursor right
void LCD_vidShiftCursorRight(void){
	u8 local_u8ShiftCursorRightCmd = SHIFT_CURSOR;
	SET_BIT(local_u8ShiftCursorRightCmd, 2);
	LCD_vidSendCmd(local_u8ShiftCursorRightCmd);
}
