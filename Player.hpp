#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
protected:
	std::string name;
	int score;
public:
	Player(std::string playerName, int s = 0);
	std::string getName() const;
	void setScore(int n);
	int getScore() const;
	virtual void printPlayer() const = 0;
};


class BronzePlayer : public Player
{
public:
	BronzePlayer(std::string, int s = 0);
	virtual void printPlayer() const;
};

class SilverPlayer : public Player
{
public:
	SilverPlayer(std::string, int s = 0);
	virtual void printPlayer() const;
};

class GoldPlayer : public Player
{
public:
	GoldPlayer(std::string, int s = 0);
	virtual void printPlayer() const;
};

#endif