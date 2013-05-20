/*
 * lauflicht.c
 *
 * Created: 08.05.2013 23:56:47
 *  Author: Christoph
 */ 

#include "lauflicht.h"

int8_t lauflicht_position =0;
int8_t lauflicht_direction =1;
int8_t lauflicht_color[3] ={255, 0, 128};

/*
	
*/
/*void lauflicht_rechts_links() {
	for(uint8_t y =0;y <SCREEN_HEIGHT;y++) {
		for(uint8_t x =0;x <SCREEN_WIDTH;x++) {
			screen_setPixel(x, y, 0, 0, 0);
			if(lauflicht_position ==x + (y * SCREEN_WIDTH)) screen_setPixel(x, y, lauflicht_color[0], lauflicht_color[1], lauflicht_color[2]);
			if(lauflicht_direction ==1) {
				if(lauflicht_position ==x + (y * SCREEN_WIDTH) - 1) screen_setPixel(x, y, lauflicht_color[0] * 0.66f, lauflicht_color[1] * 0.66f, lauflicht_color[2] * 0.66f);
				if(lauflicht_position ==x + (y * SCREEN_WIDTH) - 2) screen_setPixel(x, y, lauflicht_color[0] * 0.33f, lauflicht_color[1] * 0.33f, lauflicht_color[2] * 0.33f);
			}
			else if(lauflicht_direction ==-1) {
				if(lauflicht_position ==x + (y * SCREEN_WIDTH) - 1) screen_setPixel(x, y, lauflicht_color[0] * 0.66f, lauflicht_color[1] * 0.66f, lauflicht_color[2] * 0.66f);
				if(lauflicht_position ==x + (y * SCREEN_WIDTH) - 2) screen_setPixel(x, y, lauflicht_color[0] * 0.33f, lauflicht_color[1] * 0.33f, lauflicht_color[2] * 0.33f);				
			}
		}
	}
	
	if(lauflicht_direction ==1) lauflicht_position++;
	else if(lauflicht_direction ==-1) lauflicht_position--;
	
	if(lauflicht_position ==-2) {
		lauflicht_direction =1;
		lauflicht_position =0;
	}
	else if(lauflicht_position ==SCREEN_WIDTH * SCREEN_HEIGHT + 2) {
		lauflicht_direction =-1;
		lauflicht_position =SCREEN_WIDTH * SCREEN_HEIGHT;
		
		lauflicht_color[0] =rand()%256;
		lauflicht_color[1] =rand()%256;
		lauflicht_color[2] =rand()%256;
	}
}*/

void lauflicht() {
	for(uint8_t y =0;y <SCREEN_HEIGHT;y++) {
		for(uint8_t x =0;x <SCREEN_WIDTH;x++) {
			screen_setPixel(x, y, 0, 0, 0);
			if(lauflicht_position ==x + (y * SCREEN_WIDTH)) screen_setPixel(x, y, lauflicht_color[0], lauflicht_color[1], lauflicht_color[2]);
			if(lauflicht_direction ==1) {
				if(lauflicht_position ==(x - 1) + (y * SCREEN_WIDTH)) screen_setPixel(x, y, lauflicht_color[0] * 0.66f, lauflicht_color[1] * 0.66f, lauflicht_color[2] * 0.66f);
				if(lauflicht_position ==(x - 2) + (y * SCREEN_WIDTH)) screen_setPixel(x, y, lauflicht_color[0] * 0.33f, lauflicht_color[1] * 0.33f, lauflicht_color[2] * 0.33f);
			}
			else if(lauflicht_direction ==-1) {
				if(lauflicht_position ==(x + 1) + (y * SCREEN_WIDTH)) screen_setPixel(x, y, lauflicht_color[0] * 0.66f, lauflicht_color[1] * 0.66f, lauflicht_color[2] * 0.66f);
				if(lauflicht_position ==(x + 2) + (y * SCREEN_WIDTH)) screen_setPixel(x, y, lauflicht_color[0] * 0.33f, lauflicht_color[1] * 0.33f, lauflicht_color[2] * 0.33f);
			}
		}
	}
	
	if(lauflicht_direction ==1) lauflicht_position++;
	else if(lauflicht_direction ==-1) lauflicht_position--;
	
	if(lauflicht_position ==-2) {
		lauflicht_direction =1;
		lauflicht_position =0;
	}
	else if(lauflicht_position ==SCREEN_WIDTH * SCREEN_HEIGHT + 2) {
		lauflicht_direction =-1;
		lauflicht_position =SCREEN_WIDTH * SCREEN_HEIGHT;
		
		lauflicht_color[0] =rand()%256;
		lauflicht_color[1] =rand()%256;
		lauflicht_color[2] =rand()%256;
	}
}