#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "SDL.h"
#include "Player.h"
#include <vector>

std::vector <SDL_Rect*> InitEnemyList();
int GuideWindow(SDL_Event e, SDL_Window *w, SDL_Renderer *r);
int GameOverWindow(SDL_Event e, SDL_Window *w, SDL_Renderer *r, Player player_1);

#endif
