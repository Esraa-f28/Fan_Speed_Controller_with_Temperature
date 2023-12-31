/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver using polling
 *
 * Author: Esraa Fawzy
 *
 *******************************************************************************/
#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
/*******************************************************************************
 * Functions Definitions *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * ADLAR = 0 right adjusted
	 * MUX4:0 = 00000 to choose channel 0 as initialization
	 */
	ADMUX = 0;
	if (Config_Ptr->ref_volt==AREF)//REFS0 =0 ,REFS1 =0 for EXternal AREF
		ADMUX =0;
	else if (Config_Ptr->ref_volt==AVCC)//REFS0 =1 for EXternal AREF
		ADMUX |= (1<<REFS0);
	else if (Config_Ptr->ref_volt==INTERNAL)//REFS0 =1 ,REFS1 =1 for internal VREF=2.56
		ADMUX |= (1<<REFS1)|(1<<REFS0);
	/* ADCSRA Register Bits Description:
	 * ADEN = 1 Enable ADC
	 * ADIE = 0 Disable ADC Interrupt
	 * ADATE = 0 Disable Auto Trigger
	 * ADPS2:0  to choose ADC_Clock --> ADC must operate in range 50-200Khz
	 */
	ADCSRA |= (1<<ADEN);

	/* configuring prescaler*/
		if(Config_Ptr->prescaler==PRE1)
			ADCSRA|=PRE1;
		else if (Config_Ptr->prescaler==PRE2)
			ADCSRA|=PRE2;
		else if (Config_Ptr->prescaler==PRE4)
			ADCSRA|=PRE4;
		else if (Config_Ptr->prescaler==PRE8)
			ADCSRA|=PRE8;
		else if (Config_Ptr->prescaler==PRE16)
			ADCSRA|=PRE16;
		else if (Config_Ptr->prescaler==PRE32)
			ADCSRA|=PRE32;
		else if (Config_Ptr->prescaler==PRE64)
			ADCSRA|=PRE64;
		else if (Config_Ptr->prescaler==PRE128)
			ADCSRA|=PRE128;
}
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
