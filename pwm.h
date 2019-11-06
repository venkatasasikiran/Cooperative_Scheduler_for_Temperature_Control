/*
 * pwm.h
 *
 *  Created on: Mar 25, 2016
 *      Author: VEERAMACHANENI
 */

#ifndef PWM_H_
#define PWM_H_

#define TIMER_PERIOD 40 // To give frequency of 25kHz

//#define DUTY_CYCLE 30
//unsigned int duty_cycle;

void pwm_init(int);
void pwm_set(int);

#endif /* PWM_H_ */
