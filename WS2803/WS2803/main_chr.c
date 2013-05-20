/*
 * main.c
 *
 * Created: 05.05.2013 16:41:27
 *  Author: Christoph
 */ 

#define F_CPU 8000000UL

#include "ws2803.h"
#include "screen.h"

/*int8_t position;
int8_t direction;
int8_t color;

void lauflicht() {
	for(int8_t i =0;i <6;i++) {
		data[(i * 3) + 0] =0;
		data[(i * 3) + 1] =0;
		data[(i * 3) + 2] =0;
		
		if(i ==position) {
			data[(i * 3) + 0] =color_data[0];
			data[(i * 3) + 1] =color_data[1];
			data[(i * 3) + 2] =color_data[2];
		}
		else if(i ==(position - (1 * direction))) {
			data[(i * 3) + 0] =color_data[0] * 0.7;
			data[(i * 3) + 1] =color_data[1] * 0.7;
			data[(i * 3) + 2] =color_data[2] * 0.7;
		}
		else if(i ==(position - (2 * direction))) {
			data[(i * 3) + 0] =color_data[0] * 0.4;
			data[(i * 3) + 1] =color_data[1] * 0.4;
			data[(i * 3) + 2] =color_data[2] * 0.4;
		}
	}
	
	position +=(1 * direction);
	
	if(position ==-2) {
		direction =1;
		position =0;
		color_data[0] =1 + rand()%254;
		color_data[1] =1 + rand()%254;
		color_data[2] =1 + rand()%254;
	}
	else if(position ==8) {
		direction =-1;
		position =5;
		color_data[0] =1 + rand()%254;
		color_data[1] =1 + rand()%254;
		color_data[2] =1 + rand()%254;
	}
}*/

int main(void) {
	uint8_t color1, color2, color3;
	
	ws2803_init();
	
	while(1) {
		for(uint8_t y =0;y <SCREEN_HEIGHT;y++) {
			for(uint8_t x =0;x <SCREEN_WIDTH;x++) {
				screen_setPixel(x, y, color1, color2, color3);
			}				
		}
		color1 = 1 + rand()%254;
		color2 = 1 + rand()%254;
		color3 = 1 + rand()%254;
		 
		screen_show();
		
		_delay_ms(5);
	}
	
	return 0;
}