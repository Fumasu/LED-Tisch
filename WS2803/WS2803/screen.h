/*
 * screen.h
 *
 * Created: 05.05.2013 16:57:37
 *  Author: Christoph
 */


#ifndef SCREEN_H_
#define SCREEN_H_

#include "config.h"
#include "ws2803.h"

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
} _pixel;

void screen_show();

void screen_setPixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);

#endif /* SCREEN_H_ */