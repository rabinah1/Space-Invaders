#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Functions.h"

#define USER "Space_ship.png"
#define ENEMY "Enemy.png"

int main() {
  //Initialize variables and structures that are needed for the program.
  std::vector <SDL_Rect*> EnemyList; // A vector that contains pointers to enemies.
  EnemyList = InitEnemyList(); // Create enemies and add them to a list. This function can be found in the file "Functions.cpp".
  std::string UserName = "None"; // This is the name of the player.
  int remainder = 0; // This is a counter that ensures that position of a bullet shot by the player is updated only once in every two iterations.
  int speed = 0; // This is the speed of the player.
  int w_player = 0; // The width of the image of the player's spaceship.
  int h_player = 0; // The height of the image of the player's spaceship.
  int w_enemy = 0; // The width of the image of an enemy.
  int h_enemy = 0; // The height of the image of an enemy.
  int init_height = 0;
  int init_width = 0;
  int *WindowHeight = &init_height; // The height of the window.
  int *WindowWidth = &init_width; // The width of the window.
  int quit = 0; // This variable is used to determine when to exit the main loop.
  int dir = 0; // This variable defines the direction to which the enemis move. Enemies can move to left or right.
  clock_t t;
  int CheckIfDestroyed = 1; // This variable checks whether there is a bullet shot by the player in the field or not. This is important because the player can shoot a new bullet only if the previous bullet has already been destroyed.
  
  Player player_1; // Create an object "player_1" of class "Player".
  SDL_Event event; // A union that contains structures for different event types.
  SDL_Window *window = NULL; // The window where we will be rendering to.
  SDL_Renderer *renderer = NULL; // A structure that contains a rendering state.
  SDL_Texture *PlayerShip = NULL; // A structure that contains representation of pixel data, in this case the image of the player's spaceship.
  SDL_Texture *EnemyAlien = NULL; // A structure that contas the image of an enemy.
  SDL_Rect ShipRect; // A structure that defines a rectangle.
  SDL_Rect *PlayerBullet = NULL;
  
  player_1.Set_lives(3); // Set the lives of the player to be 3.
  player_1.Set_score(0); // Set the score of the player to be 0.
  player_1.Set_speed(12); // Set the speed of the player to be 12.
  speed = player_1.Give_speed();
  std::cout << "Enter your name: ";
  std::cin >> UserName;
  player_1.Set_name(UserName); // Set the name of the player.
  
  SDL_Init(SDL_INIT_VIDEO); // Initialize the SDL-window.
  window = SDL_CreateWindow("Space Invaders", // Title of the window.
			    100, // X-coordinate of the upper left corner of the window.
			    50, // Y-coordinate of the upper left corner of the window.
			    1100, // Size of the window in x-direction.
			    800, // Size of the window in y-direction.
			    SDL_WINDOW_OPENGL/* | SDL_WINDOW_RESIZABLE*/ // In here we can add different flags. Syntax for multiple flags is: flag1 | flag2 | flag3...
			    );
  if (window == NULL) { // If the creation of the window was not succesfull
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // This function creates a 2D rendering context for the window. We set the renderer to use hardware acceleration.
  PlayerShip = IMG_LoadTexture(renderer, USER); // Load the image of the spaceship of the player.
  EnemyAlien = IMG_LoadTexture(renderer, ENEMY);
  SDL_QueryTexture(PlayerShip, NULL, NULL, &w_player, &h_player); // Get the width and height of the player's spaceship.
  SDL_QueryTexture(EnemyAlien, NULL, NULL, &w_enemy, &h_enemy);
  SDL_SetRenderDrawColor(renderer, 0,0,0,255); // The integer parameters are r,g,b,a where a is the alpha-value.
  SDL_RenderClear(renderer); // This function is used to clear the current rendering target with the drawing color.
  ShipRect.x = 10; // The x-coordinate of the rectangle's upper left corner.
  ShipRect.y = 655; // The y-coordinate of the rectangle's upper left corner.
  ShipRect.w = w_player; // The width of the rectangle.
  ShipRect.h = h_player; // The height of the rectangle.
  for (int j = 0; j < EnemyList.size(); ++j) // Set the initial positions and sizes of the enemies. Also copy the image of an enemy in place of the rectangle that represent an enemy.
    {
      EnemyList[j]->x = 10 + j*40;
      EnemyList[j]->y = 350;
      EnemyList[j]->w = w_enemy;
      EnemyList[j]->h = h_enemy;
      SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
    }
  SDL_RenderPresent(renderer); // This function is used to update the screen with any rendering performance since the previous call.
  t = clock();
  
  while (quit == 0) { // Start the main loop of the game.
    SDL_GetWindowSize(window, WindowWidth, WindowHeight); // Get the height and width of the window.
    ShipRect.y = *WindowHeight - 45; // This keeps the player's spaceship in the bottom of the screen even if we resize the window.
    if (float(clock()-t)/CLOCKS_PER_SEC > 0.32)
      {
	if ((EnemyList[3])->x >= *WindowWidth) // If the position of the enemy on the far right exceeds the screen width.
	  {
	    dir = 0;
	  }
	else if ((EnemyList[0])->x <= 10) // If the x-coordinate of the position of the enemy on the far right is less than 10.
	  {
	    dir = 1;
	  }
	for(int i = 0; i < EnemyList.size(); ++i) // Loop through all enemies.
	  {
	    t = clock();
	    if (dir == 0)
	      {
		(EnemyList[i])->x = (EnemyList[i])->x - 15; // Move an enemy to the left.
	      }
	    else
	      {
		(EnemyList[i])->x = (EnemyList[i])->x + 15; // Move an enemy to the right.
	      }
	  }
      }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect);
    for (int j = 0; j < EnemyList.size(); ++j) // Loop through all the enemies.
      {
	SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
      }
    if (CheckIfDestroyed == 0) // If there exists a bullet shot by the player in the game field.
      {
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderFillRect(renderer, PlayerBullet); // Paint the bullet white.
	if (remainder % 2 == 0) // If the variable "remainder" is an even number, update the position of the bullet.
	  {
	    PlayerBullet->y = PlayerBullet->y - 1;
	  }
	remainder = remainder + 1;
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
	if (PlayerBullet->y < 0) // If the bullet has moved outside the window.
	{
	  CheckIfDestroyed = 1;
	  delete(PlayerBullet);
	  remainder = 0;
	}
      }
    SDL_RenderPresent(renderer);
    if (SDL_PollEvent(&event)) // Poll for pending events
      {
	switch(event.type)
	 {
	 case SDL_QUIT: // If the user clicks on the x-button in the top left corner
	   quit = 1;
	   for (int j = 0; j < EnemyList.size(); ++j) // Free the memory allocated for each enemy.
	     {
	       delete(EnemyList[j]);
	     }
	   break;
	   
	 case SDL_KEYDOWN: // If some keyboard key is pressed down
	   if (event.key.keysym.sym == SDLK_RIGHT) { // If the pressed key is the right arrow.
	     ShipRect.x = ShipRect.x + speed; // Move the spaceship to the right.
	  }
	   else if (event.key.keysym.sym == SDLK_LEFT) { // If the pressed key is the left arrow.
	     ShipRect.x = ShipRect.x - speed; // Move the spaceship to the left.
	   }
	   else if (event.key.keysym.sym == SDLK_SPACE && CheckIfDestroyed == 1) { // If the pressed key is the space button and there does not exist a bullet shot by the player in the field.
	     PlayerBullet = new SDL_Rect; // Allocate memory for new bullet.
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
