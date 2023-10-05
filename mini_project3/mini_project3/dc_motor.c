/******************************************************************************
 *
 * Module: DC motor
 *
 * File Name: DC Motor.c
 *
 * Description: Source file for the AVR DC motor driver
 *
 * Author: Esraa Fawzy
 *
 *******************************************************************************/
#include"dc_motor.h"
#include"TIMER0.h"

void DcMotor_init(void)
{	/* set pins of dc motor as output pins */
	GPIO_setupPinDirection(DcMotor_PORT_ID, DcMotor_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DcMotor_PORT_ID, DcMotor_PIN2_ID, PIN_OUTPUT);
	/*stop motor at first*/
	GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	/* Choose state for DC-motor */
	if(state == STOP)
	{
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_LOW);
	}
	else if (state == CLOCKWISE)
	{
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
	else if (state==ANTI_CLOCKWISE)
	{
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DcMotor_PORT_ID, DcMotor_PIN2_ID, LOGIC_HIGH);
		PWM_Timer0_Start(speed);
	}

}

