#ifndef NQUEENS
#define NQUEENS_H
#include "board.h"
using namespace std;

typedef int pos;

class nQueens
{
private:

	Board board;
	pos x = 0;
	pos y = 0;
	int count = 0;
	int gameAmount = 0;

public:

	//constructors
	nQueens();
	nQueens(int);

	//setters
	void setDimension(int);

	//getters
	string getDimension();
	int getMoveCount();

	//functions
	bool diagonalCheck(pos, pos);
	bool columnCheck(pos);
	bool rowCheck(pos);
	void setPosition(pos, pos);
	void printBoard();
	void popPosition(pos, pos);
	bool isWin();
	friend ostream& operator<<(ostream& out, nQueens& option3);
};

#endif