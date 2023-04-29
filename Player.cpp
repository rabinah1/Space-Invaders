#include "config.h"
#include "Player.h"
#include "Functions.h"

void Player::Set_lives(int amnt)
{
    Lives = amnt;
}

void Player::Set_score(int sc)
{
    Score = sc;
}

int Player::Give_lives()
{
    return Lives;
}

int Player::Give_score()
{
    return Score;
}

void Player::Reduce_lives()
{
    Lives = Lives - 1;
}

void Player::Increase_lives()
{
    Lives = Lives + 1;
}

void Player::Increase_score()
{
    Score = Score + 50;
}
