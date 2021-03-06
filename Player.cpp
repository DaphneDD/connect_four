#include "Player.hpp"
#include <iostream>

Player::Player(std::string playerName, int s)
{
	name = playerName;
	score = s;
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


BronzePlayer::BronzePlayer(std::string playerName, int s)
:Player(playerName, s) {}

void BronzePlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tBronze Player" << std::endl;
}

SilverPlayer::SilverPlayer(std::string playerName,int s)
:Player(playerName, s) {}

void SilverPlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tSilver Player" << std::endl;
}

GoldPlayer::GoldPlayer(std::string playerName, int s)
:Player(playerName, s) {}

void GoldPlayer::printPlayer() const
{
	std::cout << getName() << '\t' << getScore() << "\tSilver Player" << std::endl;
}
