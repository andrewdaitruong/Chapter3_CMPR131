#ifndef OPTION3_H
#define OPTION3_H
#include "board.h"
using namespace std;

typedef int pos;

class Option3
{
private:

	Board board;
	pos x = 0;
	pos y = 0;
	int count = 0;
	int gameAmount = 0;

public:

	//constructors
	Option3();
	Option3(int);

	//setters
	void setDimension(int);

	//getters
	string getDimension();
	int getCount();

	//functions
	bool diagonalCheck(pos, pos);
	bool columnCheck(pos);
	bool rowCheck(pos);
	void setPos(pos, pos);
	void printBoard();
	void pop(pos, pos);
	bool isWin();
	friend ostream& operator<<(ostream& out, Option3& option3);
};

#endif