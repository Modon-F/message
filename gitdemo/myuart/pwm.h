#ifndef __PWM_H__
#define __PWM_H__

#define PWM_GARBAGE 5
//#define PWM_RECOVERABLE_GARBAGE 5

void pwm_wirte(int pwm_pin);
void pwm_stop(int pwm_pin);

#endif
