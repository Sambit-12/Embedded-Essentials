// Source file for input
#include "Input.h"
// Initializing PWM on D6 Pin
void PWM(){

    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B|= (1<<CS01)|(1<<CS00); //63 prescalar
    //TCCR0B|= (1<<CS01); //8 prescalar
    DDRD|=(1<<PD6);

}

// Declaration of pin for input and output
void port(){
DDRB |=0b11111111; // for BCD to 7 segment converter
DDRD |=(1<<PD5);  // Output
DDRD &= ~(1<<PD2); // Button Sensor
PORTD |= (1<<PD2); // set bit


}

// Declaration for ADC Converter
void InitADC(){
ADMUX = (1<<REFS0);
//ADMUX = 0x40;
ADCSRA = (1<<ADEN)|(7<<ADPS0);
}

// Program to read ADC Value
uint16_t ReadADC(uint8_t ch){
ADMUX&= 0xf8;
ch= ch&0b00000111;
ADMUX|=ch;
ADCSRA|=(1<<ADSC);

while(!(ADCSRA & (1<<ADIF)));
ADCSRA|=(1<<ADIF);
return(ADC);



}
