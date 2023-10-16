#ifndef BOARD_H
#define BOARD_H
#include <map>
#include <iostream>
using namespace std;



class Board
{
private:
	int size;
	multimap<int, int> danger_zone;
	multimap< int, int> coordinate;
	
public:
	//constructor
	Board();
	Board(int);

	//setters
	void setQueen(const int&, const int&);
	void setSize(const int& );
	void setDangerZone(const int&, const int&);

	//getters
	int getAmountOfQueen() const;
	int getSize() const;
	multimap<int,int> getDangerZone() const;
	multimap<int, int> getCoordinate() const;
	
	//functions
	bool isInDangerZone(const int&, const int&) const;
	bool searchForCoordinate(const int&, const int&);
	void popQueen(const int&, const int&);
	void printBoard();
};

#endif
//bool searchForDangerZone(const int&, const int&);