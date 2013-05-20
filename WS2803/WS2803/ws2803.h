/*
 * ws2803.h
 *
 * Created: 05.05.2013 16:43:02
 *  Author: Christoph
 */ 


#ifndef WS2803_H_
#define WS2803_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "config.h"

#define WS2803_DDR DDRB
#define WS2803_PORT PORTB

#define CKI_PIN PB0
#define SDI_PIN PB1

/*
	Setzt die Fareb für ein Pixel
*/
void ws2803_setPixel(uint8_t r, uint8_t g, uint8_t b);

/*
	Latcht das IC um die Pixel anzuzeigen
*/
void ws2803_show();

/*
	Initialisiert das IC
*/
void ws2803_init();



#endif /* WS2803_H_ */