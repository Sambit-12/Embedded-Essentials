/*
 */
#include "Input.h"
#include "FinalOutput.h"
#define baud_rate 9600

int main(void)
{   // port declaration
    port();
    // ADC channel declaration
    InitADC();
    // PWM Channel Declaration
    PWM();
    // Initializing Serial Communication
    InitUSART(baud_rate);

    // Heater is off
    uint8_t Temperature=0;

    uint16_t ADC_value;

    // loop to execute forever
    while(1){



            //Checking if person is sitting or not
            if ((!(PIND&(1<<PIND2)))){
                // Output Showing
                PORTD |=(1<<PD5);

                //Reading ADC Value from C0 pin(Temperature Sensor)
                ADC_value = ReadADC(0);
                _delay_ms(20);
                // Checking for input from TempSensor
                if (ADC_value<=200){
                    OCR0A =60;
                    Temperature=20;

                }
                else if(ADC_value<=500){
                    OCR0A =110;
                    Temperature=25;

                }
                else if(ADC_value<=700){
                    OCR0A =190;
                    Temperature=29;

                }
                else{
                    OCR0A =250;
                    Temperature=33;

                }

                  _delay_ms(20);


            }
            // If person is not sitting then turn off the heater
            else{
                PORTD &= ~(1<<PD5);
                OCR0A =0;
            }


        // Sending Temperature data over Serial Port
        USARTWriteChar(Temperature);
        // HEX to BCD Conversion
        Temperature+= (Temperature/10)*6;
        // 7 Segment display input
        PORTB = Temperature;

        Temperature=0;
        _delay_ms(20);









    }
        return 0;
}
