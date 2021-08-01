#include "Activity.h"
void PWM(){

    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B|= (1<<CS01)|(1<<CS00); //64 prescalar
    //TCCR0B|= (1<<CS01); //8 prescalar
    DDRD|=(1<<PD6);

}
void port(){
DDRB |=(1<<PB7); // for led
//DDRB |=(1<<PB1); // for led
DDRD &= ~(1<<PD2); // clear bit
PORTD |= (1<<PD2); // set bit
//DDRD &= ~(1<<PD3); // clear bit
//PORTD |= (1<<PD3); // set bit
//EICRA = 0x0;
//EICRA &= ~(1<<ISC00);
//EICRA &= ~(1<<ISC01);
//EICRA|=(1<<ISC00)|(1<<ISC01);
//EIMSK |= (1<<INT0)|(1<<INT1);;
//sei();

}
void InitADC(){
ADMUX = (1<<REFS0);
//ADMUX = 0x40;
ADCSRA = (1<<ADEN)|(7<<ADPS0);
}

uint16_t ReadADC(uint8_t ch){
ADMUX&= 0xf8;
ch= ch&0b00000111;
ADMUX|=ch;
ADCSRA|=(1<<ADSC);

while(!(ADCSRA & (1<<ADIF)));
ADCSRA|=(1<<ADIF);
return(ADC);



}
