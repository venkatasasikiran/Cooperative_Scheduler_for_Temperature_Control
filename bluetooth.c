/*
 * bluetooth.c
 *
 *  Created on: Mar 25, 2016
 *      Author: VEERAMACHANENI
 */
#include <msp430.h>
#include "bluetooth.h"
#include "semaphores.h"

void uart_init(void)
{
		P4SEL1 &= ~BIT2|~BIT3;
	    P4SEL0 |= BIT2+BIT3;

	    UCA0CTLW0 |= UCSWRST;                      // Put eUSCI in reset
	    UCA0CTLW0 |= UCSSEL__SMCLK;               // CLK = SMCLK
	    UCA0BR0 = 6;                              // 1MHz 9600 (see User's Guide)
	    UCA0BR1 = 0;                              // 1MHz 9600
	    UCA0MCTLW = UCBRS0 + UCBRF_13 + UCOS16;   // Modln UCBRSx=0, UCBRFx=0,// over sampling
	    UCA0CTLW0 &= ~UCSWRST;					// RELEASE E_USIC FOR OPERATION

}

void transmit_digit(volatile unsigned char digit)
{
	while (!(UCTXIFG & UCA0IFG));
	UCA0TXBUF = digit;
}

void transmit_char(const char *str1)
{
    if(*str1 =='T')
    {
    	temp_sem=1;
    }
    else if(*str1 == 'S')
	{
    	speed_sem=1;
	}
	while (*str1 !=0 )
    {
        while (!(UCTXIFG & UCA0IFG));
         UCA0TXBUF = *str1++;
    }

}

void transmit_value(unsigned int value)
{
	unsigned int d0,d1,d2,d3;
	d3=value%10;
	d3=d3+48;
	value=value/10;
	d2=value%10;
	d2=d2+48;
	value=value/10;
	d1=value%10;
	d1=d1+48;
	d0=value/10;
	d0=d0+48;

	transmit_digit(d0);
	transmit_digit(d1);
	transmit_digit(d2);
	transmit_digit(d3);

}


void transmit_space(void)
{
	while (!(UCTXIFG & UCA0IFG));
	UCA0TXBUF = 9;
	while (!(UCTXIFG & UCA0IFG));
	UCA0TXBUF = 10;
}
