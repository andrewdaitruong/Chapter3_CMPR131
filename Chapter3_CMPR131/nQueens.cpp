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
//postcondition: set size of board to initialize;
nQueens::nQueens(int size)
{
	board.setSize(size);
}


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
int nQueens::getMoveCount()
{
	return count;
}



//precondition: board must be above 0
//postcondition: puts a piece on the board
void nQueens::setPosition(pos x, pos y)
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
		board.setPosition(x, y);
		cout << "\n\t Queen placed at position (" << x + 1 << "," << y + 1 << ")" << endl;
		count++;
	}
}

//precondition: pieces should be on the board
//postcondition: removes a piece of the board
void nQueens::popPosition(pos x, pos y)
{
	if (board.checkBlock(x, y))
	{
		board.popPosition(x, y);
		count++;
	}
	else
		cout << "\n\t Queen does not exist at position (" << x + 1 << "," << y + 1 << ")" << endl;
}

//precondition: none
//postcondition: checks the diagnol for obstruction
bool nQueens::diagonalCheck(pos x, pos y)
{
	for (int i = 1; i <= board.getSize(); i++)
	{
		if (board.checkBlock(x - i, y - i) || board.checkBlock(x + i, y - i) || board.checkBlock(x - i, y + i) || board.checkBlock(x + i, y + i))
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
		if (board.checkBlock(x, i))
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
		if (board.checkBlock(i, y))
			return true;
	}
	return false;
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