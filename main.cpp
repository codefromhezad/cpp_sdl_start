#include <iostream>
#include <SDL2/SDL.h>

#include "RayRenderer.h"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;


int main(int, char**){
	
	RayRenderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);

	if( ! renderer.init() ) {
		return 1;
	}

	for(int i = 0; i < SCREEN_WIDTH; i++) {
		renderer.setPixel(i, 40, 255, 0, 0);
	}

	renderer.render();
	
	SDL_Delay(3000);

	return 0;
}