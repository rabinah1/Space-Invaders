#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Player.h"
#include <sstream>

std::vector <SDL_Rect*> InitEnemyList() // Create 50 enemies and add them to a vector
{
  std::vector <SDL_Rect*> List;
  SDL_Rect *Enemy1 = new SDL_Rect;
  SDL_Rect *Enemy2 = new SDL_Rect;
  SDL_Rect *Enemy3 = new SDL_Rect;
  SDL_Rect *Enemy4 = new SDL_Rect;
  SDL_Rect *Enemy5 = new SDL_Rect;
  SDL_Rect *Enemy6 = new SDL_Rect;
  SDL_Rect *Enemy7 = new SDL_Rect;
  SDL_Rect *Enemy8 = new SDL_Rect;
  SDL_Rect *Enemy9 = new SDL_Rect;
  SDL_Rect *Enemy10 = new SDL_Rect;
  SDL_Rect *Enemy11 = new SDL_Rect;
  SDL_Rect *Enemy12 = new SDL_Rect;
  SDL_Rect *Enemy13 = new SDL_Rect;
  SDL_Rect *Enemy14 = new SDL_Rect;
  SDL_Rect *Enemy15 = new SDL_Rect;
  SDL_Rect *Enemy16 = new SDL_Rect;
  SDL_Rect *Enemy17 = new SDL_Rect;
  SDL_Rect *Enemy18 = new SDL_Rect;
  SDL_Rect *Enemy19 = new SDL_Rect;
  SDL_Rect *Enemy20 = new SDL_Rect;
  SDL_Rect *Enemy21 = new SDL_Rect;
  SDL_Rect *Enemy22 = new SDL_Rect;
  SDL_Rect *Enemy23 = new SDL_Rect;
  SDL_Rect *Enemy24 = new SDL_Rect;
  SDL_Rect *Enemy25 = new SDL_Rect;
  SDL_Rect *Enemy26 = new SDL_Rect;
  SDL_Rect *Enemy27 = new SDL_Rect;
  SDL_Rect *Enemy28 = new SDL_Rect;
  SDL_Rect *Enemy29 = new SDL_Rect;
  SDL_Rect *Enemy30 = new SDL_Rect;
  SDL_Rect *Enemy31 = new SDL_Rect;
  SDL_Rect *Enemy32 = new SDL_Rect;
  SDL_Rect *Enemy33 = new SDL_Rect;
  SDL_Rect *Enemy34 = new SDL_Rect;
  SDL_Rect *Enemy35 = new SDL_Rect;
  SDL_Rect *Enemy36 = new SDL_Rect;
  SDL_Rect *Enemy37 = new SDL_Rect;
  SDL_Rect *Enemy38 = new SDL_Rect;
  SDL_Rect *Enemy39 = new SDL_Rect;
  SDL_Rect *Enemy40 = new SDL_Rect;
  SDL_Rect *Enemy41 = new SDL_Rect;
  SDL_Rect *Enemy42 = new SDL_Rect;
  SDL_Rect *Enemy43 = new SDL_Rect;
  SDL_Rect *Enemy44 = new SDL_Rect;
  SDL_Rect *Enemy45 = new SDL_Rect;
  SDL_Rect *Enemy46 = new SDL_Rect;
  SDL_Rect *Enemy47 = new SDL_Rect;
  SDL_Rect *Enemy48 = new SDL_Rect;
  SDL_Rect *Enemy49 = new SDL_Rect;
  SDL_Rect *Enemy50 = new SDL_Rect;
  List.push_back(Enemy1);
  List.push_back(Enemy2);
  List.push_back(Enemy3);
  List.push_back(Enemy4);
  List.push_back(Enemy5);
  List.push_back(Enemy6);
  List.push_back(Enemy7);
  List.push_back(Enemy8);
  List.push_back(Enemy9);
  List.push_back(Enemy10);
  List.push_back(Enemy11);
  List.push_back(Enemy12);
  List.push_back(Enemy13);
  List.push_back(Enemy14);
  List.push_back(Enemy15);
  List.push_back(Enemy16);
  List.push_back(Enemy17);
  List.push_back(Enemy18);
  List.push_back(Enemy19);
  List.push_back(Enemy20);
  List.push_back(Enemy21);
  List.push_back(Enemy22);
  List.push_back(Enemy23);
  List.push_back(Enemy24);
  List.push_back(Enemy25);
  List.push_back(Enemy26);
  List.push_back(Enemy27);
  List.push_back(Enemy28);
  List.push_back(Enemy29);
  List.push_back(Enemy30);
  List.push_back(Enemy31);
  List.push_back(Enemy32);
  List.push_back(Enemy33);
  List.push_back(Enemy34);
  List.push_back(Enemy35);
  List.push_back(Enemy36);
  List.push_back(Enemy37);
  List.push_back(Enemy38);
  List.push_back(Enemy39);
  List.push_back(Enemy40);
  List.push_back(Enemy41);
  List.push_back(Enemy42);
  List.push_back(Enemy43);
  List.push_back(Enemy44);
  List.push_back(Enemy45);
  List.push_back(Enemy46);
  List.push_back(Enemy47);
  List.push_back(Enemy48);
  List.push_back(Enemy49);
  List.push_back(Enemy50);
  return List;
}

int GameOverWindow(SDL_Event e, SDL_Window *w, SDL_Renderer *r, Player player_1) // We will enter this function when the player loses the game. This function will open a window that tells the player that the game has ended.
{
  int mousex_init = 0;
  int mousey_init = 0;
  int *mousex = &mousex_init; // X-coordinate of the mouse
  int *mousey = &mousey_init; // Y-coordinate of the mouse
  int quit = 0;
  TTF_Font *Font = TTF_OpenFont("Ubuntu-L.ttf", 80);
  std::stringstream score;
  score << player_1.Give_score();
  SDL_SetRenderDrawColor(r, 0,0,0,255); // Set the render draw color to black
  SDL_RenderClear(r);
  SDL_Color White = {255,255,255};
  SDL_Surface *surface1 = TTF_RenderText_Solid(Font, "Game over", White); // Create a surface that contains some text
  SDL_Surface *surface2 = TTF_RenderText_Solid(Font, "Your score:", White);
  SDL_Surface *surface3 = TTF_RenderText_Solid(Font, "Menu", White);
  SDL_Surface *surface4 = TTF_RenderText_Solid(Font, "Exit", White);
  SDL_Surface *surfaceScore = TTF_RenderText_Solid(Font, score.str().c_str(), White);
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(r, surface1); // Create texture from a surface
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(r, surface2);
  SDL_Texture *texture3 = SDL_CreateTextureFromSurface(r, surface3);
  SDL_Texture *texture4 = SDL_CreateTextureFromSurface(r, surface4);
  SDL_Texture *Score = SDL_CreateTextureFromSurface(r, surfaceScore);
  SDL_Rect Rect1; // Define rectangle
  SDL_Rect Rect2;
  SDL_Rect Rect3;
  SDL_Rect Rect4;
  SDL_Rect Rect5;
  Rect1.x = 350; // The x-coordinate of the top left corner of a rectangle
  Rect1.y = 170; // The y-coordinate of the top left corner of a rectangle
  Rect1.w = 400; // The width of a rectangle
  Rect1.h = 150; // The height of a rectangle
  Rect2.x = 290;
  Rect2.y = 350;
  Rect2.w = 400;
  Rect2.h = 150;
  Rect3.x = 710;
  Rect3.y = 350;
  Rect3.w = 140;
  Rect3.h = 150;
  Rect4.x = 80;
  Rect4.y = 620;
  Rect4.w = 200;
  Rect4.h = 150;
  Rect5.x = 825;
  Rect5.y = 620;
  Rect5.w = 200;
  Rect5.h = 150;
  SDL_RenderCopy(r, texture1, NULL, &Rect1); // Copy a texture on top of a rectangle
  SDL_RenderCopy(r, texture2, NULL, &Rect2);
  SDL_RenderCopy(r, Score, NULL, &Rect3);
  SDL_RenderCopy(r, texture3, NULL, &Rect4);
  SDL_RenderCopy(r, texture4, NULL, &Rect5);
  SDL_RenderPresent(r);
  while(quit == 0)
    {
      SDL_GetMouseState(mousex, mousey); // Get the x- and y-coordinates of the mouse
      if (SDL_PollEvent(&e)) // Poll for pending events
	{
	  switch(e.type)
	    {
	    case SDL_QUIT: // If the player clicks on the x-button on the top left corner of the screen
	      quit = 1;
	      break;

	    case SDL_MOUSEBUTTONDOWN:
	      if (*mousex >= 80 && *mousex <= 280 && *mousey >= 620 && *mousey <= 770) // If the player clicks on the menu-button on the screen
		{
		  // Free some surfaces and delete some textures
		  SDL_FreeSurface(surface1);
		  SDL_FreeSurface(surface2);
		  SDL_FreeSurface(surfaceScore);
		  SDL_FreeSurface(surface3);
		  SDL_FreeSurface(surface4);
		  SDL_DestroyTexture(texture1);
		  SDL_DestroyTexture(texture2);
		  SDL_DestroyTexture(Score);
		  SDL_DestroyTexture(texture3);
		  SDL_DestroyTexture(texture4);
		  TTF_CloseFont(Font);
		  return 0;
		}
	      else if (*mousex >= 825 && *mousex <= 1025 && *mousey >= 620 && *mousey <= 770) // If the player clicks on the exit-button on the screen
		{
		  SDL_FreeSurface(surface1);
		  SDL_FreeSurface(surface2);
		  SDL_FreeSurface(surfaceScore);
		  SDL_FreeSurface(surface3);
		  SDL_FreeSurface(surface4);
		  SDL_DestroyTexture(texture1);
		  SDL_DestroyTexture(texture2);
		  SDL_DestroyTexture(Score);
		  SDL_DestroyTexture(texture3);
		  SDL_DestroyTexture(texture4);
		  TTF_CloseFont(Font);
		  return 1;
		}
	    }
	}
    }
  SDL_FreeSurface(surface1);
  SDL_FreeSurface(surface2);
  SDL_FreeSurface(surfaceScore);
  SDL_FreeSurface(surface3);
  SDL_FreeSurface(surface4);
  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  SDL_DestroyTexture(Score);
  SDL_DestroyTexture(texture3);
  SDL_DestroyTexture(texture4);
  TTF_CloseFont(Font);
  return 1;
}

int GuideWindow(SDL_Event e, SDL_Window *w, SDL_Renderer *r) // We will enter this function if the player clicks on the controls-button on the menu-screen. This will open a window that tells the controls of the game
{
  int mousex_init = 0;
  int mousey_init = 0;
  int *mousex = &mousex_init;
  int *mousey = &mousey_init;
  int exit = 0;
  TTF_Font *Font = TTF_OpenFont("Ubuntu-L.ttf", 35);
  TTF_Font *Font2 = TTF_OpenFont("Ubuntu-L.ttf", 100);
  SDL_SetRenderDrawColor(r, 0,0,0,255);
  SDL_RenderClear(r);
  SDL_Color White = {255,255,255};
  // Create some surfaces and textures
  SDL_Surface *surface1 = TTF_RenderText_Solid(Font, "- Left arrow = Move left", White);
  SDL_Surface *surface2 = TTF_RenderText_Solid(Font, "- Right arrow = Move right", White);
  SDL_Surface *surface3 = TTF_RenderText_Solid(Font, "- Space = Shoot", White);
  SDL_Surface *surface4 = TTF_RenderText_Solid(Font, "- p = Pause", White);
  SDL_Surface *surface5 = TTF_RenderText_Solid(Font2, "Menu", White);
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(r, surface1);
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(r, surface2);
  SDL_Texture *texture3 = SDL_CreateTextureFromSurface(r, surface3);
  SDL_Texture *texture4 = SDL_CreateTextureFromSurface(r, surface4);
  SDL_Texture *texture5 = SDL_CreateTextureFromSurface(r, surface5);
  SDL_Rect Rect1;
  SDL_Rect Rect2;
  SDL_Rect Rect3;
  SDL_Rect Rect4;
  SDL_Rect Rect5;
  Rect1.x = 300;
  Rect1.y = 80;
  Rect1.w = 420;
  Rect1.h = 100;
  Rect2.x = 300;
  Rect2.y = 200;
  Rect2.w = 420;
  Rect2.h = 100;
  Rect3.x = 340;
  Rect3.y = 320;
  Rect3.w = 340;
  Rect3.h = 100;
  Rect4.x = 370;
  Rect4.y = 440;
  Rect4.w = 280;
  Rect4.h = 100;
  Rect5.x = 395;
  Rect5.y = 660;
  Rect5.w = 230;
  Rect5.h = 100;
  // Copy textures on top of rectangles
  SDL_RenderCopy(r, texture1, NULL, &Rect1);
  SDL_RenderCopy(r, texture2, NULL, &Rect2);
  SDL_RenderCopy(r, texture3, NULL, &Rect3);
  SDL_RenderCopy(r, texture4, NULL, &Rect4);
  SDL_RenderCopy(r, texture5, NULL, &Rect5);
  SDL_RenderPresent(r);
  while (exit == 0)
    {
      SDL_GetMouseState(mousex, mousey);
      if (SDL_PollEvent(&e))
	{
	  switch(e.type)
	    {
	    case SDL_QUIT: // If the user clicks on the x-button on the top left corner of the window
	      exit = 1;
	      break;
	    case SDL_MOUSEBUTTONDOWN:
	      if (*mousex >= 395 && *mousex <= 625 && *mousey >= 660 && *mousey <= 760) // If the player clicks on the menu-button shown on the screen
		{
		  exit = 1;
		  break;
		}
	    }
	}
    }
  SDL_FreeSurface(surface1);
  SDL_FreeSurface(surface2);
  SDL_FreeSurface(surface3);
  SDL_FreeSurface(surface4);
  SDL_FreeSurface(surface5);
  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  SDL_DestroyTexture(texture3);
  SDL_DestroyTexture(texture4);
  SDL_DestroyTexture(texture5);
  TTF_CloseFont(Font);
  TTF_CloseFont(Font2);
  return 0;
}
