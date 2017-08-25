#include "Player.h"
#include "Functions.h"
#include <iostream>
#include <string>

// This file contains the definitions of the functions that the class Player has.

void Player::Set_lives(int amnt) // Set the amount of lives of the player to be amnt.
{
  Lives = amnt;
}

void Player::Set_score(int sc) // Set the score of the player to be sc.
{
  Score = sc;
}

int Player::Give_lives() // Return the amount of lives of the player.
{
  return Lives;
}

int Player::Give_score() // Return the score of the player.
{
  return Score;
}

void Player::Reduce_lives()
{
  Lives = Lives - 1;
}

void Player::Increase_score()
{
  Score = Score + 50;
}
