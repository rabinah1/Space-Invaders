#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"

#define IMG_PATH "Space_ship.png"

int main() {
  // Initialize variables and structures that are needed for the program.
  int speed = 0;
  int w, h;
  Player player_1; // Create an object "player_1" of class "Player".
  SDL_Event event; // A union that contains structures for different event types.
  int quit = 0;
  SDL_Window *window;
  SDL_Renderer *renderer; // A structure that contains a rendering state.
  SDL_Texture *PlayerShip = NULL; // A structure that contains representation of pixel data.
  
  player_1.Set_lives(15); // Set the lives of the player to be 15.
  player_1.Set_score(100); // Set the score of the player to be 100.
  player_1.Set_name("Henry"); // Set the name of the player.
  std::cout << "Enter the speed of the player: ";
  std::cin >> speed; // We save the speed of the player to a variable "speed".
  player_1.Set_speed(speed); // Set the speed of the player to be whatever the user decides.
  
  SDL_Init(SDL_INIT_EVERYTHING); // Initialize the SDL-window.
  window = SDL_CreateWindow("Space Invaders", // Title of the window.
			    100, // X-coordinate of the upper left corner of the window.
			    50, // Y-coordinate of the upper left corner of the window.
			    1000, // Size of the window in x-direction.
			    700, // Size of the window in y-direction.
			    SDL_WINDOW_OPENGL // In here we can add different flags. Syntax for multiple flags is: flag1 | flag2 | flag3...
			    );
  if (window == NULL) { // If the creation of the window was not succesfull
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }
  
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // This function creates a 2D rendering context for the window. We set the renderer to use hardware acceleration.
  PlayerShip = IMG_LoadTexture(renderer, IMG_PATH); // Load the image.
  SDL_QueryTexture(PlayerShip, NULL, NULL, &w, &h); // Get the width and height of the image.
  SDL_SetRenderDrawColor(renderer, 0,0,0,255); // The integer parameters are r,g,b,a where a is the alpha-value
  SDL_RenderClear(renderer); // This function is used to clear the current rendering target with the drawing color
  SDL_Rect r; // A structure that defines a rectangle
  r.x = 10; // The x-coordinate of the rectangle's upper left corner
  r.y = 655; // The y-coordinate of the rectangle's upper left corner
  r.w = w; // The width of the rectangle
  r.h = h; // The height of the rectangle
  SDL_RenderCopy(renderer, PlayerShip, NULL, &r); // Copy the image to the rectangle r.
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
	     r.x = r.x + speed;
	     SDL_RenderCopy(renderer, PlayerShip, NULL, &r);
	     SDL_RenderPresent(renderer);
	  }
	   else if (event.key.keysym.sym == SDLK_LEFT) { // If the pressed key is the left arrow.
	     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	     SDL_RenderClear(renderer);
	     r.x = r.x - speed;
	     SDL_RenderCopy(renderer, PlayerShip, NULL, &r);
	     SDL_RenderPresent(renderer);
	   }
	   else if (event.key.keysym.sym == SDLK_SPACE) { // If the pressed key is the space button.
	     printf("Hello world!\n"); // Create a bullet here
	   }
	 }
      }
  }
  SDL_DestroyTexture(PlayerShip); // Destroy the img-texture.
  SDL_DestroyRenderer(renderer); // Destroy the rendering context for a window and free associated textures.
  SDL_DestroyWindow(window); // This destroys the window
  SDL_Quit();
  return 0;
}
