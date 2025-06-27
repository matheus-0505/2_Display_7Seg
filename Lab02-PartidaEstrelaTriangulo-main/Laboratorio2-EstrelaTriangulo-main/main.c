/*
PB1 - ENTRADA - PULL UP - S0
PB2 - ENTRADA - PULL UP - S1

PB3 - SAÍDA - K1
PB4 - SAÍDA - K2
PB5 - SAÍDA - K3
*/
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

void main(void){
    //Config. p/ entrada
    DDRB&= ~(1<<1);
    DDRB&= ~(1<<2);

    //outra forma
    //DDRB&= ~((1<<1)|(1<<2))

    //Pull up
    PORTB|= (1<<1);
    PORTB|= (1<<2);

    //Config. p/ saída
    DDRB|=(1<<3);
    DDRB|=(1<<4);
    DDRB|=(1<<5);

    //Desliga contatoras
    PORTB&= ~(1<<3);
    PORTB&= ~(1<<4);
    PORTB&= ~(1<<5);


    while (1){
        if(!(PINB & (1<<PINB2))){
            PORTB|= (1<<3);
            PORTB|= (1<<4);
            _delay_ms(5000);
            PORTB|= (1<<5);
            PORTB&= ~(1<<4);
        }else if(!(PINB & (1<<PINB1))){
            PORTB&= ~(1<<3);
            PORTB&= ~(1<<4);
            PORTB&= ~(1<<5);
        }
    }
    

}
