#include <SDL2/SDL.h>

#include"fisica_del_juego.h"
#include"config.h"
#include"naves.h"
#include"vectores_dinamicos.h"
#include"generador_terreno.h"

int main(){
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Lunar Lander");

	int dormir = 0;

	// BEGIN código del alumno
	/*Declaro las variables a utilizar*/
	size_t a = 0;
	size_t *n = &a;
	float **terreno =	crear_terreno(n);
	// Mi nave:
	const float (*nave)[2] = nave_grande;
	size_t nave_tam = sizeof(nave_grande) / sizeof(nave_grande[0]);
	float **navedin = vector_desde_matriz(nave, nave_tam);
	// El chorro de la nave:
	float chorro[3][2] = {
		{-NAVE_GRANDE_TOBERA_X, NAVE_GRANDE_TOBERA_Y},
		{0, NAVE_GRANDE_TOBERA_Y},
		{NAVE_GRANDE_TOBERA_X, NAVE_GRANDE_TOBERA_Y}
	};

	// Queremos que todo se dibuje escalado por f:
	float f = 2;

	// END código del alumno

	unsigned int ticks = SDL_GetTicks();
	while(1){

		if(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				break;
	    		if (event.type == SDL_KEYDOWN) {
				// BEGIN código del alumno
				switch(event.key.keysym.sym) {
					case SDLK_UP:
						// Agrandamos el dibujo del chorro:
						chorro[1][1] -= 1;
						break;
					case SDLK_DOWN:
						// Achicamos el dibujo del chorro:
						chorro[1][1] += 1;
					case SDLK_RIGHT:
					  rotar(nave, nave_tam, NAVE_ROTACION_PASO);
						rotar(chorro, 3, NAVE_ROTACION_PASO);
						break;
					case SDLK_LEFT:
						rotar(nave, nave_tam, NAVE_ROTACION_PASO);
				 		rotar(chorro, 3, NAVE_ROTACION_PASO);
						break;
				}
				// END código del alumno


			}
			continue;
		}
        	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        	SDL_RenderClear(renderer);
        	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);


		// BEGIN código del alumno
		/* Dibujo el terreno aleatorio */
		for(int i = 0; i < *n - 1; i++)
			SDL_RenderDrawLine(
				renderer,
				terreno[i][0],
				-terreno[i][1] + VENTANA_ALTO,
				terreno[i+1][0],
				-terreno[i+1][1] + VENTANA_ALTO
			);

		// Dibujamos la nave escalada por f en el centro de la pantalla:
		for(int i = 0; i < nave_tam - 1; i++)
			SDL_RenderDrawLine(
				renderer,
				nave[i][0] * f + VENTANA_ANCHO / 2,
				-nave[i][1] * f + VENTANA_ALTO / 2,
				nave[i+1][0] * f + VENTANA_ANCHO / 2,
				-nave[i+1][1] * f + VENTANA_ALTO / 2
			);

		// Dibujamos el chorro escalado por f en el centro de la pantalla:
		for(int i = 0; i < 3 - 1; i++)
			SDL_RenderDrawLine(
				renderer,
				chorro[i][0] * f + VENTANA_ANCHO / 2,
				-chorro[i][1] * f + VENTANA_ALTO / 2,
				chorro[i+1][0] * f + VENTANA_ANCHO / 2,
				-chorro[i+1][1] * f + VENTANA_ALTO / 2
			);
		// END código del alumno


        	SDL_RenderPresent(renderer);
		ticks = SDL_GetTicks() - ticks;
		if(dormir) {
			SDL_Delay(dormir);
			dormir = 0;
		}
		else if(ticks < 1000 / JUEGO_FPS)
			SDL_Delay(1000 / JUEGO_FPS - ticks);
		ticks = SDL_GetTicks();
	}

	// BEGIN código del alumno
	// No tengo nada que destruir.
	// END código del alumno

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
