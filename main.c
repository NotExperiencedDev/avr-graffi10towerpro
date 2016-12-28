#define F_CPU 1000000L

#include "main.h"
#include <util/delay.h>


int main(void)
{
    PORTSETUP;
 
    // setup timer to Fast PWM, with ICR0 as TOP
    // OCR0B as compare value
    // Non Inverted output on PB1 (OC0B)
    // prescaler set to 1 (CS0[2:0])
    TCCR0A = (1 << WGM01) | (1 << COM0B1); 
    TCCR0B = (1 << CS00) | (1 << WGM02) | (1 << WGM03);

    uint_fast16_t position = 500;
    int_fast8_t adder = 50;

    // TOP - mcu runs on 1MHz, so PWM will be 50Hz (20ms)
    ICR0 = 19999; 

    // initial compare value - servo needs pulse between
    // 0.5ms and 2.1ms (0 - 180 degrees)
    OCR0B = position;

   while(1){
       // create delay and blink a led, to indicate that mcu is running
        _delay_ms(1000);
        PINOFF(PORTB, PB2);        
        _delay_ms(1000);
        PINON(PORTB, PB2);

        // update position and OCR0B
        position = position + adder;
        OCR0B = position;

        // increasing/decreasing position in each loop
        // within range 500 (0.5ms) - 2100 (2.1ms) pulse width
        // period all the time is 20ms (50 Hz)
        if(position < 550 || position > 2050)
            adder = -1 * adder;
   }

    return 0;
}

    