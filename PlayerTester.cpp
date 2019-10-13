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
	
	cout << "Please enter the name of Player 2: ";
	string p2name;
	getline(cin, p2name);
	Player p2(p2name);
	cout << "After initialization, Player 2 " << p2.getName() <<"'s score is " << p2.getScore() << endl;
	p2.setScore(15);
	cout << "After setting the score to 15, " << p2.getName() <<"'s new score is " << p2.getScore() << endl;
	
	cout << "\nUsing getline(), the chars of Player 2's name are:" << endl;
	for (int i=0; i<p2name.length(); i++)
		cout << p2name[i] << ' ';
	cout << endl;
	return 0;
}