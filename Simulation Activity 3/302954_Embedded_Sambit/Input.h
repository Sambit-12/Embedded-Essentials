#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
void port();
void InitADC();
uint16_t ReadADC(uint8_t ch);
void PWM();


#endif // INPUT_H_INCLUDED
