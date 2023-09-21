#include "board.h"

//precondition: none
//postcondition: none
void Board::init()
{
	for (int i = 0; i < size; i++)
	{
		row[i] = false;
		column[i] = false;
	}
}

//precondition: none
//postcondition: none
Board::Board()
{
	row = nullptr;
	column = nullptr;
	size = 0;
	coord.clear();
}

//precondition: none
//postcondition: returns the coordinates
bool Board::cord(pos x, pos y)
{
	if (coord[x] != y)
		return false;
	else
		return true;
}

//precondition: 
//postcondition: 
Board::Board(int size)
{
	row = new bool[size];
	column = new bool[size];
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		row[i] = false;
		column[i] = false;
	}
}

//precondition: none
//postcondition: set the size of the board
void Board::setSize(int size)
{
	if (size != 0)
	{
		delete[] row;
		delete[] column;
	}
	this->size = size;
	row = new bool[size];
	column = new bool[size];
	init();
}

//precondition: 
//postcondition: 
int Board::getSize()
{
	return size;
}

//precondition: none
//postcondition: clears the board
Board::~Board()
{
	coord.clear();
	row = nullptr;
	column = nullptr;
	delete[] row;
	delete[] column;
}

//precondition: pieces on the board
//postcondition: checks the position of pieces to see if it is blocked by another piece
bool Board::checkMate(pos x, pos y)
{
	if (x < 0 || y < 0 || x >= size || y >= size)
		return false;
	if (row[x] && column[y]&& cord(x, y))
		return true;
	else
		return false;
}

//precondition: none
//postcondition: places something into the position designated
void Board::setPos(pos x, pos y)
{
	row[x] = true;
	column[y] = true;
	coord.insert(pair<int, int>(x, y));
}

//precondition: must have something in that column or row
//postcondition: removes the thing in that column or row
void Board::pop(pos x, pos y)
{
	column[y] = false;
	row[x] = false;
	
	if (coord.size() == 1)
		coord.clear();
	else
	coord.erase(x) ;
}

//precondition: needs to enter board size
//postcondition: returns maximum size for both row and column
int Board::getCoordSize()
{
	return coord.size();
}

//precondition: needs dimension
//postcondition: prints board
void Board::printBoard()
{
	for (int i = 0; i < size; ++i) {
		if (i == 0)
		{
			cout << "\t" << char(201);
			for (int i = 0; i < size - 1; ++i)
				cout << string(2, char(205));
			cout << char(205);
			cout << char(187) << endl;
		}

		cout << "\t" << char(186);
		for (int j = 0; j < size; j++) {
			if (row[j] && column[i] && cord(j, i))
			{
				cout << "Q";
			}
			else
			{
				cout << " ";
			}
			if (j < size - 1)
				cout << char(179);
		}
		cout << char(186);
		cout << endl;
		if (i != size - 1) {
			cout << "\t" << char(186);
			for (int j = 0; j < size; j++) {
				cout << char(196);
				if (j != size - 1)

					cout << char(197);
			}
			cout << char(186) << endl;
		}
		else
		{
			cout << "\t" << char(200);
			for (int i = 0; i < size - 1; ++i)
				cout << string(2, char(205));
			cout << char(205);
			cout << char(188) << endl;
		}
	}
}