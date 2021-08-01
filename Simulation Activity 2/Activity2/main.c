/*
 */
#include "Activity.h"
unsigned volatile FLAG1= 0;
//unsigned volatile FLAG2= 0;
//unsigned volatile overflow;
int main(void)
{   //pwm generation
    port();
    InitADC();
    PWM();
    uint16_t ADC_value;
    while(1){

            //ADC input
        if((!(PIND&(1<<PIND2)))){
                PORTB |=(1<<PB7);


                ADC_value = ReadADC(0); //ADC from C0
                _delay_ms(20);
                if (ADC_value<=200){
                    OCR0A =60;

                }
                else if(ADC_value<=500){
                    OCR0A =110;

                }
                else if(ADC_value<=700){
                    OCR0A =180;

                }
                else{
                    OCR0A =250;

                }
                  FLAG1=0;
                  _delay_ms(20);

        }

        else{
            PORTB &= ~(1<<PB7);
            OCR0A =0;
        }


    _delay_ms(20);



    }
        return 0;
}





    /*
    DDRD|=(1<<PD6);
    TCCR0B|=(1<<CS02);

    TIMSK0|=(1<<TOIE0);
      TCNT0=0;
      overflow=0;
    sei();
    while(1){
            if(overflow>=247){
               if(TCNT0>=52){
                PORTD^=(1<<PD6);
                TCNT0=0;
                overflow=0;
            }
            }


    }
    return 0;
}
ISR(TIMER0_OVF_vect){
    overflow++;
    */














    /*
port();



    // Insert code

    while(1){

            if (FLAG1==1){
                  PORTB |=(1<<PB0);
                  _delay_ms(2000);
                  PORTB &= ~(1<<PB0);
                  FLAG1=0;


            }

            if (FLAG2==1){
                  PORTB |=(1<<PB1);
                  _delay_ms(2000);
                  PORTB &= ~(1<<PB1);
                  FLAG2=0;


            }



    }


    return 0;
}
ISR(INT0_vect)
{
    FLAG1 =1;

}
ISR(INT1_vect)
{
    FLAG2 =1;
*/


