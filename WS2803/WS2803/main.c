/*
 * main.c
 *
 * Created: 05.05.2013 16:41:27
 *  Author: Christoph
 */ 

#define F_CPU 8000000UL

#include "ws2803.h"
#include "screen.h"
#include "fade.h"
#include "lauflicht.h"
#include "plasma.h"

uint8_t pos_x =0, pos_y =0;

uint8_t colors[4 * 3] ={
	255, 0, 0,
	0, 255, 0,
	0, 0, 255,
	255, 255, 255	
};

void draw() {
	//fade();
	//lauflicht();
	//plasma();
	int index =rand()%4;
	for(int x =0;x <SCREEN_WIDTH;x++) {
		for(int y =0;y <SCREEN_HEIGHT;y++) {
			screen_setPixel(x, y, 0, 0, 0);
		}
	}
	
	screen_setPixel(pos_x, pos_y, 255, 255, 255);
}

int main(void) {
	uint8_t taste =0;
	uint8_t war_taste =0;
	int16_t color =255;
	ws2803_init();
	
	DDRB &=~(1<<2);
	PORTB |=(1<<2);
	
	//plasma_init_palette();
	
	while(1) {
		draw();
		
		if((~PINB & (1<<2))) {		//taste gedrückt ?
			if(taste ==0) {
				/*if(color <=0) {
					color =255;
					taste =1;
				}*/
				taste =1;
			}
		}
		else {						//taste losgelassen
			taste =0;
			war_taste =0;
		}
		
		if(taste && !war_taste) {
			pos_x++;
			if(pos_x ==SCREEN_WIDTH) {
				pos_x =0;
				pos_y++;
			}				
			if(pos_y ==SCREEN_HEIGHT) pos_y =0;
			war_taste =1;
		}		
		
		/*if(color >0) {
			screen_setPixel(4, 0, color, color, color);
			color -=10;
		}
		else color =0;*/
		
		screen_show();
		
		_delay_ms(30);
	}
	
	return 0;
}