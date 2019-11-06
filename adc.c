/*
 * adc.c
 *
 *  Created on: Mar 25, 2016
 *      Author: VEERAMACHANENI
 */
#include <msp430.h>
#include "adc.h"

void adc_init(void)
{
	P9SEL1 &= ~BIT1;						// setting 9.1 as ADC input
	P9SEL0 &= ~BIT1;
	P9SELC |= BIT1;

	while(REFCTL0 & REFGENBUSY);              // If ref generator busy, WAIT
	REFCTL0 |= REFVSEL_0 + REFON;             // Enable internal 1.2V reference

	ADC12CTL0 &= ~ADC12ENC;
	ADC12CTL0 |= ADC12SHT0_8|ADC12ON;
	ADC12CTL1 |= ADC12SHP;
	ADC12CTL1 |=  ADC12PDIV__1|ADC12SHS_0|ADC12DIV_4|ADC12SSEL_3;
	ADC12CTL2 |= ADC12RES__12BIT;
	ADC12MCTL0 |= ADC12VRSEL_1 + ADC12INCH_9;	// channel9 for ADC
	while(!(REFCTL0 & REFGENRDY));            // Wait for reference generator to settle
	ADC12CTL0 |= ADC12ENC;

}
unsigned int calculate_temp(volatile unsigned int raw_temp)
{
	float dummy_temp;
	dummy_temp = raw_temp;
	dummy_temp = ((long)dummy_temp*1.2*100)/4096;
	return dummy_temp;
}

unsigned int read_adc(void)
{
	unsigned int dummy_read;
	ADC12CTL0 |= ADC12SC;
	while(ADC12BUSY & ADC12CTL1);
	//return ADC12MEM0;
	dummy_read = calculate_temp(ADC12MEM0);
	return dummy_read;
}


