#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <vector>

std::vector <SDL_Rect*> InitEnemyList();
int GuideWindow(SDL_Event e, SDL_Window *w, SDL_Renderer *r);

#endif
