#include "Player.hpp"
class Player
{
private:
	std::string name;
	int score;
public:
	Player(std::string playerName);
	std::string getName() const;
	void setScore(int n);
	int getScore() const;
};

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