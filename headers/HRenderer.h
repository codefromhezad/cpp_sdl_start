using namespace Eigen;

class HRenderer {
	int rendererWidth, 
		rendererHeight;
	SDL_Window *rendererWindow;
	SDL_Renderer *rendererSDLRenderer;

public:
	HRenderer(int width, int height) {
		rendererWidth = width;
		rendererHeight = height;
	}

	bool init() {
		/* Init SDL */
		if (SDL_Init(SDL_INIT_VIDEO) != 0){
			std::cout << "SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		/* Open SDL Window */
		rendererWindow = SDL_CreateWindow("Test", 100, 100, rendererWidth, rendererHeight, SDL_WINDOW_SHOWN);
		if( rendererWindow == nullptr ) {
			std::cout << "SDL Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		}

		/* Setup SDL Renderer */
		rendererSDLRenderer = SDL_CreateRenderer(rendererWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if( rendererSDLRenderer == nullptr ) {
			SDL_DestroyWindow(rendererWindow);
			std::cout << "SDL Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return false;
		}

		SDL_RenderClear(rendererSDLRenderer);

		/* Everything's OK */
		return true;
	}


	void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
		SDL_SetRenderDrawColor(rendererSDLRenderer, r, g, b, 255);
		SDL_RenderDrawPoint(rendererSDLRenderer, x, y);
	}


	void render(HScene scene) {
		int worldX, worldY;

		HRay sceneRay;

		for(int i = 0; i < rendererWidth; i++) {
			for(int j = 0; j < rendererHeight; j++) {

				worldX = i - rendererWidth * 0.5;
				worldY = j - rendererHeight * 0.5;

				sceneRay.position(0) = worldX;
				sceneRay.position(1) = worldY;
				sceneRay.position(2) = -400;

				sceneRay.direction(0) = 0;
				sceneRay.direction(1) = 0;
				sceneRay.direction(2) = 1.0;

				HColor pixelColor = scene.castRay(sceneRay);

				setPixel(i, j, pixelColor.r * 255, pixelColor.g * 255, pixelColor.b * 255);
			}
		}

		SDL_RenderPresent(rendererSDLRenderer);
	}


	void cleanup() {
		SDL_DestroyRenderer(rendererSDLRenderer);
		SDL_DestroyWindow(rendererWindow);
		SDL_Quit();
	}
};
