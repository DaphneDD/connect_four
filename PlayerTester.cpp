#include <iostream>
#include <string>
#include "Player.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	Player p1("Alice");
	cout << "After initialization, Player 1 " << p1.getName() <<"'s score is " << p1.getScore() << endl;
	p1.setScore(10);
	cout << "After setting the score to 10, " << p1.getName() <<"'s new score is " << p1.getScore() << endl;
	
	return 0;
}