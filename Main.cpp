#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "Player.h"
#include "Functions.h"

#define USER "Space_ship.png"
#define ENEMY "Enemy.png"

int game(SDL_Event e, SDL_Window *w, SDL_Renderer *r);

int main() {
  SDL_Event e; // Event.
  SDL_Window *w = NULL; // Window.
  SDL_Renderer *r = NULL; // Renderer.
  int quit = 0; // A variable that determines when to exit the program.
  int return_value = 0;
  int mousex_init = 0;
  int mousey_init = 0;
  int *mousex = &mousex_init; // X-coordinate of the cursor.
  int *mousey = &mousey_init; // Y-coordinate of the cursor.
  SDL_Init(SDL_INIT_VIDEO); // Initialize the SDL-window.
  TTF_Init(); // Initialize TTF.
  w = SDL_CreateWindow("Space Invaders", // Title of the window.
			    100, // X-coordinate of the upper left corner of the window.
			    50, // Y-coordinate of the upper left corner of the window.
			    1100, // Size of the window in x-direction.
			    800, // Size of the window in y-direction.
			    SDL_WINDOW_OPENGL/* | SDL_WINDOW_RESIZABLE*/ // In here we can add different flags. Syntax for multiple flags is: flag1 | flag2 | flag3...
			    );
  if (w == NULL) { // If the creation of the window was not succesfull
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }
  
  r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED); // Create the renderer.
  SDL_SetRenderDrawColor(r, 0,0,0,255); // Set the drawing color of the renderer to black.
  TTF_Font *HeadingFont = TTF_OpenFont("Ubuntu-B.ttf", 140); // Create font.
  TTF_Font *ButtonFont = TTF_OpenFont("Ubuntu-L.ttf", 35);
  SDL_Color Green = {0,255,0}; // Define a color.
  SDL_Color White = {255,255,255};
  SDL_Surface *surfaceHeading1 = TTF_RenderText_Solid(HeadingFont, "Space", Green);
  SDL_Surface *surfaceHeading2 = TTF_RenderText_Solid(HeadingFont, "Invaders", Green);
  SDL_Surface *surfaceStart = TTF_RenderText_Solid(ButtonFont, "Start game", White);
  SDL_Surface *surfaceControls = TTF_RenderText_Solid(ButtonFont, "Controls", White);
  SDL_Surface *surfaceExit = TTF_RenderText_Solid(ButtonFont, "Exit", White);
  SDL_Texture *Heading1 = SDL_CreateTextureFromSurface(r, surfaceHeading1);
  SDL_Texture *Heading2 = SDL_CreateTextureFromSurface(r, surfaceHeading2);
  SDL_Texture *StartButton = SDL_CreateTextureFromSurface(r, surfaceStart);
  SDL_Texture *ControlsButton = SDL_CreateTextureFromSurface(r, surfaceControls);
  SDL_Texture *ExitButton = SDL_CreateTextureFromSurface(r, surfaceExit);
  SDL_Rect Heading1_Rect;
  SDL_Rect Heading2_Rect;
  SDL_Rect Start_Rect;
  SDL_Rect Controls_Rect;
  SDL_Rect Exit_Rect;
  Heading1_Rect.x = 380;
  Heading1_Rect.y = 80;
  Heading1_Rect.w = 300;
  Heading1_Rect.h = 170;
  Heading2_Rect.x = 340;
  Heading2_Rect.y = 230;
  Heading2_Rect.w = 400;
  Heading2_Rect.h = 170;
  Start_Rect.x = 420;
  Start_Rect.y = 410;
  Start_Rect.w = 200;
  Start_Rect.h = 70;
  Controls_Rect.x = 420;
  Controls_Rect.y = 520;
  Controls_Rect.w = 200;
  Controls_Rect.h = 70;
  Exit_Rect.x = 465;
  Exit_Rect.y = 630;
  Exit_Rect.w = 100;
  Exit_Rect.h = 70;
  SDL_RenderClear(r);
  SDL_RenderCopy(r, Heading1, NULL, &Heading1_Rect);
  SDL_RenderCopy(r, Heading2, NULL, &Heading2_Rect);
  SDL_RenderCopy(r, StartButton, NULL, &Start_Rect);
  SDL_RenderCopy(r, ControlsButton, NULL, &Controls_Rect);
  SDL_RenderCopy(r, ExitButton, NULL, &Exit_Rect);
  SDL_RenderPresent(r);
  
  while (quit == 0)
    {
      SDL_GetMouseState(mousex, mousey);
      if (SDL_PollEvent(&e)) // Poll for pending events
      {
	switch(e.type)
	 {
	 case SDL_QUIT: // If the user clicks on the x-button in the top left corner
	   quit = 1;

	 case SDL_MOUSEBUTTONUP:
	   if (*mousex >= 420 && *mousex <= 620 && *mousey >= 410 && *mousey <= 480) {
	     return_value = game(e, w, r);
	     if (return_value != 1)
	       {
		 SDL_FreeSurface(surfaceHeading1);
		 SDL_FreeSurface(surfaceHeading2);
		 SDL_FreeSurface(surfaceStart);
		 SDL_FreeSurface(surfaceControls);
		 SDL_FreeSurface(surfaceExit);
		 SDL_DestroyTexture(Heading1);
		 SDL_DestroyTexture(Heading2);
		 SDL_DestroyTexture(StartButton);
		 SDL_DestroyTexture(ControlsButton);
		 SDL_DestroyTexture(ExitButton);
		 TTF_CloseFont(HeadingFont);
		 TTF_CloseFont(ButtonFont);
		 return 0;
	       }
	     else
	       {
		 SDL_RenderClear(r);
		 SDL_RenderCopy(r, Heading1, NULL, &Heading1_Rect);
		 SDL_RenderCopy(r, Heading2, NULL, &Heading2_Rect);
		 SDL_RenderCopy(r, StartButton, NULL, &Start_Rect);
		 SDL_RenderCopy(r, ControlsButton, NULL, &Controls_Rect);
		 SDL_RenderCopy(r, ExitButton, NULL, &Exit_Rect);
		 SDL_RenderPresent(r);
	       }
	   }
	   else if (*mousex >= 465 && *mousex <= 565 && *mousey >= 630 && *mousey <= 700)
	     {
	       quit = 1;
	     }
	   else if (*mousex >= 420 && *mousex <= 620 && *mousey >= 520 && *mousey <= 590)
	     {
	       GuideWindow(e, w, r);
	       SDL_RenderClear(r);
	       SDL_RenderCopy(r, Heading1, NULL, &Heading1_Rect);
	       SDL_RenderCopy(r, Heading2, NULL, &Heading2_Rect);
	       SDL_RenderCopy(r, StartButton, NULL, &Start_Rect);
	       SDL_RenderCopy(r, ControlsButton, NULL, &Controls_Rect);
	       SDL_RenderCopy(r, ExitButton, NULL, &Exit_Rect);
	       SDL_RenderPresent(r);
	     }
	 }
      }
    }
  SDL_FreeSurface(surfaceHeading1);
  SDL_FreeSurface(surfaceHeading2);
  SDL_FreeSurface(surfaceStart);
  SDL_FreeSurface(surfaceControls);
  SDL_FreeSurface(surfaceExit);
  SDL_DestroyTexture(Heading1);
  SDL_DestroyTexture(Heading2);
  SDL_DestroyTexture(StartButton);
  SDL_DestroyTexture(ControlsButton);
  SDL_DestroyTexture(ExitButton);
  TTF_CloseFont(HeadingFont);
  TTF_CloseFont(ButtonFont);
  SDL_DestroyWindow(w);
  SDL_DestroyRenderer(r);
  SDL_Quit();
  return 0;
}

int game(SDL_Event event, SDL_Window *window, SDL_Renderer *renderer) {
  //Initialize variables and structures that are needed for the program.
  TTF_Font *ButtonFont = TTF_OpenFont("Ubuntu-L.ttf", 65);
  int mousex_init = 0;
  int mousey_init = 0;
  int *mousex = &mousex_init;
  int *mousey = &mousey_init;
  SDL_Color White = {255,255,255};
  SDL_Surface *surfaceButton1 = TTF_RenderText_Solid(ButtonFont, "Return to menu", White);
  SDL_Surface *surfaceButton2 = TTF_RenderText_Solid(ButtonFont, "Exit", White);
  std::string UserName = "Henry"; // This is the name of the player.
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
  int dir = 1; // This variable defines the direction to which the enemis move. Enemies can move to left or right.
  int PauseFlag = 0;
  clock_t t;
  int CheckIfDestroyed = 1; // This variable checks whether there is a bullet shot by the player in the field or not. This is important because the player can shoot a new bullet only if the previous bullet has already been destroyed.
  std::vector <SDL_Rect*> EnemyList; // A vector that contains pointers to enemies.
  EnemyList = InitEnemyList(); // Create enemies and add them to a list. This function can be found in the file "Functions.cpp".
  
  Player player_1; // Create an object "player_1" of class "Player".
  SDL_Texture *PlayerShip = NULL; // A structure that contains representation of pixel data, in this case the image of the player's spaceship.
  SDL_Texture *EnemyAlien = NULL; // A structure that contas the image of an enemy.
  SDL_Rect ShipRect; // A structure that defines a rectangle.
  SDL_Rect *PlayerBullet = NULL;
  player_1.Set_lives(3); // Set the lives of the player to be 3.
  player_1.Set_score(0); // Set the score of the player to be 0.
  player_1.Set_speed(12); // Set the speed of the player to be 12.
  speed = player_1.Give_speed();
  player_1.Set_name(UserName); // Set the name of the player.
  SDL_Init(SDL_INIT_VIDEO); // Initialize the SDL-window.
  
  PlayerShip = IMG_LoadTexture(renderer, USER); // Load the image of the spaceship of the player.
  EnemyAlien = IMG_LoadTexture(renderer, ENEMY);
  SDL_QueryTexture(PlayerShip, NULL, NULL, &w_player, &h_player); // Get the width and height of the player's spaceship.
  SDL_QueryTexture(EnemyAlien, NULL, NULL, &w_enemy, &h_enemy);
  SDL_SetRenderDrawColor(renderer, 0,0,0,255); // The integer parameters are r,g,b,a where a is the alpha-value.
  SDL_RenderClear(renderer); // This function is used to clear the current rendering target with the drawing color.
  SDL_Texture *Button1 = SDL_CreateTextureFromSurface(renderer, surfaceButton1);
  SDL_Texture *Button2 = SDL_CreateTextureFromSurface(renderer, surfaceButton2);
  SDL_Rect Button1Rect;
  SDL_Rect Button2Rect;
  Button1Rect.x = 10;
  Button1Rect.y = 5;
  Button1Rect.w = 330;
  Button1Rect.h = 100;
  Button2Rect.x = 950;
  Button2Rect.y = 5;
  Button2Rect.w = 120;
  Button2Rect.h = 100;
  ShipRect.x = 10; // The x-coordinate of the rectangle's upper left corner.
  ShipRect.y = 655; // The y-coordinate of the rectangle's upper left corner.
  ShipRect.w = w_player; // The width of the rectangle.
  ShipRect.h = h_player; // The height of the rectangle.
  for (int j = 0; j < EnemyList.size(); ++j) // Set the initial positions and sizes of the enemies. Also copy the image of an enemy in place of the rectangle that represent an enemy.
    {
      EnemyList[j]->x = 10 + j*45 - j/10*10*45;
      EnemyList[j]->y = 400 - h_enemy*(j/10) - j/10*5;
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
	if ((EnemyList[EnemyList.size()-1])->x >= *WindowWidth - w_enemy) // If the position of the enemy on the far right exceeds the screen width.
	  {
	    dir = 0;
	    for (int j = 0; j < EnemyList.size(); ++j) // Set the initial positions and sizes of the enemies. Also copy the image of an enemy in place of the rectangle that represent an enemy.
	      {
		EnemyList[j]->y = EnemyList[j]->y + 10;
	      }
	  }
	else if ((EnemyList[0])->x <= 0) // If the x-coordinate of the position of the enemy on the far left is less than 10.
	  {
	    dir = 1;
	    for (int j = 0; j < EnemyList.size(); ++j)
	      {
		EnemyList[j]->y = EnemyList[j]->y + 10;
	      }
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
	for(int j = 0; j < EnemyList.size(); ++j)
	  {
	    if (SDL_HasIntersection(EnemyList[j], PlayerBullet) == SDL_TRUE)
	      {
		EnemyList.erase(EnemyList.begin()+j);
		CheckIfDestroyed = 1;
		delete(PlayerBullet);
		remainder = 0;
	      }
	  }
	if (CheckIfDestroyed == 0)
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
	   else if (event.key.keysym.sym == SDLK_p) {
	     while (1)
	       {
		 SDL_GetMouseState(mousex, mousey);
		 SDL_RenderClear(renderer);
		 SDL_RenderCopy(renderer, Button1, NULL, &Button1Rect);
		 SDL_RenderCopy(renderer, Button2, NULL, &Button2Rect);
		 SDL_RenderCopy(renderer, PlayerShip, NULL, &ShipRect);
		 for (int j = 0; j < EnemyList.size(); ++j) // Loop through all the enemies.
		   {
		     SDL_RenderCopy(renderer, EnemyAlien, NULL, EnemyList[j]);
		   }
		 if (CheckIfDestroyed == 0) // If there exists a bullet shot by the player in the game field.
		   {
		     SDL_SetRenderDrawColor(renderer, 255,255,255,255);
		     SDL_RenderFillRect(renderer, PlayerBullet); // Paint the bullet white.
		     SDL_SetRenderDrawColor(renderer, 0,0,0,255);
		     if (PlayerBullet->y < 0) // If the bullet has moved outside the window.
		       {
			 CheckIfDestroyed = 1;
			 delete(PlayerBullet);
			 remainder = 0;
		       }
		   }
		 SDL_RenderPresent(renderer);
		 if (SDL_PollEvent(&event))
		   {
		     switch(event.type)
		       {
		       case SDL_QUIT:
			 quit = 1;
			 PauseFlag = 1;
			 for (int j = 0; j < EnemyList.size(); ++j) // Free the memory allocated for each enemy.
			   {
			     delete(EnemyList[j]);
			   }
			 break;
			 
		       case SDL_KEYDOWN:
			 if (event.key.keysym.sym == SDLK_p)
			   {
			     PauseFlag = 1;
			     break;
			   }

		       case SDL_MOUSEBUTTONUP:
			 if (*mousex >= 10 && *mousex <= 340 && *mousey >= 5 && *mousey <= 105)
			   {
			     TTF_CloseFont(ButtonFont);
			     SDL_FreeSurface(surfaceButton1);
			     SDL_FreeSurface(surfaceButton2);
			     SDL_DestroyTexture(Button1);
			     SDL_DestroyTexture(Button2);
			     SDL_DestroyTexture(PlayerShip); // Destroy the img-texture.
			     SDL_DestroyTexture(EnemyAlien);
			     return 1;
			   }
			 else if (*mousex >= 950 && *mousex <= 1070 && *mousey >= 5 && *mousey <= 105)
			   {
			     TTF_CloseFont(ButtonFont);
			     SDL_FreeSurface(surfaceButton1);
			     SDL_FreeSurface(surfaceButton2);
			     SDL_DestroyTexture(Button1);
			     SDL_DestroyTexture(Button2);
			     SDL_DestroyTexture(PlayerShip); // Destroy the img-texture.
			     SDL_DestroyTexture(EnemyAlien);
			     SDL_DestroyRenderer(renderer); // Destroy the rendering context for a window and free associated textures.
			     SDL_DestroyWindow(window); // This destroys the window
			     return 0;
			   }
		       }
		     if (PauseFlag == 1)
		       {
			 PauseFlag = 0;
			 break;
		       }
		   }
	       }
	   }
	 }
      }
  }
  TTF_CloseFont(ButtonFont);
  SDL_FreeSurface(surfaceButton1);
  SDL_FreeSurface(surfaceButton2);
  SDL_DestroyTexture(Button1);
  SDL_DestroyTexture(Button2);
  SDL_DestroyTexture(PlayerShip); // Destroy the img-texture.
  SDL_DestroyTexture(EnemyAlien);
  SDL_DestroyRenderer(renderer); // Destroy the rendering context for a window and free associated textures.
  SDL_DestroyWindow(window); // This destroys the window
  return 0;
}
