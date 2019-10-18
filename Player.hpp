#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
protected:
	int ID;
	std::string name;
	int score;
public:
	Player(int id, std::string playerName);
	int getID() const;
	std::string getName() const;
	void setScore(int n);
	int getScore() const;
	virtual void printPlayer() const = 0;
};


class BronzePlayer : public Player
{
public:
	BronzePlayer(std::string);
	virtual void printPlayer() const;
};

class SilverPlayer : public Player
{
public:
	SilverPlayer(std::string);
	virtual void printPlayer() const;
};

class GoldPlayer : public Player
{
public:
	GoldPlayer(std::string);
	virtual void printPlayer() const;
};

#endif