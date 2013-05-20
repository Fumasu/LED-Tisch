/*
 * ws2803.c
 *
 * Created: 05.05.2013 16:46:25
 *  Author: Christoph
 */ 

#include "ws2803.h"

void ws2803_setPixel(uint8_t r, uint8_t g, uint8_t b) {
	uint8_t color;
	
	color =r;
		for(int8_t digit =7;digit >=0;digit--) {
			WS2803_PORT &=~(1<<CKI_PIN);
			if(color & (1<<digit))
			WS2803_PORT |=(1<<SDI_PIN);
			else
			WS2803_PORT &=~(1<<SDI_PIN);
		
			WS2803_PORT |=(1<<CKI_PIN);
		}
		
	color =g;
		for(int8_t digit =7;digit >=0;digit--) {
			WS2803_PORT &=~(1<<CKI_PIN);
			if(color & (1<<digit))
			WS2803_PORT |=(1<<SDI_PIN);
			else
			WS2803_PORT &=~(1<<SDI_PIN);
			
			WS2803_PORT |=(1<<CKI_PIN);
		}
		
	color =b;
		for(int8_t digit =7;digit >=0;digit--) {
			WS2803_PORT &=~(1<<CKI_PIN);
			if(color & (1<<digit))
			WS2803_PORT |=(1<<SDI_PIN);
			else
			WS2803_PORT &=~(1<<SDI_PIN);
			
			WS2803_PORT |=(1<<CKI_PIN);
		}
}

void ws2803_show() {
	WS2803_PORT |=(1<<CKI_PIN);
	WS2803_PORT &=~(1<<CKI_PIN);
	_delay_us(500);
}

void ws2803_init() {
	WS2803_DDR |=(1<<CKI_PIN) | (1<<SDI_PIN);
	
	ws2803_show();
}