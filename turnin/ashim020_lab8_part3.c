/*	Author: Andrew Shim
 *  	Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab # 8 Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo: https://drive.google.com/file/d/1p8I9ui2NXFIra-HICJKCp4iyyGJHO99F/view?usp=sharing
 */
#include <avr/io.h>
#include "io.h"
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x = 0;
unsigned short max = 0xFF;

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
	tmpB = (char)x;
	if(tmpB >= max / 2) {
	    PORTB = 0x01;
	} else {
	    PORTB = 0x00;
	}
	//PORTD = (char)(x >> 8);
    }
}
