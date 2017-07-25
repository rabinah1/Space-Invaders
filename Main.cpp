#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"

#define IMG_PATH "Space_ship.png"

int main() {
  int speed = 0;
  int s = 0;
  int w, h;
  Player player_1; // Create an object "player_1" of class "Player".
  player_1.Set_lives(15); // Set the lives of the player to be 15.
  player_1.Set_score(100); // Set the score of the player to be 100.
  player_1.Set_name("Henry"); // Set the name of the player.
  std::cout << "Enter the speed of the player: ";
  std::cin >> speed;
  player_1.Set_speed(speed); // Set the speed of the player to be whatever the user decides.
  s = player_1.Give_speed(); // Save the speed of the player to a variable s.
  SDL_Event event;
  int quit = 0;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *img = NULL;
  
  SDL_Init(SDL_INIT_EVERYTHING); // Initialize the SDL-window.
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
  
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // This function creates a 2D rendering context for the window
  img = IMG_LoadTexture(renderer, IMG_PATH);
  SDL_QueryTexture(img, NULL, NULL, &w, &h);
  SDL_SetRenderDrawColor(renderer, 0,0,0,255); // The integer parameters are r,g,b,a where a is the alpha-value
  SDL_RenderClear(renderer); // This function is used to clear the current rendering target with the drawing color
  SDL_Rect r; // A structure that defines a rectangle
  r.x = 10; // The x-coordinate of the rectangle's upper left corner
  r.y = 655; // The y-coordinate of the rectangle's upper left corner
  r.w = w; // The width of the rectangle
  r.h = h; // The height of the rectangle
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderCopy(renderer, img, NULL, &r);
  //SDL_RenderFillRect(renderer, &r);
  SDL_RenderPresent(renderer); // This function is used to update the screen with any rendering performance since the previous call
  
  while (quit == 0) {
    if (SDL_PollEvent(&event)) // Poll for pending events
      {
	switch(event.type)
	 {
	 case SDL_QUIT: // If the user clicks on the x-button in the top left corner
	   quit = 1;
	   break;
	   
	 case SDL_KEYDOWN: // If some keyboard key is pressed down
	   if (event.key.keysym.sym == SDLK_RIGHT) { // If the pressed key is the right arrow.
	     SDL_SetRenderDrawColor(renderer, 0,0,0,255); // Set the render draw color to black.
	     SDL_RenderClear(renderer);
	     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	     r.x = r.x + s;
	     //SDL_RenderFillRect(renderer, &r);
	     SDL_RenderCopy(renderer, img, NULL, &r);
	     SDL_RenderPresent(renderer);
	  }
	   else if (event.key.keysym.sym == SDLK_LEFT) { // If the pressed key is the left arrow.
	     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	     SDL_RenderClear(renderer);
	     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	     r.x = r.x - s;
	     //SDL_RenderFillRect(renderer, &r);
	     SDL_RenderCopy(renderer, img, NULL, &r);
	     SDL_RenderPresent(renderer);
	   }
	   else if (event.key.keysym.sym == SDLK_SPACE) { // If the pressed key is the space button.
	     printf("Hello world!\n"); // Create a bullet here
	   }
	 }
      }
  }
  SDL_DestroyTexture(img);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window); // This destroys the window
  SDL_Quit();
  return 0;
}
