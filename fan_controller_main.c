#include "headers.h"
#include "char_variables.h"
#include "semaphores.h"
/*
 * main.c
 */

void main(void)
{
    WDTCTL = WDTPW | WDTSSEL__ACLK |WDTCNTCL|WDTIS_4 ;	// Configure watchdog for 1sec

    temp_sem = 0;
    speed_sem= 0;
    old_duty_cycle = 0.3*40;
    temp_value = 0;
    rpm = 0;
    push =0;
    stack_pointer_TCB_start = 0x00239C;

    uart_init();							//UART initialisation
    adc_init();								//ADC initialisation
    pwm_init(old_duty_cycle);				//initially set to 30% of pwm nearly 660RPM
    measurement_init();						// To count the pulses from the fan
    timer_interrupt_init();					// Interrupt for every 0.5sec
    push_button_init();						// Initialization of push button for vector

    PM5CTL0 &= ~LOCKLPM5;

    __bis_SR_register(GIE);					// enable interrupt

       while(1)
       {

    	WDTCTL = WDTPW | WDTSSEL__ACLK |WDTCNTCL|WDTIS_4 ;	// Configure watchdog for 1sec
       	transmit_char(temp);
       	scheduler();
        transmit_value(temp_value);
        transmit_space();
       	transmit_char(speed);
       	scheduler();
       	transmit_value(rpm);
       	scheduler();
       	transmit_space();
       	}
	}
