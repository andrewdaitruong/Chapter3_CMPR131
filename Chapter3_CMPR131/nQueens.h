#ifndef NQUEENS_H
#define NQUEENS_H
#include "board.h"
using namespace std;



class nQueens
{
private:
	Board board;

public:
	//constructors
	nQueens();
	nQueens(int);

	//setters
	void setQueen(const int&, const int&);
	void setDimension(const int&);
	//getters
	
	string getDimension() const;
	int getAmmountOfQueen() const;
	//functions

	
	bool isDanger(const int&, const int&);
	void popQueen(const int&, const int&);
	bool isWinning() const;
	void printBoard();
};

#endif