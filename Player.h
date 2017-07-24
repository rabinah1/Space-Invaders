#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
 private:
  int Lives;
  int Score;
  int Speed;
  std::string Name;
 public:
  void Set_lives(int amnt);
  void Set_score(int sc);
  void Set_name(std::string nm);
  void Set_speed(int sp);
  int Give_lives();
  int Give_score();
  int Give_speed();
};
#endif
