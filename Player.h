#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
 private:
  int Lives; // The amount of lives that the player has left.
  int Score; // The current score of the player.
  int Speed; // The speed of the spaceship of the player.
  std::string Name; // The name of the player.
 public:
  void Set_lives(int amnt);
  void Set_score(int sc);
  void Set_name(std::string nm);
  void Set_speed(int sp);
  void Reduce_lives();
  void Increase_score();
  int Give_lives();
  int Give_score();
  int Give_speed();
};
#endif
