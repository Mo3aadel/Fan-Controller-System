 /******************************************************************************
 *
 * Module: DC_Motor
 *
 * File Name: DC_Motor.h
 *
 * Description: header file for the DC_Motor driver
 *
 * Author: Mohamed Adel
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"std_types.h"
extern uint8 duty_cyclee;


#define DC_MOTOR_INPUT1_PORT     PORTB_ID
#define DC_MOTOR_INPUT1_PIN      PIN0_ID

#define DC_MOTOR_INPUT2_PORT     PORTB_ID
#define DC_MOTOR_INPUT2_PIN      PIN1_ID


typedef enum
{
    stop,CCW,CW
}DcMotor_State;



void DcMotor_Init(void);


void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
