
#include "../LIB/STD_TYPES.h"
#include"../HAL/LCD_Handler_V1/LCD_int.h"
#include "../HAL/Flex_Sensor_Handler_V1/FLEX_Sensor_int.h"
#include "../MCAL/ADC_Driver_V1/ADC_int.h"
#include "avr/delay.h"

#include "../HAL/DFPLAYER_Handler_V1/DFPLAYER_ErrorTypes.h"
#include "../HAL/DFPLAYER_Handler_V1/DFPLAYER_Interface.h"

#define SENSOR_ONE		e_FLEX_sensor_No_3
#define SENSOR_TWO		e_FLEX_sensor_No_4
#define SENSOR_THREE	e_FLEX_sensor_No_5
#define SENSOR_FOUR		e_FLEX_sensor_No_6
#define SENSOR_FIVE		e_FLEX_sensor_No_7

void read_sensors(void);
void mapping(f64 sensor_read, u8 sensor_no);
u8 global_arr[8];
u8 APP_SOUND_TRACK_ARRAY[5]={0};

void main(void){
	u8 Local_u8Counter;
	DFPLAYER_Init();

	LCD_vidInit();
	FLEX_vidInit();
	//	f64 output_voltage_mv = 0;
	//	f64 sensor_res_ohm = 0;
	while(1){
		read_sensors();
		DFPLAYER_SendCMD(DFPLAYER_CMD_t_Specify_volume,30);

		if(global_arr[SENSOR_ONE] == 'A' && global_arr[SENSOR_TWO] == 'A' && global_arr[SENSOR_THREE] == 'A'
				&& global_arr[SENSOR_FOUR] == 'A' && global_arr[SENSOR_FIVE] == 'A')
		{
			LCD_u8Goto(2, 10);
			LCD_vidSendString((u8 *)"Five");
			if(APP_SOUND_TRACK_ARRAY[4] == 0)
			{
				DFPLAYER_SendCMD(DFPLAYER_CMD_t_Specify_tracking,5);
				for(Local_u8Counter = 0; Local_u8Counter <5 ; Local_u8Counter++)
				{
					APP_SOUND_TRACK_ARRAY[Local_u8Counter] =0;
				}
				APP_SOUND_TRACK_ARRAY[4] =1;
			}
			else
			{
				//DoNothing
			}


		}

		else if(global_arr[SENSOR_ONE] == 'A' && global_arr[SENSOR_TWO] == 'B' && global_arr[SENSOR_THREE] == 'B'
				&& global_arr[SENSOR_FOUR] == 'B' && global_arr[SENSOR_FIVE] == 'B')
		{
			LCD_u8Goto(2, 10);
			LCD_vidSendString((u8 *)"ThumbUp");
		}
		else if(global_arr[SENSOR_ONE] == 'B' && global_arr[SENSOR_TWO] == 'A' && global_arr[SENSOR_THREE] == 'B'
				&& global_arr[SENSOR_FOUR] == 'B' && global_arr[SENSOR_FIVE] == 'B')
		{
			LCD_u8Goto(2, 10);
			LCD_vidSendString((u8 *)"One");
			if(APP_SOUND_TRACK_ARRAY[0] == 0)
			{
				DFPLAYER_SendCMD(DFPLAYER_CMD_t_Specify_tracking,1);
				for(Local_u8Counter = 0; Local_u8Counter <5 ; Local_u8Counter++)
				{
					APP_SOUND_TRACK_ARRAY[Local_u8Counter] =0;
				}
				APP_SOUND_TRACK_ARRAY[0] =1;
			}
			else
			{
				//DoNothing
			}
		}
		else if(global_arr[SENSOR_ONE] == 'B' && global_arr[SENSOR_TWO] == 'A' && global_arr[SENSOR_THREE] == 'A'
				&& global_arr[SENSOR_FOUR] == 'B' && global_arr[SENSOR_FIVE] == 'B')
		{
			LCD_u8Goto(2, 10);
			LCD_vidSendString((u8 *)"Two");

			if(APP_SOUND_TRACK_ARRAY[1] == 0)
			{
				DFPLAYER_SendCMD(DFPLAYER_CMD_t_Specify_tracking,2);
				for(Local_u8Counter = 0; Local_u8Counter <5 ; Local_u8Counter++)
				{
					APP_SOUND_TRACK_ARRAY[Local_u8Counter] =0;
				}
				APP_SOUND_TRACK_ARRAY[1] =1;
			}
			else
			{
				//DoNothing
			}
		}
		else if(global_arr[SENSOR_ONE] == 'B' && global_arr[SENSOR_TWO] == 'A' && global_arr[SENSOR_THREE] == 'A'
				&& global_arr[SENSOR_FOUR] == 'A' && global_arr[SENSOR_FIVE] == 'B')
		{
			LCD_u8Goto(2, 10);
			LCD_vidSendString((u8 *)"Three");
			if(APP_SOUND_TRACK_ARRAY[2] == 0)
			{
				DFPLAYER_SendCMD(DFPLAYER_CMD_t_Specify_tracking,3);
				for(Local_u8Counter = 0; Local_u8Counter <5 ; Local_u8Counter++)
				{
					APP_SOUND_TRACK_ARRAY[Local_u8Counter] =0;
				}
				APP_SOUND_TRACK_ARRAY[2] =1;
			}
			else
			{
				//DoNothing
			}
		}

		else if(global_arr[SENSOR_ONE] == 'B' && global_arr[SENSOR_TWO] == 'A' && global_arr[SENSOR_THREE] == 'A'
				&& global_arr[SENSOR_FOUR] == 'A' && global_arr[SENSOR_FIVE] == 'A')
		{
			LCD_u8Goto(2, 10);
			LCD_vidSendString((u8 *)"Four");
			if(APP_SOUND_TRACK_ARRAY[3] == 0)
			{
				DFPLAYER_SendCMD(DFPLAYER_CMD_t_Specify_tracking,4);
				for(Local_u8Counter = 0; Local_u8Counter <5 ; Local_u8Counter++)
				{
					APP_SOUND_TRACK_ARRAY[Local_u8Counter] =0;
				}
				APP_SOUND_TRACK_ARRAY[3] =1;
			}
			else
			{
				//DoNothing
			}
		}


		_delay_ms(200);

	}
}

void read_sensors(void)
{
	f64 sensor_res_ohm = 0;
	LCD_vidClear();

	FLEX_u8GetResValue_ohm(SENSOR_ONE, &sensor_res_ohm);
	LCD_u8Goto(1, 1);
	LCD_vidSendInt(sensor_res_ohm/1000);
	mapping(sensor_res_ohm, SENSOR_ONE);

	FLEX_u8GetResValue_ohm(SENSOR_TWO, &sensor_res_ohm);
	LCD_u8Goto(1, 5);
	LCD_vidSendInt(sensor_res_ohm/1000);
	mapping(sensor_res_ohm, SENSOR_TWO);

	FLEX_u8GetResValue_ohm(SENSOR_THREE, &sensor_res_ohm);
	LCD_u8Goto(1, 9);
	LCD_vidSendInt(sensor_res_ohm/1000);
	mapping(sensor_res_ohm, SENSOR_THREE);

	FLEX_u8GetResValue_ohm(SENSOR_FOUR, &sensor_res_ohm);
	LCD_u8Goto(2, 1);
	LCD_vidSendInt(sensor_res_ohm/1000);
	mapping(sensor_res_ohm, SENSOR_FOUR);

	FLEX_u8GetResValue_ohm(SENSOR_FIVE, &sensor_res_ohm);
	LCD_u8Goto(2, 5);
	LCD_vidSendInt(sensor_res_ohm/1000);
	mapping(sensor_res_ohm, SENSOR_FIVE);
}

void mapping(f64 sensor_read, u8 sensor_no)
{
	switch(sensor_no)
	{
	case SENSOR_ONE:
		if(sensor_read <= (f64)35000)
		{
			global_arr[SENSOR_ONE] = 'A';
		}
		//		else if(sensor_read <= 34 && sensor_read >= 30)
		//		{
		//			global_arr[0] = 'B';
		//		}
		else //if(sensor_read <= (f64)80000)
		{
			global_arr[SENSOR_ONE] = 'B';
		}
		break;
	case SENSOR_TWO:
		if(sensor_read <= (f64)32000)
		{
			global_arr[SENSOR_TWO] = 'A';
		}
		else //if(sensor_read <= (f64)52000)
		{
			global_arr[SENSOR_TWO] = 'B';
		}

		break;
	case SENSOR_THREE:
		if(sensor_read <= (f64)39000)
		{
			global_arr[SENSOR_THREE] = 'A';
		}
		else //if(sensor_read <= (f64)65000)
		{
			global_arr[SENSOR_THREE] = 'B';
		}
		//		else if( sensor_read <= 40)
		//		{
		//			global_arr[2] = 'B';
		//		}

		break;

	case SENSOR_FOUR:
		if(sensor_read <= (f64)40000)
		{
			global_arr[SENSOR_FOUR] = 'A';
		}
		else //if(sensor_read <= (f64)105000)
		{
			global_arr[SENSOR_FOUR] = 'B';
		}
		//		else if( sensor_read <= 40)
		//		{
		//			global_arr[2] = 'B';
		//		}

		break;
	case SENSOR_FIVE:
		if(sensor_read <= (f64)40000)
		{
			global_arr[SENSOR_FIVE] = 'A';
		}
		else //if(sensor_read <= (f64)80000)
		{
			global_arr[SENSOR_FIVE] = 'B';
		}
		//		else if( sensor_read <= 40)
		//		{
		//			global_arr[2] = 'B';
		//		}

		break;


	}
}

/*
 * LCD_vidInit();
	FLEX_vidInit();
	f64 output_voltage_mv = 0;
	f64 sensor_res_ohm = 0;
	while(1){
		LCD_vidClear();
		LCD_vidSendString((u8 *)"Voltage_mv= ");
		FLEX_u8GetVolageValue_mv(e_FLEX_sensor_No_0, &output_voltage_mv);
		LCD_vidSendInt(output_voltage_mv);
		LCD_u8Goto(2,1);
		LCD_vidSendString((u8 *)"res_ohm= ");
		FLEX_u8GetResValue_ohm(e_FLEX_sensor_No_0, &sensor_res_ohm);
		LCD_vidSendInt(sensor_res_ohm);
		_delay_ms(500);

	}
 */
