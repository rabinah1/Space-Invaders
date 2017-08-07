#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

std::vector <SDL_Rect*> InitEnemyList()
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


int GuideWindow(SDL_Event e, SDL_Window *w, SDL_Renderer *r)
{
  int exit = 0;
  TTF_Font *Font = TTF_OpenFont("Ubuntu-L.ttf", 35);
  SDL_SetRenderDrawColor(r, 0,0,0,255);
  SDL_RenderClear(r);
  SDL_Color White = {255,255,255};
  SDL_Surface *surface1 = TTF_RenderText_Solid(Font, "- Left arrow = Move left", White);
  SDL_Surface *surface2 = TTF_RenderText_Solid(Font, "- Right arrow = Move right", White);
  SDL_Surface *surface3 = TTF_RenderText_Solid(Font, "- Space = Shoot", White);
  SDL_Surface *surface4 = TTF_RenderText_Solid(Font, "- Pause = p", White);
  SDL_Texture *texture1 = SDL_CreateTextureFromSurface(r, surface1);
  SDL_Texture *texture2 = SDL_CreateTextureFromSurface(r, surface2);
  SDL_Texture *texture3 = SDL_CreateTextureFromSurface(r, surface3);
  SDL_Texture *texture4 = SDL_CreateTextureFromSurface(r, surface4);
  SDL_Rect Rect1;
  SDL_Rect Rect2;
  SDL_Rect Rect3;
  SDL_Rect Rect4;
  Rect1.x = 300;
  Rect1.y = 180;
  Rect1.w = 420;
  Rect1.h = 100;
  Rect2.x = 300;
  Rect2.y = 300;
  Rect2.w = 420;
  Rect2.h = 100;
  Rect3.x = 340;
  Rect3.y = 420;
  Rect3.w = 340;
  Rect3.h = 100;
  Rect4.x = 370;
  Rect4.y = 540;
  Rect4.w = 280;
  Rect4.h = 100;
  SDL_RenderCopy(r, texture1, NULL, &Rect1);
  SDL_RenderCopy(r, texture2, NULL, &Rect2);
  SDL_RenderCopy(r, texture3, NULL, &Rect3);
  SDL_RenderCopy(r, texture4, NULL, &Rect4);
  SDL_RenderPresent(r);
  while (exit == 0)
    {
      if (SDL_PollEvent(&e))
	{
	  switch(e.type)
	    {
	    case SDL_QUIT:
	      exit = 1;
	      break;
	    }
	}
    }
  SDL_FreeSurface(surface1);
  SDL_FreeSurface(surface2);
  SDL_FreeSurface(surface3);
  SDL_FreeSurface(surface4);
  SDL_DestroyTexture(texture1);
  SDL_DestroyTexture(texture2);
  SDL_DestroyTexture(texture3);
  SDL_DestroyTexture(texture4);
  TTF_CloseFont(Font);
  return 0;
}
