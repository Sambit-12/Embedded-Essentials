/*
 */
#include <avr/io.h>
int main()
{
DDRD |=(1<<PD6); // Led Output
DDRD &=~(1<<PD4);// Input of the Heater
DDRD &=~(1<<PD0);// Input of seat Button

/* Enabling Pull ups at pin 0 and Pin 4 of Port D*/
PORTD |= (1<<PD4); //Setting up the Bit
PORTD |= (1<<PD0); //Setting up the Bit

    while(1)
        {

            if((!(PIND&(1<<PD4)))&(!(PIND&(1<<PD0))))
               {
                   PORTD |=(1<<PD6); //Turn on Led
               }
          else
          {
              PORTD &= ~(1<<PD6); //Turn of Led
          }

    }
    return 0;
}

