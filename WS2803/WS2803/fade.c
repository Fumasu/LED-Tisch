/*
 * fade.c
 *
 * Created: 08.05.2013 23:50:33
 *  Author: Christoph
 */ 

#include "fade.h"

uint8_t color[3] ={255, 0, 128};
int8_t prozent =0;
uint8_t heller =1;

void fade() {
	for(uint8_t y =0;y <SCREEN_HEIGHT;y++) {
		for(uint8_t x =0;x <SCREEN_WIDTH;x++) {
			if(prozent <0) {
				screen_setPixel(x, y, 0, 0, 0);
			}
			else {
				if(prozent >100)
					screen_setPixel(x, y, color[0], color[1], color[2]);
				else
					screen_setPixel(x, y, color[0] * ((float)prozent / 100.0f), color[1] * ((float)prozent / 100.0f), color[2]  * ((float)prozent / 100.0f));
			}
		}
	}
	
	if(prozent >100) {
		heller =0;
		prozent =100;
		
		/*color[0] =rand()%256;
		color[1] =rand()%256;
		color[2] =rand()%256;*/
	}
	else if(prozent <0) {
		heller =1;
		prozent =0;
		
		color[0] =rand()%256;
		color[1] =rand()%256;
		color[2] =rand()%256;
	}
	if(heller ==1) prozent++;
	else if(heller ==0) prozent--;
}