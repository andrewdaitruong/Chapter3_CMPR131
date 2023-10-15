#include "nQueens.h"
#include "input.h"
#include <iostream>

using namespace std;

//precondition: none
//postcondition: size originally at 0
nQueens::nQueens()
{
	board.setSize(0);
}

//precondition: none
//postcondition: size;
nQueens::nQueens(int size)
{
	board.setSize(size);
}

//precondition: none
//postcondition: sets the dimension with only a single integer to make an even squared board
void nQueens::setDimension(int size)
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

//precondition: none
//postcondition: returns move count
int nQueens::getCount()
{
	return count;
}

//precondition: none
//postcondition: returns CoordSize from board class to represent the amount of queens
int nQueens::getQueenAmount() 
{ 
	return board.getCoordSize(); 
}

//precondition: board must be above 0
//postcondition: puts a piece on the board
void nQueens::setQueen(pos x, pos y)
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
		count++;
	}
}

//precondition: pieces should be on the board
//postcondition: removes a piece of the board
void nQueens::popQueen(pos x, pos y)
{
	if (board.searchForCoordinate(x, y))
	{
		board.popQueen(x, y);
		count++;
	}
	else
		cout << "\n\t Queen does not exist at position (" << x + 1 << "," << y + 1 << ")" << endl;
}

//precondition: need dimension size
//postcondition: prints the board and size
void nQueens::printBoard()
{
	board.printBoard(mode);
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

//precondition: at least one piece should be on the board
//postcondition: checks if queen contradicts with other queens
bool nQueens::isDanger(pos x, pos y)
{
	if (board.isInDangerZone(x, y))
		return true;
	else
		return false;
}

//precondition: none
//postcondition: shows the danger zone for where the queen contradicts
void nQueens::setMode(bool mode)
{
	this->mode = mode;
}

