#define F_CPU   16000000
#include <util/delay.h>
#include <avr/io.h>

int main(void) 
{
	DDRB  |=  (1<<5);
	PORTB &= ~(1<<5);
	
    while (1) 
    {
		PORTB |=  (1<<5);
		_delay_ms(2000);

		PORTB &= ~(1<<5);
		_delay_ms(2000);

    }
}
