#ifndef CFGAME_HPP
#define CFGAME_HPP

#include "Player.hpp"
#include "CFBoard.hpp"

class CFGame
{
private:
	CFBoard board;
	Player* player1;
	Player* player2;
	int _getColNumber();
public:
	CFGame(Player*, Player*);
	void play();
};


#endif
