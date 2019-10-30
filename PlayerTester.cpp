#include <iostream>
#include <string>
#include "Player.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	Player *pps[3];
	pps[0] = new BronzePlayer("Bronze");
	pps[1] = new SilverPlayer("Silver");
	pps[2] = new GoldPlayer("Gold");
	
	pps[0]->setScore(10);
	cout << "Player 1 name is " << pps[0]->getName() << " and score is " << pps[0]->getScore();
	cout << endl;
	pps[0]->printPlayer();
	pps[1]->printPlayer();
	pps[2]->printPlayer();
	for (int i=0; i<3; i++)
		delete pps[i];
	return 0;
}