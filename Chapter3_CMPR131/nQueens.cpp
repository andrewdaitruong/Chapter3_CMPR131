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

//precondition: valid integer size
//postcondition: sets the dimension with only a single integer to make an even squared board
void nQueens::setDimension(const int& size)
{
	board.setSize(size);

}

//precondition: none
//postcondition: size originally at 0
nQueens::nQueens()
{
	board.setSize(0);

}

//precondition: valid integer size
//postcondition: set the size of the board to the integer size
nQueens::nQueens(int size)
{
	board.setSize(size);
}

//precondition: none
//postcondition: returns the dimension size x size in a string
string nQueens::getDimension()const
{
	string dimension;
	dimension = board.getSize() + " x " + board.getSize();
	return dimension;
}

//precondition: A valid column X and a valid row Y
//postcondition: it perform condition check to see if the queen is in danger, X and Y out side of the board. If not, it will place the queen
void nQueens::setQueen(const int& x, const int& y)
{
	if (x >= board.getSize() || y >= board.getSize())
	{
		cout << "Invalid position" << endl;
		return;
	}
	else if (x < 0 || y < 0)
	{
		cout << "Invalid position" << endl;
		return;
	}
	else if (isDanger(x, y))
	{
		cout << "\n\t Couldnt place queen at position (" << x + 1 << "," << y + 1 << ").\n\t Queen is in danger!" << endl;
	}
	else
	{
		board.setQueen(x, y);
		cout << "\n\t Queen placed at position (" << x + 1 << "," << y + 1 << ")" << endl;
	}
}

//precondition: A valid column X and a valid row Y
//postcondition: removes the position of the queen from the board if detected
void nQueens::popQueen(const int& x, const int& y)
{
	if (board.searchForCoordinate(x, y))
	{
		board.popQueen(x, y);
	}
	else
		cout << "\n\t Queen does not exist at position (" << x + 1 << "," << y + 1 << ")" << endl;
}

//precondition: none
//postcondition: checks if the game has been won by matching the size with the amount of queens
bool nQueens::isWinning() const
{
	if (board.getAmountOfQueen() == board.getSize())
		return true;
	else
		return false;
}
//precondition: A valid column X and a valid row Y
//postcondition: perform checking by calling the function isInDangerZone from board class return true if it is in danger else return false
bool nQueens::isDanger(const int& x, const int& y)
{
	if (board.isInDangerZone(x, y))
		return true;
	else
		return false;
}

//precondition: none
//postcondition: calling the function getAmountOfQueen from board class and return integer of the ammount of queen
int nQueens::getAmountOfQueen() const
{
	return board.getAmountOfQueen();
}
