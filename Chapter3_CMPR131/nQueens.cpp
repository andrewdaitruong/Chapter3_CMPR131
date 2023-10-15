#include "nQueens.h"
#include "input.h"
#include <iostream>

using namespace std;

//precondition: need dimension size
//postcondition: prints the board and size
void nQueens::printBoard() 
{
	board.printBoard(mode);
}

//precondition: none
//postcondition: sets the dimension with only a single integer to make an even squared board
void nQueens::setDimension(int size)
{
	board.setSize(size);
	x = 0;
	y = 0;
	mode = false;
}

//precondition: none
//postcondition: size originally at 0
nQueens::nQueens()
{
	board.setSize(0);
	x = 0;
	y = 0;
	mode = false;
}

//precondition: none
//postcondition: size;
nQueens::nQueens(int size)
{
	board.setSize(size);
}

//precondition: number must be above 0
//postcondition: returns dimension to get a perfect square
string nQueens::getDimension()
{
	string dimension;
	dimension = board.getSize() + " x " + board.getSize();
	return dimension;
}

//precondition: board must be above 0
//postcondition: puts a piece on the board
void nQueens::setQueen(int x, int y)
{
	if (x >= board.getSize() || y >= board.getSize())
	{
		cout << "Invalid position" << endl;
		return;
	}
	else if (isDanger(x,y))
	{
		cout << "\n\t Couldnt place queen at position (" << x + 1 << "," << y + 1 << ").\n\t Queen is in danger!" << endl;
	
	}
	else
	{
		x = x;
		y = y;
		board.setQueen(x, y);
		cout << "\n\t Queen placed at position (" << x + 1 << "," << y + 1 << ")" << endl;
	
	}
}
void nQueens::setX(const int& x)
{
	this->x = x;
}
void nQueens::setY(const int& y)
{
	this->y = y;
}
int nQueens::getX()
{
	return x;
}
int nQueens::getY()
{
	return y;
}
//precondition: pieces should be on the board
//postcondition: removes a piece of the board
void nQueens::popQueen(int x, int y)
{
	if (board.searchForCoordinate(x, y))
	{
		board.popQueen(x, y);
	
	}
	else
		cout << "\n\t Queen does not exist at position (" << x + 1 << "," << y + 1 << ")" << endl;
}

//precondition: none
//postcondition: checks if the game has been won by matching the size with the amount of pieces
bool nQueens::isWin()
{
	if (board.getCoordSize() == board.getSize())
		return true;
	else 
		return false;
}

bool nQueens::isDanger(int x, int y)
{
	if (board.isInDangerZone(x, y))
		return true;
	else
		return false;
}

void nQueens::setMode(bool mode)
{
	this->mode = mode;
}

