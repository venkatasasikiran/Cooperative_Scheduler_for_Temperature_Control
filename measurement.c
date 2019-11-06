/*
 * measurement.c
 *
 *  Created on: Apr 2, 2016
 *      Author: VEERAMACHANENI
 */
#include "msp430.h"
#include "measurement.h"

void measurement_init(void)
{
	P2DIR &= ~BIT0;
	P2SEL1 &= ~BIT0;
	P2SEL0 &= ~BIT0;
	P2SELC |= BIT0;

	TB0CTL |= TBSSEL_0|ID_1|MC__CONTINUOUS|TBCLR;

}

void timer_interrupt_init(void)
{
	TA0CCR0 = 270; //296
	TA0CTL |= TASSEL__ACLK|MC__UP|ID_3;
	TA0CCTL0 = CCIE;
	TA0EX0 |= TAIDEX_7;

}

