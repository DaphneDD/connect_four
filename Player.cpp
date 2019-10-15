#include "Player.hpp"
#include <iostream>

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

void BronzePlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tBronze Player" << endl;
}

void SilverPlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tSilver Player" << endl;
}