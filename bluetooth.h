/*
 * bluetooth.h
 *
 *  Created on: Mar 25, 2016
 *      Author: VEERAMACHANENI
 */

#ifndef BLUETOOTH_CONTROL_BLUETOOTH_H_
#define BLUETOOTH_CONTROL_BLUETOOTH_H_



void uart_init(void);
void transmit_digit(volatile unsigned char digit);
void transmit_char(const char *str1);
void transmit_value(unsigned int value);
void transmit_space(void);

#endif /* BLUETOOTH_CONTROL_BLUETOOTH_H_ */
