#include <vector>
#include "SDL.h"

std::vector <SDL_Rect*> InitEnemyList()
{
  std::vector <SDL_Rect*> List;
  SDL_Rect *Enemy1 = new SDL_Rect;
  SDL_Rect *Enemy2 = new SDL_Rect;
  SDL_Rect *Enemy3 = new SDL_Rect;
  SDL_Rect *Enemy4 = new SDL_Rect;
  List.push_back(Enemy1);
  List.push_back(Enemy2);
  List.push_back(Enemy3);
  List.push_back(Enemy4);
  return List;
}
