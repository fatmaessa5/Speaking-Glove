

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "./DFPLAYER_Private.h"
#include "./DFPLAYER_ErrorTypes.h"
#include "./DFPLAYER_Interface.h"

#include "../../MCAL/USART_Driver_V1/USART_ErrorTypes.h"
#include "../../MCAL/USART_Driver_V1/USART_Init.h"

DFPLAYER_Error_t DFPLAYER_Init(void)
{
	DFPLAYER_Error_t Local_ErrorStatus = DFPLAYER_Error_t_RT_OK;

	USART_Config_t Local_u8_USART_obj = {USART_Enable_t_TXAndRXEnable, USART_CharcterSize_t_8, USART_ParityMode_t_Disable, USART_StopBitSlct_t_OneBit, USART_Speed_t_NormalSpeed};

	USART_init(&Local_u8_USART_obj);

	return Local_ErrorStatus;
}

DFPLAYER_Error_t DFPLAYER_SendCMD(DFPLAYER_CMD_t Copy_u8Command, u16 Copy_u16Parameter)
{
	DFPLAYER_Error_t Local_ErrorStatus = DFPLAYER_Error_t_RT_OK;

	s16 Local_s16Checksum = 0;

	Local_s16Checksum = -(DFPLAYER_VERSION + DFPLAYER_LENGTH + Copy_u8Command + DFPLAYER_FEEDBACK + ((u8)(Copy_u16Parameter>>8))
			+ ((u8)Copy_u16Parameter) );


	if((Copy_u8Command >= DFPLAYER_CMD_t_Next) && (Copy_u8Command <= DFPLAYER_CMD_t_Queries_the_current_track_of_Flash))
	{
		USART_SendData(DFPLAYER_START);
		USART_SendData(DFPLAYER_VERSION);
		USART_SendData(DFPLAYER_LENGTH);
		USART_SendData(Copy_u8Command);
		USART_SendData(DFPLAYER_FEEDBACK);
		USART_SendData((Copy_u16Parameter>>8));			//MSB of the parameter
		USART_SendData(Copy_u16Parameter);				//LSB of the parameter
		USART_SendData((Local_s16Checksum>>8));			//MSB of the checksum
		USART_SendData(Local_s16Checksum);
		USART_SendData(DFPLAYER_END);
	}
	else
	{
		Local_ErrorStatus = DFPLAYER_Error_t_RT_WRONG_CMD;
	}

	return Local_ErrorStatus;
}
