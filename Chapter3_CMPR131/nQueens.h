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
	void setDimension(const int&);
	string getDimension() const;
	//getters
	
	
	int getAmmountOfQueens() const;
	//functions
	
	

	void printBoard();

	void setQueen(const int&, const int&);
	void popQueen(const int&, const int&);

	bool isDanger(const int&, const int&);
	bool isWinning() const;
};

#endif