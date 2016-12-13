
#define F_CPU 8000000L
#include "main.h"
#include<avr/pgmspace.h>
#include <avr/interrupt.h>


 
ISR(TIM0_COMPA_vect)
{
}

int main(void)
{
    PORTSETUP;
    PINON(PORTB, PB2);
    
    CCP = 0xD8;
    CLKPSR = 0; 

    // set up Output Compare A
// WGM[3:0] is set to 0010
// prescaler is set to clk/8 (010)
TCCR0A = 0;
TCCR0B = (1 << 1) | (1 << WGM02);
// set Output Compare A value
OCR0A = 39;
// enable Output Compare A Match interrupt
TIMSK0 |= (1 << OCIE0A);

sei();
	
	// set pin directions
	//DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2);

 

   while(1){
    

   }

    return 0;
}

    