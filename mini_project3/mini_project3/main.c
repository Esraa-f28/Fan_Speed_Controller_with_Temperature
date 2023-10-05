/******************************************************************************
 *
 * Module:
 *
 * File Name:
 *
 * Description:
 *
 * Author: Esraa Fawzy
 *
 *******************************************************************************/
#include "lcd.h"
#include"lm35_sensor.h"
#include"dc_motor.h"
#include"adc.h"


int main(void)
{

	LCD_init();
	DcMotor_init();
	DcMotor_Rotate(STOP,0);
	ADC_ConfigType ADC={INTERNAL,PRE8};
	ADC_ConfigType * Config_Ptr=&ADC;
	ADC_init(Config_Ptr);
	uint8 temp=0,prevTemp=0;
	while(1){
		temp=LM35_getTemperature(Config_Ptr);

		if(temp!=prevTemp)
		{

			if(temp<30)
			{
				LCD_clearScreen();
				DcMotor_Rotate(STOP,0);
				LCD_displayStringRowColumn(0,3,"FAN IS OFF");
				LCD_displayStringRowColumn(1,3,"Temp = ");
				LCD_intgerToString(temp);
				LCD_displayCharacter(0xDF);
				LCD_displayCharacter('C');

			}
			else if(temp >= 30 && temp < 60)
			{
				LCD_clearScreen();
				DcMotor_Rotate(CLOCKWISE,25);
				LCD_displayStringRowColumn(0,3,"FAN IS ON");
				LCD_displayStringRowColumn(1,3,"Temp = ");
				LCD_intgerToString(temp);
				LCD_displayCharacter(0xDF);
				LCD_displayCharacter('C');
			}
			else if (temp >= 60 && temp < 90)
			{
				LCD_clearScreen();
				DcMotor_Rotate(CLOCKWISE,50);
				LCD_displayStringRowColumn(0,3,"FAN IS ON");
				LCD_displayStringRowColumn(1,3,"Temp = ");
				LCD_intgerToString(temp);
				LCD_displayCharacter(0xDF);
				LCD_displayCharacter('C');
			}
			else if (temp >= 90 && temp < 120)
			{
				LCD_clearScreen();
				DcMotor_Rotate(CLOCKWISE,75);
				LCD_displayStringRowColumn(0,3,"FAN IS ON");
				LCD_displayStringRowColumn(1,3,"Temp = ");
				LCD_intgerToString(temp);
				LCD_displayCharacter(0xDF);
				LCD_displayCharacter('C');
			}
			else
			{
				LCD_clearScreen();
				DcMotor_Rotate(CLOCKWISE,100);
				LCD_displayStringRowColumn(0,3,"FAN IS ON");
				LCD_displayStringRowColumn(1,3,"Temp = ");
				LCD_intgerToString(temp);
				LCD_displayCharacter(0xDF);
				LCD_displayCharacter('C');
			}


		}
		prevTemp=temp;

	}
}
