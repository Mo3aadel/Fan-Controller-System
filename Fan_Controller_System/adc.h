 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Adel
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

#define ADC_MAX_VALUE        1023
#define VREF_value           5


extern float ADC_VREF_VALUE;

typedef enum
{
	AREF,AVCC,Reserved,Internal_VREF

}ADC_ReferenceVolatge;

typedef enum
{
	FCPU_2=1 ,FCPU_4 ,FCPU_8 ,FCPU_16 ,FCPU_32 ,FCPU_64 ,FCPU_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
    ADC_Prescaler prescaler;

}ADC_ConfigType;


void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
