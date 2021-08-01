#include "Project.h"
void port()
{

DDRD |=(1<<PD6); // Led Output
DDRD &=~(1<<PD4);// Input of the Heater
DDRD &=~(1<<PD0);// Input of seat Button

/* Enabling Pull ups at pin 0 and Pin 4 of Port D*/
PORTD |= (1<<PD4); //Setting up the Bit
PORTD |= (1<<PD0); //Setting up the Bit
}
