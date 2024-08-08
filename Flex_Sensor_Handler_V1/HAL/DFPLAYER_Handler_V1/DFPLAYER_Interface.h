
#ifndef HAL_DFPLAYER_INTERFACE_H_
#define HAL_DFPLAYER_INTERFACE_H_

typedef enum{
	DFPLAYER_CMD_t_Next										= 0x01,
	DFPLAYER_CMD_t_Previous									= 0x02,
	DFPLAYER_CMD_t_Specify_tracking							= 0x03,
	DFPLAYER_CMD_t_Increase_volume							= 0x04,
	DFPLAYER_CMD_t_Decrease_volume							= 0x05,
	DFPLAYER_CMD_t_Specify_volume							= 0x06,
	DFPLAYER_CMD_t_Pause									= 0x0E,
	DFPLAYER_CMD_t_Queries_the_current_track_of_Flash		= 0x4D
}DFPLAYER_CMD_t;

/*
 * Use this function to initiate the DFPLAYER
 * it takes:
 * 			- void
 * it returns:
 * 			-  the error status (DFPLAYER_Error_t)
 */
DFPLAYER_Error_t DFPLAYER_Init(void);

/*
 * Use this function to send a command to the DFPLAYER
 * it takes:
 * 			1- the command (DFPLAYER_CMD_t)
 * 			2- the parameter of that command if any (u16)
 * it returns:
 * 			-  the error status (DFPLAYER_Error_t)
 */
DFPLAYER_Error_t DFPLAYER_SendCMD(DFPLAYER_CMD_t Copy_u8Command, u16 Copy_u16Parameter);

#endif /* HAL_DFPLAYER_INTERFACE_H_ */
