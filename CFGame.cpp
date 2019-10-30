#include "CFGame.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

CFGame::CFGame(Player* p1ptr, Player* p2ptr)
:board()
{
	player1 = p1ptr;
	player2 = p2ptr;
}

int CFGame::_getColNumber()
{
	int colNo;
	cout << "Please enter a column number (1 - 7):\t";
	cin >> colNo;
	while (colNo < 1 || colNo > 7)
	{
		cout << "Please enter a valid column number (1 - 7):\t";
		cin >> colNo;
	}
	return colNo;
}


void CFGame::play()
{
	board.print();
	int col;
	
	do
	{
		cout << player1->getName() <<"'s turn. ";
		col = _getColNumber();
		while (! board.makeMove(col, 'x'))
			col = _getColNumber();
		board.print();
		
		if (board.getGameState() != UNFINISHED)
			break;
		
		cout << player2->getName() << "'s turn. ";
		col = _getColNumber();
		while (! board.makeMove(col, 'o'))
			col = _getColNumber();
		board.print();
		if (board.getGameState() != UNFINISHED)
			break;
	} while (true);
	
	State result = board.getGameState();
	switch (result)
	{
		case X_WON: 
			cout << player1->getName() << " WON!" << endl; 
			player1->setScore(player1->getScore() + 2);
			break;
		case O_WON: 
			cout << player2->getName() << " WON!" << endl;
			player2->setScore(player2->getScore() + 2);
			break;
		case DRAW: 
			cout << "DRAW!" << endl; 
			player1->setScore(player1->getScore() + 1);
			player2->setScore(player2->getScore() + 1);
			break;
		case UNFINISHED: 
			cout << "UNFINISHED" << endl; 
			break;
		default: cout << "How could this happen?" << endl;
	}
	
}