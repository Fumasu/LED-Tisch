#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include <Fumasu/tga.h>

#define WIDTH 4
#define HEIGHT 4

using namespace std;

vector<uint8_t> sintable(WIDTH * HEIGHT * 3);
vector<uint8_t> data(WIDTH * HEIGHT * 3);
vector<uint8_t> data_2(256 * 256 * 3);
vector<uint8_t> palette(256 * 3);

float map(float value, float au, float ao, float zu, float zo) {
	float ausgang =(abs(au) + abs(ao));
	float ziel =(abs(zu) + abs(zo));

	float faktor =ziel / ausgang;

	return value * faktor + zu - (au * faktor);
}

int main(int argc, char *argv[]) {
	uint16_t counter =0;

	for(int i =0;i <256;i++) {
		float index =map(i, 0, 255, 0, 360);
		index =map(index, 0, 360, -1, 1);
		/*palette[(i * 3) + 0] =map(sin(index * M_PI), -1, 1, 0, 255);		//Rot/Grün
		palette[(i * 3) + 1] =map(cos(index * M_PI), -1, 1, 0, 255);
		palette[(i * 3) + 2] =0;*/

		/*palette[(i * 3) + 0] =255;											//Hitze
		palette[(i * 3) + 1] =map(cos(index * M_PI), -1, 1, 0, 255);
		palette[(i * 3) + 2] =map(sin(index * M_PI), -1, 1, 0, 255);*/

		palette[(i * 3) + 0] =map(sin(index * M_PI), -1, 1, 0, 255);			//Regenbogen
		palette[(i * 3) + 1] =map(sin(index * M_PI + 2.0f * M_PI / 3.0f), -1, 1, 0, 255);
		palette[(i * 3) + 2] =map(sin(index * M_PI + 4.0f * M_PI / 3.0f), -1, 1, 0, 255);

		/*palette[(i * 3) + 0] =map(sin(index * M_PI * 5), -1, 1, 0, 255);		//Schwarz/Weiß
		palette[(i * 3) + 1] =palette[(i * 3) + 0];
		palette[(i * 3) + 2] =palette[(i * 3) + 0];*/
	}

	Fumasu::makeScreenshot("palette.tga", 256, 1, 3, palette.data());

	float zoom =100.0f / 1.0f;

	while(1) {
		for(int y =0;y <HEIGHT;y++) {
			for(int x =0;x <WIDTH;x++) {
				float tmp;
				float cx, cy;
				float grad_x, grad_y;
				grad_x =x * M_PI / 180.0;
				grad_y =y * M_PI / 180.0;
				/*cx =x - WIDTH / 2;
				cy =y - HEIGHT / 2;*/
				cx =(x - WIDTH / 2) + map(sin((counter / 10.0) / 5), -1, 1, -128, 128);
				cy =(y - HEIGHT / 2) + map(cos((counter / 10.0) / 3), -1, 1, -128, 128);

				tmp =sin(zoom * grad_x + counter / 10.0f);
				tmp +=sin(zoom * (grad_x * sin((counter / 10.0) / 2) + grad_y * cos((counter / 10.0) / 3)) + (counter / 10.0f));
				tmp +=sin( sqrt(1 * (pow(cx, 2) + pow(cy, 2)) + 1) * M_PI / 180.0 + counter / 10.0f);
				//tmp /=3;
				tmp =map(tmp, -3, 3, -1, 1);
				/*data[(x * 3) + (y * WIDTH * 3) + 0] =map(sin(tmp * M_PI), -1, 1, 0, 255);
				data[(x * 3) + (y * WIDTH * 3) + 1] =map(cos(tmp * M_PI), -1, 1, 0, 255);
				data[(x * 3) + (y * WIDTH * 3) + 2] =0;*/
				data[(x * 3) + (y * WIDTH * 3) + 0] =palette[(int)map(tmp, -1, 1, 0, 255) * 3 + 0];
				data[(x * 3) + (y * WIDTH * 3) + 1] =palette[(int)map(tmp, -1, 1, 0, 255) * 3 + 1];
				data[(x * 3) + (y * WIDTH * 3) + 2] =palette[(int)map(tmp, -1, 1, 0, 255) * 3 + 2];
			}
		}

		stringstream str;

		str.fill('0');
		str.width(5);
		str <<counter++;

	//	Fumasu::makeScreenshot("imgs/jo"+str.str()+".tga", WIDTH, HEIGHT, 3, data.data());

		//return 0;
	}

	/*counter =0;
	int left, top;

	while(1) {
		left =(2 * 256) + (1 * 256) * sin((10 * counter * M_PI / 180.0f) / 5);
		top =(2 * 256) + (1 * 256) * cos((10 * counter * M_PI / 180.0f) / 3);
		cout <<left <<" " <<top <<endl;
		//return 0;
		for(int x =0;x <256;x++) {
			for(int y =0;y <256;y++) {
				data_2[(x * 3) + (y * 256 * 3) + 0] =data[(left + x) * 3 + ((y + top) * WIDTH *3 ) + 0];
				data_2[(x * 3) + (y * 256 * 3) + 1] =data[(left + x) * 3 + ((y + top) * WIDTH *3 ) + 1];
				data_2[(x * 3) + (y * 256 * 3) + 2] =data[(left + x) * 3 + ((y + top) * WIDTH *3 ) + 2];
			}
		}

		stringstream str;

		str.fill('0');
		str.width(5);
		str <<counter++;

		Fumasu::makeScreenshot("imgs/plasma"+str.str()+".tga", 256, 256, 3, data_2.data());
	}*/

	return 0;
}
