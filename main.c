
#define F_CPU 1000000L
#include <util/delay.h>
#include "main.h"

int z=50;
int z1 = 950;
int z3 = 0;
int i = 0;
int j =0;
int main(void)
{
    PORTSETUP;
    PINON(PORTB, PB2);
    
   while(1){
        z1 = 1000 - z;
       PINON(PORTB, PB2);
       for(i =0 ; i< z1; i++)
       _delay_us(1);

      //
       PINOFF(PORTB, PB2);
       for(j=0; j< z; j++)       
        _delay_us(1);

     if(z3 < 500)
     {
         z3++;
     }
     else{
        z3 = 0;
     if(z <950)
       z = z + 10;
     else
       z = 50;
     }
   }

    return 0;
}

    