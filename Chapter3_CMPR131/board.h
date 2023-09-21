#ifndef BOARD_H
#define BOARD_H
#include <map>
#include <iostream>
using namespace std;

typedef int pos;

class Board
{
private:

	bool* row;
	bool* column;
	int size;
	map< int, int> coord;
	void init();

public:

	//constructor
	Board();
	Board(int);

	//destructor
	~Board();

	//setters
	void setPos(pos, pos);
	void setSize(const int);
	
	//getters
	int getCoordSize();
	int getSize();
	
	//functions
	bool checkMate(pos, pos);
	void printBoard();	
	void pop(pos, pos);
	bool cord(pos, pos);
};
#endif // !1