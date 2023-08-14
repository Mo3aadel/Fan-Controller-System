 /******************************************************************************
 *
 * Module: DC_Motor
 *
 * File Name: DC_Motor.c
 *
 * Description: Source file for the DC_Motor driver
 *
 * Author: Mohamed Adel
 *
 *******************************************************************************/

#include"gpio.h"
#include"DC_Motor.h"
#include"PWM_Timer.h"
#include<util\delay.h>

uint8 duty_cyclee;

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN,PIN_OUTPUT);

	GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN,LOGIC_HIGH);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

    duty_cyclee= (uint8) (  (speed/100.0f)*255 ) ;

	PWM_Timer0_Start(duty_cyclee);

	switch(state){
		case stop:
			GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN, LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN, LOGIC_LOW);
			break;
		case CCW:
			GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN, LOGIC_LOW);
			GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN, LOGIC_HIGH);
			break;
		case CW:
			GPIO_writePin(DC_MOTOR_INPUT1_PORT,DC_MOTOR_INPUT1_PIN, LOGIC_HIGH);
			GPIO_writePin(DC_MOTOR_INPUT2_PORT,DC_MOTOR_INPUT2_PIN, LOGIC_LOW);
			break;
		}

}
