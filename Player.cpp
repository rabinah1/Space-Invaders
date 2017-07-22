#include "Player.h"
#include <iostream>
#include <string>

void Player::Print_lives()
{
  std::cout << Lives << "\n";
}

void Player::Print_score()
{
  std::cout << Score << "\n";
}

void Player::Print_name()
{
  std::cout << Name << "\n";
}

void Player::Set_lives(int amnt)
{
  Lives = amnt;
}

void Player::Set_score(int sc)
{
  Score = sc;
}

void Player::Set_name(std::string nm)
{
  Name = nm;
}
