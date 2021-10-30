/*	Author: Andrew Shim
 *  	Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab # 8 Exercise # 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo: https://drive.google.com/file/d/1HnANIUjZj74n8mGMMPlBvCUFWebrjIkq/view?usp=sharing
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x = 0;
unsigned short max = 900;

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;  
    DDRD = 0xFF; PORTD = 0x00;
    
    ADC_init();

    /* Insert your solution below */
    while (1) {
        x = ADC;
	if(x >= max) {
	    PORTB = 0xFF;
	}
	else if(x >= max * 7 / 8) {
	    PORTB = 0x7F;
	}
	else if(x >= max * 6 / 8) {
	    PORTB = 0x3F;
	}
	else if(x >= max * 5 / 8) {
	    PORTB = 0x1F;
	}
	else if(x >= max * 4 / 8) {
	    PORTB = 0x0F;
	}
	else if(x >= max * 3 / 8) {
	    PORTB = 0x07;
	}
	else if(x >= max * 2 / 8) {
	    PORTB = 0x03;
	}
	else if(x >= max * 1 / 8) {
	    PORTB = 0x01;
	}
	else if(x >= 0) {
	    PORTB = 0x00;
	}
    }
}
