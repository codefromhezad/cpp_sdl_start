#include <iostream>

/* CONSTS */
const float FLT_EPSILON = 0.00001;
const float MAX_DISTANCE = 9999999;

/* LIBS */
#include <SDL2/SDL.h>
#include "lib/Eigen/Dense"

/* HEADERS */
#include "headers/HColor.h"
#include "headers/HRay.h"
#include "headers/HMaterial.h"
#include "headers/HGeometry.h"
#include "headers/HGeometrySphere.h"
#include "headers/HRenderer.h"
#include "headers/HScene.h"

/* NAMESPACES*/
using namespace Eigen;


/* ENTRY POINT */
int main(int, char**){
	
	HRenderer renderer(640, 480);

	if( ! renderer.init() ) {
		return 1;
	}

	renderer.render();
	
	SDL_Delay(3000);

	return 0;
}