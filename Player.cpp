#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>

void Player::Set_lives(int amnt) // Set the amount of lives of the player to be amnt.
{
  Lives = amnt;
}

void Player::Set_score(int sc) // Set the score of the player to be sc.
{
  Score = sc;
}

void Player::Set_name(std::string nm) // Set the name of the player to be nm.
{
  Name = nm;
}

void Player::Set_speed(int sp) // Set the speed of the player to be sp.
{
  Speed = sp;
}

int Player::Give_lives() // Return the amount of lives of the player.
{
  return Lives;
}

int Player::Give_score() // Return the score of the player.
{
  return Score;
}

int Player::Give_speed() // Return the speed of the player.
{
  return Speed;
}
