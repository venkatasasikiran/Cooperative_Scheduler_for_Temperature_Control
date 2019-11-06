/*
 * scheduler.h
 *
 *  Created on: Apr 9, 2016
 *      Author: VEERAMACHANENI
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

void scheduler(void);
void context_save(void);
void context_restore(void);

volatile unsigned int dummy_speed;
volatile unsigned int task;
volatile unsigned int old_duty_cycle;
volatile unsigned int new_duty_cycle;
short stack_pointer_TCB_start;
short stack_pointer_TCB_end;
short stack_pointer_func;


#endif /* SCHEDULER_H_ */
