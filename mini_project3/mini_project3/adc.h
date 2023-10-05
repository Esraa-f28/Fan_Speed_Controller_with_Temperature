/******************************************************************************
*
* Module: ADC
*
* File Name: adc.h
*
* Description: header file for the ATmega16 ADC driver
*
*
*******************************************************************************/
#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
/*******************************************************************************
* Definitions *
*******************************************************************************/
#define ADC_MAXIMUM_VALUE 1023
#define ADC_REF_VOLT_VALUE 5
/*******************************************************
* Configrations for ADC using enums and struct
*******************************************************/
typedef enum {
AVCC,AREF,INTERNAL
}ADC_ReferenceVolatge;
typedef enum
{
	PRE1,PRE2,PRE4,PRE8,PRE16,PRE32,PRE64,PRE128
}ADC_Prescaler;
typedef struct{
ADC_ReferenceVolatge ref_volt;
ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
* Functions Prototypes *
*******************************************************************************/
/*
* Description :
* Function responsible for initialize the ADC driver.
*/
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
* Description :
* Function responsible for read analog data from a certain ADC channel
* and convert it to digital using the ADC driver.
*/
uint16 ADC_readChannel(uint8 channel_num);
#endif /* ADC_H_ */
