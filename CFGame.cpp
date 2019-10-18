#include "CFGame.hpp"
#include <iostream>

using std::cout;
using std::endl;

class CFGame
{
private:
	CFBoard board;
	Player* player1;
	Player* player2;
public:
	CFGame(Player*, Player*);
	void play();
};

CFGame::CFGame(Player* p1ptr, Player* p2ptr)
:board()
{
	player1 = p1ptr;
	player2 = p1ptr;
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
		if (round1.makeMove(col, 'x'))
		{
			round1.print();
			cout << endl << endl;
		}
		if (round1.getGameState() != UNFINISHED)
			break;
		
		cout << "o's turn. Please enter a column (1-7):\t";
		cin >> col;
		cin.get();
		if (col < 1 || col > 7)
			break;
		if (round1.makeMove(col, 'o'))
		{
			round1.print();
			cout << endl << endl;
		}
		if (round1.getGameState() != UNFINISHED)
			break;
	} while (true);
	
	State result = round1.getGameState();
	switch (result)
	{
		case X_WON: cout << "X WON!" << endl; break;
		case O_WON: cout << "O WON!" << endl; break;
		case DRAW: cout << "DRAW!" << endl; break;
		case UNFINISHED: cout << "UNFINISHED" << endl; break;
		default: cout << "How could this happen?" << endl;
	}
	
}