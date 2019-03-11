/*********************************************************************************
**Name: Xiaoqiong Dong
**Date: June 3, 2018
**Description: header file of the class CFBoard. It represents a game board for 
**playing Connect Four. It has a char double pointer pointing to a 2D array to store
**the location of the player's pieces. It also has a variable called gameState which 
**if enum type State define in this file. The default constructor builds a board. The
**makeMove() record a move of a player. the updateGameState() is used internally to
**update the game state. getGameState() returns the state of the game. It also has a 
**pring() to print the current board.  
*************************************************************************************/


#ifndef CFBOARD_HPP
#define CFBOARD_HPP

enum State {X_WON, O_WON, DRAW, UNFINISHED};

class CFBoard
{
private:
	char **board;
	State gameState;
public:
	CFBoard();
	bool makeMove(int, char);
	void updateGameState(int, int);
	State getGameState();
	void print();
};

#endif