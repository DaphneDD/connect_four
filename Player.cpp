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


BronzePlayer::BronzePlayer(std::string playerName)
:Player(playerName) {}

void BronzePlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tBronze Player" << std::endl;
}

SilverPlayer::SilverPlayer(std::string playerName)
:Player(playerName) {}

void SilverPlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tSilver Player" << std::endl;
}

GoldPlayer::GoldPlayer(std::string playerName)
:Player(playerName) {}

void GoldPlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tSilver Player" << std::endl;
}
