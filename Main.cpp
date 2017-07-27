#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "Player.h"
#include "Enemy.h"

#define IMG_PATH "Space_ship.png"

int main() {
  // Initialize variables and structures that are needed for the program.
  int rem = 0;
  int speed = 0;
  int w, h;
  Player player_1; // Create an object "player_1" of class "Player".
  SDL_Event event; // A union that contains structures for different event types.
  int quit = 0;
  SDL_Window *window;
  SDL_Renderer *renderer; // A structure that contains a rendering state.
  SDL_Texture *PlayerShip = NULL; // A structure that contains representation of pixel data.
  int CheckIfDestroyed = 1;
  
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
  SDL_Rect ShipRect; // A structure that defines a rectangle
  ShipRect.x = 10; // The x-coordinate of the rectangle's upper left corner
  ShipRect.y = 655; // The y-coordinate of the rectangle's upper left corner
  ShipRect.w = w; // The width of the rectangle
  ShipRect.h = h; // The height of the rectangle
  SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect); // Copy the image to the rectangle r.
  SDL_RenderPresent(renderer); // This function is used to update the screen with any rendering performance since the previous call
  SDL_Rect *PlayerBullet = NULL;
  
  while (quit == 0) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect);
    if (CheckIfDestroyed == 0)
      {
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderFillRect(renderer, PlayerBullet);
	if (rem % 2 == 0)
	  {
	    PlayerBullet->y = PlayerBullet->y - 1;
	  }
	rem = rem + 1;
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	if (PlayerBullet->y < 0)
	  {
	    CheckIfDestroyed = 1;
	    delete(PlayerBullet);
	    rem = 0;
	  }
      }
    SDL_RenderPresent(renderer);
    if (SDL_PollEvent(&event)) // Poll for pending events
      {
	switch(event.type)
	 {
	 case SDL_QUIT: // If the user clicks on the x-button in the top left corner
	   quit = 1;
	   break;
	   
	 case SDL_KEYDOWN: // If some keyboard key is pressed down
	   if (event.key.keysym.sym == SDLK_RIGHT) { // If the pressed key is the right arrow.
	     ShipRect.x = ShipRect.x + speed;
	  }
	   else if (event.key.keysym.sym == SDLK_LEFT) { // If the pressed key is the left arrow.
	     ShipRect.x = ShipRect.x - speed;
	   }
	   else if (event.key.keysym.sym == SDLK_SPACE && CheckIfDestroyed == 1) { // If the pressed key is the space button.
	     PlayerBullet = new SDL_Rect;
	     CheckIfDestroyed = 0;
	     PlayerBullet->x = ShipRect.x + 32;
	     PlayerBullet->y = ShipRect.y;
	     PlayerBullet->w = 5;
	     PlayerBullet->h = 5;
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
