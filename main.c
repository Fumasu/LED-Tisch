/*
 * main.c
 *
 * Created: 05.05.2013 16:41:27
 *  Author: Christoph
 */ 

#define F_CPU 8000000UL

#include "ws2803.h"
#include "screen.h"
#include "lauflicht.h"

void draw() {
	lauflicht();
}

int main(void) {
	uint8_t taste =0;
	int16_t color =255;
	ws2803_init();
	
	DDRD =0;
	PORTD =(1<<7);
	
	while(1) {
		draw();
		
		if((~PIND & (1<<7))) {		//taste gedrückt ?
			if(taste ==0) {
				if(color <=0) {
					color =255;
					taste =1;
				}
			}
		}
		else {						//taste losgelassen
			taste =0;
		}
		
		if(color >0) {
			for(uint8_t y =1;y <=2;y++) {
				for(uint8_t x =1;x <=2;x++) {
					screen_setPixel(x, y, color, color, color);
				}
			}
			color -=10;
		}
		else color =0;
		
		screen_show();
		
		_delay_ms(30);
	}
	
	return 0;
}