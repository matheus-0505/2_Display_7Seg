#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

// Entradas
// Botão para pedestres - PB0

// Saídas
// VeicVerde - PB1, VeicAmarelo - PB2, VeicVermelho - PB3 
// PedVerd - PB4, PedVermelho - PB5


int main(void){  
    // PINOUT
    unsigned long counter = 0;

    DDRB &= ~(1<<0);
    PORTB |= (1<<0);

    DDRB |= (1<<1);
    DDRB |= (1<<2);
    DDRB |= (1<<3);
    DDRB |= (1<<4);
    DDRB |= (1<<5);

    while (1){
        _delay_ms(1);
        counter++;

        if((!(PINB & (1<<PINB0))) && (counter<=32000)){
            counter = 32000;
        }

        if(counter<=42000){
            PORTB &= ~(1<<2);
            PORTB &= ~(1<<3);
            PORTB |= (1<<1);
            PORTB &= ~(1<<4);
            PORTB |= (1<<5);
        }else if(counter<=45000){
            PORTB &= ~(1<<1);
            PORTB &= ~(1<<3);
            PORTB |= (1<<2);
        }else if(counter<=57000){
            PORTB &= ~(1<<1);
            PORTB &= ~(1<<2);
            PORTB |= (1<<3);
            PORTB &= ~(1<<5);
            PORTB |= (1<<4);
        }else if(counter<=60000){
            PORTB &= ~(1<<4);
            PORTB |= (1<<5);
            _delay_ms(500);
            PORTB &= ~(1<<5);
            _delay_ms(500);
            PORTB |= (1<<5);
            _delay_ms(500);
            PORTB &= ~(1<<5);
            _delay_ms(500);
            PORTB |= (1<<5);
            _delay_ms(500);
            PORTB &= ~(1<<5);
            _delay_ms(500);
            counter =0;        
        }

    }
}


