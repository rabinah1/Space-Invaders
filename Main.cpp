#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  SDL_Event event;
  int quit = 0;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("Space Invaders",
			    100, // X-coordinate of the upper left corner of the window
			    50, // Y-coordinate of the upper left corner of the window
			    1000, // Size of the window in x-direction
			    700, // Size of the window in y-direction
			    SDL_WINDOW_OPENGL // In here we can add different flags. Syntax for multiple flags is: flag1 | flag2 | flag3...
			    );
  if (window == NULL) { // If the creation of the window was not succesfull
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }
  renderer = SDL_CreateRenderer(window, -1, 0); // This function creates a 2D rendering context for the window
  SDL_SetRenderDrawColor(renderer, 255,255,255,255); // The integer parameters are r,g,b,a where a is the alpha-value
  SDL_RenderClear(renderer); // This function is used to clear the current rendering target with the drawing color
  SDL_Rect r;
  r.x = 10;
  r.y = 640;
  r.w = 50;
  r.h = 50;
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderFillRect(renderer, &r);
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
