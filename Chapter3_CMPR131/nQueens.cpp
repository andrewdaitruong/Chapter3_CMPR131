#include "nQueens.h"
#include "input.h"
#include <iostream>

using namespace std;

//precondition: need dimension size
//postcondition: prints the board and size
void nQueens::printBoard() 
{
	board.printBoard();
}

//precondition: none
//postcondition: sets the dimension with only a single integer to make an even squared board
void nQueens::setDimension(int size)
{
	board.setSize(size);
}

//precondition: none
//postcondition: returns move count
int nQueens::getCount()
{
	return count;
}

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

//precondition: number must be above 0
//postcondition: returns dimension to get a perfect square
string nQueens::getDimension()
{
	string dimension;
	dimension = board.getSize() + " x " + board.getSize();
	return dimension;
}

//precondition: none
//postcondition: checks the diagnol for obstruction
bool nQueens::diagonalCheck(pos x, pos y)
{
	for (int i = 1; i <= board.getSize(); i++)
	{
		if (board.checkMate(x - i, y - i) || board.checkMate(x + i, y - i) || board.checkMate(x - i, y + i) || board.checkMate(x + i, y + i))
			return true;
	}
	return false;
		
}

//precondition: none
//postcondition: checks the column for obstruction
bool nQueens::columnCheck(pos x)
{
	for (int i = 0; i < board.getSize(); i++)
	{
		if (board.checkMate(x, i))
			return true;
	}
	return false;
}

//precondition: none
//postcondition: checks the row for obstruction
bool nQueens::rowCheck(pos y)
{
	for (int i = 0; i < board.getSize(); i++)
	{
		if (board.checkMate(i, y))
			return true;
	}
	return false;
}

//precondition: board must be above 0
//postcondition: puts a piece on the board
void nQueens::setPos(pos x, pos y)
{
	if (x >= board.getSize() || y >= board.getSize())
	{
		cout << "Invalid position" << endl;
		return;
	}
	else if (columnCheck(x))
	{
		cout << "\n\t Couldnt place queen at position (" << x + 1 << "," << y + 1 << ")\n\t Queen is in danger" << endl;
	}
	else if (rowCheck(y))
	{
		cout << "\n\t Couldnt place queen at position (" << x + 1 << "," << y + 1 << ")\n\t Queen is in danger" << endl;
	}
	else if (diagonalCheck(x, y))
	{
		cout << "\n\t Couldnt place queen at position (" << x + 1 << "," << y + 1 << ")\n\t Queen is in danger" << endl;
	}
	else
	{
		x = x;
		y = y;
		board.setPos(x, y);
		cout << "\n\t Queen placed at position (" << x + 1 << "," << y + 1 << ")" << endl;
		count++;
	}
}

//precondition: none
//postcondition: checks if the game has been won by matching the size with the amount of pieces
bool nQueens::isWin()
{
	if (board.getCoordSize() == board.getSize())
		return true;
	else return false;
}

//precondition: pieces should be on the board
//postcondition: removes a piece of the board
void nQueens::pop(pos x, pos y)
{
	if (board.checkMate(x, y))
	{
		board.pop(x, y);
		count++;
	}
	else
		cout << "\n\t Queen does not exist at position (" << x + 1 << "," << y + 1 << ")" << endl;
}