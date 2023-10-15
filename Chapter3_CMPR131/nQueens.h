#ifndef NQUEENS_H
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
	bool mode = false;

public:

	//constructors
	nQueens();
	nQueens(int);

	//setters
	void setDimension(int);

	//getters
	string getDimension();
	int getCount();
	int getQueenAmount();

	//functions
	void setMode(bool);
	void printBoard();

	void setQueen(pos, pos);
	void popQueen(pos, pos);

	bool isDanger(pos, pos);
	bool isWin();
};

#endif