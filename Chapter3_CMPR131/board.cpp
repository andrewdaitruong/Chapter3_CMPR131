#include "board.h"


//precondition: none
//postcondition: none
Board::Board()
{
	size = 0;
}

//precondition: none
//postcondition: initialize board size
Board::Board(int size)
{
	this->size = size;
}

//precondition: none
//postcondition: set the size of the board
void Board::setSize(const int& size)
{
	this->size = size;
}

//precondition: 
//postcondition: 
int Board::getSize() const
{
	return size;
}

//precondition: none
//postcondition: returns the danger zone
multimap<int, int> Board::getDangerZone() const
{
	return danger_zone;
}

//precondition: none
//postcondition: returns the coordinates in the multimap
multimap<int, int> Board::getCoordinate() const
{
	return coordinate;
}
//precondition: pieces on the board
//postcondition: checks the position of pieces to see if it is blocked by another piece
bool Board::isInDangerZone(const int& x, const int& y)  const
{
	for (const auto& pair : danger_zone)
	{
		if (pair.first == x && pair.second == y)
			return true;
	}
	return false;
}

//precondition: none
//postcondition: used to check the danger zone going up and left
int* Board::reduceUpWard(int x, int y)
{
	int* temp = new int[2];
	for (int i = 0; i < size; i++)
	{
		if (x == 0 || y == 0)
			break;
		x--;
		y--;
	}
	temp[0] = x;
	temp[1] = y;
	return temp;
}

//precondition: none
//postcondition: used to check the danger zone going left and down
int* Board::reduceDownWard(int x, int y)
{
	
	int* temp = new int[2];

	while (true)
	{
		if (x==0 || y == size - 1)
			break;
		x--;
		y++;
	}
	temp[0] = x;
	temp[1] = y;
	return temp;
}
//precondition : A valid column X and a valid row Y
//postcondition: insert the danger zone to danger zone multimap
void Board::setDangerZone(const int& x, const int& y)
{
	int tempX = x;
	int tempY = y;
	multimap<int, int> temp;
	int* reduceUp = reduceUpWard(x, y);
	temp.insert(pair<int, int>(reduceUp[0], reduceUp[1]));
	int* reduceDown = reduceDownWard(x, y);
	temp.insert(pair<int, int>(reduceDown[0], reduceDown[1]));
	for (int i = 0; i < size; i++)
	{
		temp.insert(pair<int, int>(i, y));
		
		temp.insert(pair<int, int>(x, i));
		if (reduceUp[0] < size || reduceUp[1] < size)
		{

			reduceUp[0]++;
			reduceUp[1]++;
			temp.insert(pair<int, int>(reduceUp[0], reduceUp[1]));

		}
		if (reduceDown[0] < size || reduceDown[1] >0)
		{
			reduceDown[0]++;
			reduceDown[1]--;
			temp.insert(pair<int, int>(reduceDown[0], reduceDown[1]));
		}

	}
	
	if(danger_zone.empty())
		danger_zone = temp;
	else
	for (const auto& pair : temp) {
		auto range = danger_zone.equal_range(pair.first);
		bool found = false;
		for (auto it = range.first; it != range.second; ++it) {
			if (it->second == pair.second) {
				found = true;
				break;
			}
		}
		if (!found) {
			danger_zone.insert(pair);
		}
	}
	delete [] reduceUp;
	delete [] reduceDown;

}
//precondition: A valid column X and a valid row Y
//postcondition: set the queen into the multimap coordinate and set the danger zone for the queen
void Board::setQueen(const int& x, const int& y)
{
	coordinate.insert(pair<int, int>(x, y));
	setDangerZone(x, y);
}

//precondition: A valid column X and a valid row Y
//postcondition: removes the posistion of the queen from the mulmap coordinate
void Board::popQueen(const int& x, const int& y)
{
	coordinate.erase(x);
	danger_zone.clear();
	for (const auto& pair : coordinate)
	{
		setDangerZone(pair.first, pair.second);
	}
}
//precondition: A valid column X and a valid row Y
//postcondition: checks if the coordinate is in the multimap coordinate
bool Board::searchForCoordinate(const int& x, const int& y)
{
	for (const auto& pair : coordinate)
	{
		if (pair.first == x && pair.second == y)
			return true;
	}
	return false;
}

//precondition: none
//postcondition: returns the amount of queens used
int Board::getAmountOfQueen() const
{
	return coordinate.size();
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
			if (searchForCoordinate(j,i))
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