#ifndef PLAYER_H
#define PLAYER_H

// Definition of the class "Player"
class Player {
 private:
  int Lives; // The amount of lives that the player has left.
  int Score; // The current score of the player.
 public:
  // These functions can be found in the file "Player.cpp"
  void Set_lives(int amnt);
  void Set_score(int sc);
  void Reduce_lives();
  void Increase_lives();
  void Increase_score();
  int Give_lives();
  int Give_score();
};
#endif
