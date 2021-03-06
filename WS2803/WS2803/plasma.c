/*
 * plasma.c
 *
 * Created: 19.05.2013 15:25:57
 *  Author: Fumasu
 */ 

#include "plasma.h"

uint8_t plasma_palette[256 * 3] ={
	127, 0, 0,
	124, 0, 0,
	121, 0, 0,
	118, 0, 0,
	114, 0, 0,
	111, 0, 0,
	108, 1, 0,
	105, 1, 0,
	102, 2, 0,
	99, 3, 0,
	96, 3, 0,
	93, 4, 0,
	90, 5, 0,
	87, 6, 0,
	84, 7, 0,
	81, 8, 0,
	78, 9, 0,
	75, 11, 0,
	72, 12, 0,
	69, 13, 0,
	67, 15, 0,
	64, 16, 0,
	61, 18, 0,
	59, 19, 0,
	56, 21, 0,
	53, 23, 0,
	51, 25, 0,
	48, 27, 0,
	46, 29, 0,
	43, 31, 0,
	41, 33, 0,
	39, 35, 0,
	37, 37, 0,
	34, 39, 0,
	32, 42, 0,
	30, 44, 0,
	28, 46, 0,
	26, 49, 0,
	24, 51, 0,
	22, 54, 0,
	21, 57, 0,
	19, 59, 0,
	17, 62, 0,
	16, 65, 0,
	14, 67, 0,
	13, 70, 0,
	12, 73, 0,
	10, 76, 0,
	9, 79, 0,
	8, 82, 0,
	7, 85, 0,
	6, 88, 0,
	5, 91, 0,
	4, 94, 0,
	3, 97, 0,
	2, 100, 0,
	2, 103, 0,
	1, 106, 0,
	1, 109, 0,
	0, 112, 0,
	0, 115, 0,
	0, 118, 0,
	0, 122, 0,
	0, 125, 0,
	0, 128, 0,
	0, 131, 0,
	0, 134, 0,
	0, 137, 0,
	0, 140, 0,
	1, 143, 0,
	1, 147, 0,
	2, 150, 0,
	2, 153, 0,
	3, 156, 0,
	4, 159, 0,
	4, 162, 0,
	5, 165, 0,
	6, 168, 0,
	7, 171, 0,
	8, 174, 0,
	10, 177, 0,
	11, 180, 0,
	12, 182, 0,
	14, 185, 0,
	15, 188, 0,
	17, 191, 0,
	18, 193, 0,
	20, 196, 0,
	22, 199, 0,
	23, 201, 0,
	25, 204, 0,
	27, 206, 0,
	29, 209, 0,
	31, 211, 0,
	33, 213, 0,
	35, 216, 0,
	38, 218, 0,
	40, 220, 0,
	42, 222, 0,
	45, 224, 0,
	47, 226, 0,
	50, 228, 0,
	52, 230, 0,
	55, 232, 0,
	57, 234, 0,
	60, 235, 0,
	63, 237, 0,
	65, 239, 0,
	68, 240, 0,
	71, 241, 0,
	74, 243, 0,
	77, 244, 0,
	79, 245, 0,
	82, 246, 0,
	85, 248, 0,
	88, 249, 0,
	91, 249, 0,
	94, 250, 0,
	97, 251, 0,
	100, 252, 0,
	104, 252, 0,
	107, 253, 0,
	110, 253, 0,
	113, 254, 0,
	116, 254, 0,
	119, 254, 0,
	122, 254, 0,
	125, 254, 0,
	129, 254, 0,
	132, 254, 0,
	135, 254, 0,
	138, 254, 0,
	141, 254, 0,
	144, 253, 0,
	147, 253, 0,
	150, 252, 0,
	154, 252, 0,
	157, 251, 0,
	160, 250, 0,
	163, 249, 0,
	166, 249, 0,
	169, 248, 0,
	172, 246, 0,
	175, 245, 0,
	177, 244, 0,
	180, 243, 0,
	183, 241, 0,
	186, 240, 0,
	189, 239, 0,
	191, 237, 0,
	194, 235, 0,
	197, 234, 0,
	199, 232, 0,
	202, 230, 0,
	204, 228, 0,
	207, 226, 0,
	209, 224, 0,
	212, 222, 0,
	214, 220, 0,
	216, 218, 0,
	219, 216, 0,
	221, 213, 0,
	223, 211, 0,
	225, 209, 0,
	227, 206, 0,
	229, 204, 0,
	231, 201, 0,
	232, 199, 0,
	234, 196, 0,
	236, 193, 0,
	237, 191, 0,
	239, 188, 0,
	240, 185, 0,
	242, 182, 0,
	243, 180, 0,
	244, 177, 0,
	246, 174, 0,
	247, 171, 0,
	248, 168, 0,
	249, 165, 0,
	250, 162, 0,
	250, 159, 0,
	251, 156, 0,
	252, 153, 0,
	252, 150, 0,
	253, 147, 0,
	253, 143, 0,
	254, 140, 0,
	254, 137, 0,
	254, 134, 0,
	254, 131, 0,
	254, 128, 0,
	254, 125, 0,
	254, 122, 0,
	254, 118, 0,
	254, 115, 0,
	254, 112, 0,
	253, 109, 0,
	253, 106, 0,
	252, 103, 0,
	252, 100, 0,
	251, 97, 0,
	250, 94, 0,
	249, 91, 0,
	248, 88, 0,
	247, 85, 0,
	246, 82, 0,
	245, 79, 0,
	244, 76, 0,
	242, 73, 0,
	241, 70, 0,
	240, 67, 0,
	238, 65, 0,
	237, 62, 0,
	235, 59, 0,
	233, 57, 0,
	232, 54, 0,
	230, 51, 0,
	228, 49, 0,
	226, 46, 0,
	224, 44, 0,
	222, 42, 0,
	220, 39, 0,
	217, 37, 0,
	215, 35, 0,
	213, 33, 0,
	211, 31, 0,
	208, 29, 0,
	206, 27, 0,
	203, 25, 0,
	201, 23, 0,
	198, 21, 0,
	195, 19, 0,
	193, 18, 0,
	190, 16, 0,
	187, 15, 0,
	185, 13, 0,
	182, 12, 0,
	179, 11, 0,
	176, 9, 0,
	173, 8, 0,
	170, 7, 0,
	167, 6, 0,
	164, 5, 0,
	161, 4, 0,
	158, 3, 0,
	155, 3, 0,
	152, 2, 0,
	149, 1, 0,
	146, 1, 0,
	143, 0, 0,
	140, 0, 0,
	136, 0, 0,
	133, 0, 0,
	130, 0, 0,
	127, 0, 0,
};

uint8_t sinetab[] ={
	221, 213, 0,
	249, 91, 0,
	186, 240, 0,
	119, 254, 0,
	249, 91, 0,
	158, 3, 0,
	254, 137, 0,
	231, 201, 0,
	183, 241, 0,
	254, 137, 0,
	138, 254, 0,
	71, 241, 0,
	113, 254, 0,
	229, 204, 0,
	71, 241, 0,
	18, 193, 0,
	254, 140, 0,
	203, 25, 0,
	240, 185, 0,
	194, 235, 0
};
uint32_t plasma_counter =0;
float zoom =50.0f / 1.0f;

float map(float value, float au, float ao, float zu, float zo) {
	float ausgang =(abs(au) + abs(ao));
	float ziel =(abs(zu) + abs(zo));

	float faktor =ziel / ausgang;

	return (value * faktor + zu - (au * faktor));
}

void plasma_init_palette() {
	for(int i =0;i <256;i++) {
		float index =map(i, 0, 255, 0, 360);
		index =map(index, 0, 360, -1, 1);
		
		/*plasma_palette[(i * 3) + 0] =map(sin(index * M_PI), -1, 1, 0, 255);		//Rot/Gr�n
		plasma_palette[(i * 3) + 1] =map(cos(index * M_PI), -1, 1, 0, 255);
		plasma_palette[(i * 3) + 2] =0;*/

		/*plasma_palette[(i * 3) + 0] =255;											//Hitze
		plasma_palette[(i * 3) + 1] =map(cos(index * M_PI), -1, 1, 0, 255);
		plasma_palette[(i * 3) + 2] =map(sin(index * M_PI), -1, 1, 0, 255);*/

		/*plasma_palette[(i * 3) + 0] =map(sin(index * M_PI), -1, 1, 0, 255);			//Regenbogen
		plasma_palette[(i * 3) + 1] =map(sin(index * M_PI + 2.0f * M_PI / 3.0f), -1, 1, 0, 255);
		plasma_palette[(i * 3) + 2] =map(sin(index * M_PI + 4.0f * M_PI / 3.0f), -1, 1, 0, 255);*/

		/*plasma_palette[(i * 3) + 0] =map(sin(index * M_PI * 5), -1, 1, 0, 255);		//Schwarz/Wei�
		plasma_palette[(i * 3) + 1] =plasma_palette[(i * 3) + 0];
		plasma_palette[(i * 3) + 2] =plasma_palette[(i * 3) + 0];*/
	}
}

void plasma() {
	for(int x =0;x <SCREEN_WIDTH;x++) {
		for(int y =0;y <SCREEN_HEIGHT;y++) {
			float tmp;
			float grad_x, grad_y;
			float cx =(x - SCREEN_WIDTH / 2) + map(sin((plasma_counter / 10.0) / 5), -1, 1, -128, 128);
			float cy =(y - SCREEN_HEIGHT / 2) + map(cos((plasma_counter / 10.0) / 3), -1, 1, -128, 128);
			
			grad_x =x * M_PI / 180.0f;
			grad_y =y * M_PI / 180.0f;
			
			tmp =sin(zoom * grad_x * M_PI + (plasma_counter / 10.0f));
			//tmp +=sin(zoom * (grad_x * sin((plasma_counter / 10.0) / 2) + grad_y * cos((plasma_counter / 10.0) / 3)) + (plasma_counter / 10.0f));
			//tmp +=sin( sqrt(0.5f * (pow(cx, 2) + pow(cy, 2)) + 1) * M_PI / 180.0 + plasma_counter / 10.0f);
			//tmp /=3;
			//tmp =map(tmp, -3, 3, -1, 1);
			
			uint8_t r, g, b;
			
			/*r =plasma_palette[(int)map(tmp, -1, 1, 0, 255) * 3 + 0];
			g =plasma_palette[(int)map(tmp, -1, 1, 0, 255) * 3 + 1];
			b =plasma_palette[(int)map(tmp, -1, 1, 0, 255) * 3 + 2];*/
			
			r =plasma_palette[sinetab[(x * 3) + (y * SCREEN_WIDTH * 3) + 0]];
			g =plasma_palette[sinetab[(x * 3) + (y * SCREEN_WIDTH * 3) + 1]];
			b =plasma_palette[sinetab[(x * 3) + (y * SCREEN_WIDTH * 3) + 2]];
						
			screen_setPixel(x, y, r, g, b);
		}
	}
	
	plasma_counter++;
}