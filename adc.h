/*
 * adc.h
 *
 *  Created on: Mar 25, 2016
 *      Author: VEERAMACHANENI
 */

#ifndef ADC_H_
#define ADC_H_

void adc_init(void);
unsigned int read_adc();
unsigned int calculate_temp(volatile unsigned int raw_temp);



#endif /* ADC_H_ */
