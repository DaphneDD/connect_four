/*class CFBoard and its testing code*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "CFGame.hpp"


using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;


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
			if (score < 20)
				players.push_back(new BronzePlayer(name, score));
			else if (score < 40)
				players.push_back(new SilverPlayer(name, score));
			else
				players.push_back(new GoldPlayer(name, score));
		}
		fin.close();
	}
	else
	{
		cout << "Fail to open results.txt to read " << endl;
	}
	Player *p1 = nullptr, *p2 = nullptr;
	cout << "--------- Connect Four -------------" << endl;
	cout << "Please Enter Player1's Name: " << endl;
	getline(cin, name);
	for (Player* p : players)
	{
		if (p->getName() == name)
		{
			p1 = p;
			break;
		}
	}
	if (!p1)
	{
		p1 = new BronzePlayer(name);
		players.push_back(p1);
	}
	cout << "Please enter Player2's Name: " << endl;
	getline(cin, name);
	for (Player* p : players)
	{
		if (p->getName() == name)
		{
			p2 = p;
			break;
		}
	}
	if (!p2)
	{
		p2 = new BronzePlayer(name);
		players.push_back(p2);
	}
	
	CFGame game(p1, p2);
	game.play();
	
	cout << "\n\nCurrent results:" << endl;
	for (Player* p : players)
		p->printPlayer();
	
	ofstream fout("results.txt");
	if (fout.is_open())
	{
		for (Player* p : players)
		{
			fout << p->getName() << endl;
			fout << p->getScore() << endl;
		}
		fout.close();
	}
	else
	{
		cout << "Failed to open results.txt to write" << endl;
	}
		
	for (Player* p : players)
		delete p;	
	
	return 0;
}
