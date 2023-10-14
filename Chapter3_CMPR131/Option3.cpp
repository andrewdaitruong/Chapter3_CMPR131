#include "Option3.h"
#include "input.h"
#include <iostream>

using namespace std;

//precondition: need dimension size
//postcondition: prints the board and size
void Option3::printBoard() 
{
	board.printBoard(mode);
}

//precondition: none
//postcondition: sets the dimension with only a single integer to make an even squared board
void Option3::setDimension(int size)
{
	board.setSize(size);
}

//precondition: none
//postcondition: returns move count
int Option3::getCount()
{
	return count;
}

//precondition: none
//postcondition: size originally at 0
Option3::Option3()
{
	board.setSize(0);
}

//precondition: none
//postcondition: size;
Option3::Option3(int size)
{
	board.setSize(size);
}

//precondition: number must be above 0
//postcondition: returns dimension to get a perfect square
string Option3::getDimension()
{
	string dimension;
	dimension = board.getSize() + " x " + board.getSize();
	return dimension;
}
void Option3::setMode(bool mode)
{
	this->mode = mode;
}
bool Option3::isDanger(pos x, pos y)
{
		if (board.isInDangerZone(x, y))
		return true;
		else 
		return false;

}
//precondition: board must be above 0
//postcondition: puts a piece on the board
void Option3::setPos(pos x, pos y)
{
	if (x >= board.getSize() || y >= board.getSize())
	{
		cout << "Invalid position" << endl;
		return;
	}
	else if (isDanger(x,y))
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
bool Option3::isWin()
{
	if (board.getCoordSize() == board.getSize())
		return true;
	else return false;
}

//precondition: pieces should be on the board
//postcondition: removes a piece of the board
void Option3::pop(pos x, pos y)
{
	if (board.searchForCoordinate(x, y))
	{
		board.pop(x, y);
		count++;
	}
	else
		cout << "\n\t Queen does not exist at position (" << x + 1 << "," << y + 1 << ")" << endl;
}