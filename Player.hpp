#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

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

#endif