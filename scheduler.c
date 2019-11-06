/*
 * scheduler.c
 *
 *  Created on: Apr 9, 2016
 *      Author: VEERAMACHANENI
 */

#include "headers.h"
#include "semaphores.h"



void scheduler(void)
{
	context_save();


	if(temp_sem)
	{
		task=1;
		temp_sem=0;
	}
	else if(speed_sem)
	{
		task=2;
		speed_sem=0;
	}
	else
	{
		task=3;
	}

	switch (task)
	{
		case 1: temp_value = read_adc();
				break;
		case 2:
				rpm = dummy_speed;
				rpm=rpm*120;		// rpm is for half sec. Inorder to make it for minute, we multiply with 2*60
				break;
		case 3: if(temp_value<=20)
					new_duty_cycle = 0.3*40;
				else if(temp_value>=21 && temp_value<=22)
					new_duty_cycle = 0.4*40;
				else if(temp_value>=23 && temp_value<=24)
					new_duty_cycle = 0.5*40;
				else if(temp_value>=25 && temp_value<=26)
					new_duty_cycle = 0.6*40;
				else if(temp_value>=27 && temp_value<=28)
					new_duty_cycle = 0.7*40;
				else if(temp_value>=29 && temp_value<=30)
					new_duty_cycle = 0.8*40;
				else if(temp_value>=31 && temp_value<=32)
					new_duty_cycle = 0.9*40;
				else
					new_duty_cycle = 1.0*40;

				if(new_duty_cycle != old_duty_cycle)
				{
					pwm_set(new_duty_cycle);
					old_duty_cycle = new_duty_cycle;
				}

				break;
		default:
			break;
	}

	context_restore();

}

void context_save(void)
{
	stack_pointer_func = __get_SP_register();
	_set_SP_register(stack_pointer_TCB_start);

	__asm( "			 push r4 ");
	__asm( "			 push r5 ");
	__asm( "			 push r6 ");
	__asm( "			 push r7 ");
	__asm( "			 push r8 ");
	__asm( "			 push r9 ");
	__asm( "			 push r10");
	__asm( "			 push r11");
	__asm( "			 push r12");
	__asm( "			 push r13");
	__asm( "			 push r14");
	__asm( "			 push r15");

	stack_pointer_TCB_end = __get_SP_register();
	__set_SP_register(stack_pointer_func);
}

void context_restore(void)
{

	stack_pointer_func = __get_SP_register();
	__set_SP_register(stack_pointer_TCB_end);

	__asm("				pop r15");
	__asm("				pop r14");
	__asm("				pop r13");
	__asm("				pop r12");
	__asm("				pop r11");
	__asm("				pop r10");
	__asm("				pop r9");
	__asm("				pop r8");
	__asm("				pop r7");
	__asm("				pop r6");
	__asm("				pop r5");
	__asm("				pop r4");

	__set_SP_register(stack_pointer_func);
}



#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A1_ISR(void)
{
	TA0CTL |= MC__STOP;
	TB0CTL |= MC__STOP;
	dummy_speed=TB0R;
	TB0CTL |= MC__CONTINUOUS|TBCLR;
	TA0CTL |= MC__UP;
	push =1;
}

#pragma vector = PORT1_VECTOR
__interrupt void PUSH_BUTTON_ISR(void)
{
	P1IFG &= ~BIT1;
	if(push)
	{
		P1DIR |= BIT0;
		P1OUT |= BIT0;
		while(1)
			{

				_no_operation();
			}
	}

}
