#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
protected:
	std::string name;
	int score;
public:
	Player(std::string playerName);
	std::string getName() const;
	void setScore(int n);
	int getScore() const;
	virtual void printPlayer() const = 0;
};


class BronzePlayer : public Player
{
public:
	virtual void printPlayer() const;
}

class SilverPlayer : public Player
{
public:
	virtual void printPlayer() const;
}

class GoldPlayer : public Player
{
public:
	virtual void printPlayer() const;
}

#endif