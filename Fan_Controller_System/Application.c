/*
 * Application.c
 *
 *  Created on: May 27, 2023
 *      Author: HP
 */


#include"adc.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"DC_Motor.h"
#include"PWM_Timer.h"


int main(void)
{
	uint8 temp_valuee;
	DcMotor_State motor_state=stop;
	uint8 motor_speed=0;
	char* fan_state="OFF";

	ADC_ConfigType config={Internal_VREF,FCPU_8};

	ADC_init(&config);
	LCD_init();
	DcMotor_Init();

	LCD_moveCursor(0,2);
	LCD_displayString("Fan is ");

	LCD_moveCursor(1,2);
	LCD_displayString("Temp is :   C");

	while(1)
	{
		temp_valuee=LM35_getTemperature();
		LCD_moveCursor(1,12);

		if(temp_valuee >= 100)
		{
			LCD_intgerToString(temp_valuee);
		}
		else
		{
			LCD_intgerToString(temp_valuee);
			LCD_displayCharacter('  ');
		}


		if(temp_valuee<30)
		{
			fan_state="OFF";
			motor_state=stop;
			motor_speed=0;
		}
		else if(temp_valuee>=30 && temp_valuee<60)
		{
			fan_state="ONN";
			motor_state=CW;
			motor_speed=25;
		}
		else if(temp_valuee>=60 && temp_valuee<90)
		{
			fan_state="ONN";
			motor_state=CW;
			motor_speed=50;
		}
		else if(temp_valuee>=90 && temp_valuee<120)
		{
			fan_state="ONN";
			motor_state=CW;
			motor_speed=75;
		}
		else if(temp_valuee>=120)
		{
			fan_state="ONN";
			motor_state=CW;
			motor_speed=100;
		}

		DcMotor_Rotate(motor_state,motor_speed);

		LCD_moveCursor(0,10);
		LCD_displayString(fan_state);

	}

}
