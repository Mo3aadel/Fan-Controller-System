 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Adel
 *
 *******************************************************************************/

#include<avr/io.h>
#include"adc.h"
#include"common_macros.h"


float ADC_VREF_VALUE ;

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
    /*
	 *  getting the selected voltage reference value for the
	 *  temperature calculation in temperature sensor driver
	 */
	if(Config_Ptr->ref_volt == AREF)
	{
		ADC_VREF_VALUE = VREF_value;
	}
	else if(Config_Ptr->ref_volt == AVCC)
	{
		ADC_VREF_VALUE = 5;
	}
	else if(Config_Ptr->ref_volt == Internal_VREF)
	{
		ADC_VREF_VALUE = 2.56;
	}

	ADMUX = (ADMUX&0x3F) | (Config_Ptr->ref_volt)<<6 ;

	ADCSRA = (1<<ADEN)|(Config_Ptr->prescaler) ;


}

uint16 ADC_readChannel(uint8 channel_num)
{

	channel_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */

}
