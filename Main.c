#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  SDL_Event event;
  int quit = 0;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("An SDL2 window",
			    10, // X-coordinate of the upper left corner of the window
			    10, // Y-coordinate of the upper left corner of the window
			    640, // Size of the window in x-direction
			    480, // Size of the window in y-direction
			    SDL_WINDOW_OPENGL // In here we can add different flags. Syntax for multiple flags is: flag1 | flag2 | flag3...
			    );
  if (window == NULL) { // If the creation of the window was not succesfull
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }
  renderer = SDL_CreateRenderer(window, -1, 0); // This function creates a 2D rendering context for the window
  SDL_SetRenderDrawColor(renderer, 0,0,0,255); // The integer parameters are r,g,b,a where a is the alpha-value
  SDL_RenderClear(renderer); // This function is used to clear the current rendering target with the drawing color
  SDL_RenderPresent(renderer); // This function is used to update the screen with any rendering performance since the previous call
  while (quit == 0) {
    if (SDL_PollEvent(&event))
      {
	switch(event.type)
	  {
	  case SDL_QUIT:
	    quit = 1;
	    break;
	  }
      }
  }
  SDL_DestroyWindow(window); // This destroys the window
  SDL_Quit();
  return 0;
}
