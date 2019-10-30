/*class CFBoard and its testing code*/

#include <iostream>
#include <fstream>
#include <vector>

#include "CFGame.hpp"


using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::vector;


int main()
{
	ifstream fin("results.txt");
	vector<Player*> players;
	string name;
	int score;
	if (fin.is_open())
	{
		while (getline(fin, name))
		{
			fin >> score;
			players.push_back(new Player(name, score));
		}
		fin.close();
	}
	
	
	
	return 0;
}
