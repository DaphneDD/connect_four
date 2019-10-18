/********************************************************************
**Author: Xiaoqiong Dong
**Date: June 3, 2018
**Description: This is the class CFBoard implementation file.
*********************************************************************/

#include <iostream>
#include "CFBoard.hpp"


/**************************************************************************************
**                             Default Constructor
**Initialize all elements of the array to being empty. '.' represents the square is empty.
**6 rows with indices 0 - 5 from top to bottom. 7 columns with indices 0 - 6 from left 
**to right
***************************************************************************************/
CFBoard::CFBoard()
{
	//Initialize the board
	board = new char*[6];
	for (int i=0; i<6; i++)
		board[i] = new char[7];
	for (int i=0; i<6; i++)
	{
		for (int j=0; j<7; j++)
			board[i][j] = '.';
	}
	
	//initialize gameState to UNFINISHED
	gameState = UNFINISHED;
}

/**************************************************************************************
**                             makeMove()
**It takes the column of the move and the player as the parameters. It returns false if 
**the game is finished or that particular column is full. Otherwise, it records the move
**and update the gameState. 
***************************************************************************************/
bool CFBoard::makeMove(int column, char player)
{
	column--; //Column is 1-7, and the index is 0-6.
	//If the game is finished or the column is full, return false 
	if (gameState != UNFINISHED || board[0][column] != '.')
		return false;
	
	//Record the move.
	//Find the first available square in the column passed as a parameter
	//Then set char of that square to be player. 
	int row = 5;
	while(board[row][column] != '.')
		row--;
	board[row][column] = player;
	updateGameState(row, column);
	return true;
}

/**************************************************************************************
**                             updateGameState()
**It takes the array indices as the parameter. If either player has four pieces connected,
**the game has been won. If the board is full but nobody won, then the gameState is draw.
***************************************************************************************/
void CFBoard::updateGameState(int row, int column)
{
	char player = board[row][column];
	int r = row, c = column;    //array indices used later to traverses row, column, or diagonal
		
	//Check if there are four pieces connected in a row
	int rCount = 1;   //count of the connected pieces in a row.
	while (c-1 >= 0 && board[r][c-1] == player)
		c--;
	while (c+1 <= 6 && board[r][c+1] == player)
	{
		rCount++;
		c++;
	}
	
	//Check if there are four pieces connected in a column
	r = row; 
	c = column;
	int cCount = 1;  //count of the connected pieces in a column
	if (r <= 2) //This is the lowest row that can have another three pieces underneath it
	{
		while (r+1 <= 5 && board[r+1][c] == player)
		{
			cCount++;
			r++;
		}
	}
	
	//Check if there are four pieces connected in bottom left to top right diagonal
	r = row; 
	c = column;
	int dCount1 = 1;  //count of the connected pieces in a diagonal
	while (r+1 <= 5 && c-1 >=0 && board[r+1][c-1] == player)
	{
		r++;
		c--;
	}
	while (r-1 >= 0 && c+1 <= 6 && board[r-1][c+1] == player)
	{
		r--;
		c++;
		dCount1++;
	}
	
	//Check if there are four pieces connected in bottom right to top left diagonal
	r = row; 
	c = column;
	int dCount2 = 1;  //count of the connected pieces in a diagonal
	while (r+1 <= 5 && c+1 <= 6 && board[r+1][c+1] == player)
	{
		r++;
		c++;
	}
	while (r-1 >= 0 && c-1 >= 0 && board[r-1][c-1] == player)
	{
		r--;
		c--;
		dCount2++;
	}
	
	//check if the board is full
	bool full = board[0][0] != '.';
	for (int i=1; i<=6; i++)
		full = full && (board[0][i] != '.');
	
	if (rCount == 4 || cCount == 4 || dCount1 == 4 || dCount2 == 4)
	{
		switch (player)
		{
			case 'x' : gameState = X_WON;
						break;
			case 'o' : gameState = O_WON;
						break;
		}
	}
	else if (full)
		gameState = DRAW;
}

/**************************************************************************************
**                             getGameState()
**return gameState
***************************************************************************************/
State CFBoard::getGameState()
{
	return gameState;
}

/**************************************************************************************
**                             print()
**print the current board
***************************************************************************************/
void CFBoard::print()
{
	for (int i=0; i<6; i++)
	{
		for (int j=0; j<7; j++)
			std::cout<< ' '<< board[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
