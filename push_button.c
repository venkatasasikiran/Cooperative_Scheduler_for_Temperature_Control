/*
 * push_button.c
 *
 *  Created on: Apr 18, 2016
 *      Author: VEERAMACHANENI
 */
#include <msp430.h>
#include "push_button.h"

void push_button_init(void)
{
	//Set push button on P1.1 to give interrupt on push

	P1DIR &= ~BIT1;
	P1REN |= BIT1;                            // Enable P1.1 internal resistance
	P1OUT |= BIT1;                            // Set P1.1 as pull-Up resistance
	P1IES |= BIT1;                            // P1.1 Hi/Lo edge
	P1IFG = 0;                           	// P1.1 IFG cleared
	P1IE |= BIT1;                             // P1.1 interrupt enabled
}



