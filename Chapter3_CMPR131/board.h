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

	//destructor
	~Board();

	//setters
	void setPos(int, int);
	void setSize(const int);

	//getters
	int getCoordSize();
	int getSize();

	//functions
	int* reduceUpWard(int, int);
	int* reduceDownWard(int, int);
	void setDangerZone(int, int);
	bool isInDangerZone(int, int);
	bool searchForDangerZone(const int&, const int&);
	void printBoard(bool);
	void pop(int, int);
	bool searchForCoordinate(const int&, const int&);
};
#endif // !1