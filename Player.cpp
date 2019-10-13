#include "Player.hpp"


Player::Player(std::string playerName)
{
	name = playerName;
	score = 0;
}

std::string Player::getName() const
{
	return name;
}

void Player::setScore(int n)
{
	score = n;
}

int Player::getScore() const
{
	return score;
}