/*
 */
#include "Project.h"
int main(void)
{
  port();

    while(1)
        {

            if((!(PIND&(1<<PD4)))&(!(PIND&(1<<PD0))))
               {
                   PORTD |=(1<<PD6); //Turn on Led
                   _delay_ms(20);
               }
          else
          {
              PORTD &= ~(1<<PD6); //Turn of Led
              _delay_ms(20);
          }

    }
    return 0;
}
