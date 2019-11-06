/*
 * pwm.c
 *
 *  Created on: Mar 25, 2016
 *      Author: VEERAMACHANENI
 */
#include <msp430.h>
#include "pwm.h"


void pwm_init(int duty_cycle)
{
	P3DIR  |= BIT3;
	P3SEL1 |= BIT3;
	P3SEL0 |= ~BIT3;

	TA1CCR0 = TIMER_PERIOD;
	TA1CCR1 = duty_cycle;


	TA1CTL |= TASSEL__SMCLK |ID_0 |MC_1|TACLR; 	// SMCLK, NO DIVISION, UPMODE, RESET TAR
	TA1CCTL1 |= OUTMOD_7;						// OUT_MODE= RESET/SET
	TA1EX0 |= TAIDEX_0; 						// NO FURTHER DIVISION
}

void pwm_set(int new_duty_cycle)
{
	TA1CTL |= MC__STOP|TACLR;
	TA1CCR1 = new_duty_cycle;
	TA1CTL |= MC_1;
}

