#define F_CPU 1000000L

#include "main.h"
#include <util/delay.h>


int main(void)
{
    PORTSETUP;
    
    // CCP = 0xD8;
    // CLKPSR = 0; 

TCCR0A = (1 << WGM01) | (1 << COM0B1); // | (1 << COM0B0);
TCCR0B = (1 << CS00) | (1 << WGM02) | (1 << WGM03);

uint_fast16_t position = 500;

int_fast8_t adder = 50;
ICR0 = 19999;
OCR0B = 1499;

	

   while(1){

    _delay_ms(1000);
    PINOFF(PORTB, PB2);
    OCR0B = position;

    _delay_ms(1000);
    PINON(PORTB, PB2);

    position = position + adder;
    if(position < 550 || position > 2050)
       adder = -1 * adder;
   }

    return 0;
}

    