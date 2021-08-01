// Source file for Output
#include "FinalOutput.h"
// Initialization for Output
void InitUSART(int baud_rate){
    uint16_t ubrr_value;
    ubrr_value= (16000000/(16*baud_rate)-1);
    UBRR0L= ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C= (1<<UMSEL00)|(1<UCSZ01)|(1<<UCSZ00);

    UCSR0B= (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);






}

// Receiver input
char USARTReadChar(){
    while(!(UCSR0A & (1<<RXC0)))
    {

    }

    return UDR0;

}

 // transmitter  output
void USARTWriteChar(uint8_t data){
    while(!(UCSR0A & (1<<UDRE0))){

    }
    UDR0 = data;



}
