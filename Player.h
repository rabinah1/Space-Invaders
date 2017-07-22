#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
 private:
  int Lives;
  int Score;
  std::string Name;
 public:
  void Print_lives();
  void Print_score();
  void Print_name();
  void Set_lives(int amnt);
  void Set_score(int sc);
  void Set_name(std::string nm);
};
#endif
