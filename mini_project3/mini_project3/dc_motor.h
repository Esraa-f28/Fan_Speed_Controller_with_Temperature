/******************************************************************************
 *
 * Module: DC motor
 *
 * File Name: DC Motor.h
 *
 * Description: Source file for the AVR DC motor driver
 *
 * Author: Esraa Fawzy
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include"gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DcMotor_PORT_ID PORTB_ID
#define DcMotor_PIN1_ID PIN0_ID
#define DcMotor_PIN2_ID PIN1_ID


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
	STOP,CLOCKWISE,ANTI_CLOCKWISE
}DcMotor_State;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*Description
 *The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.*/
void DcMotor_init(void);

/*Description:
 *The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
