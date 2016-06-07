#include <iostream>
#include <vector>

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
#include "headers/HScene.h"
#include "headers/HRenderer.h"

/* NAMESPACES*/
using namespace Eigen;


/* ENTRY POINT */
int main(int, char**){
	
	HRenderer renderer(640, 480);
	HScene scene;

	if( ! renderer.init() ) {
		return 1;
	}

	HGeometrySphere sphere = HGeometrySphere(Vector3d(0, 0, 0), 150);

	scene.addSphere(sphere);

	renderer.render(scene);
	
	SDL_Delay(3000);

	return 0;
}