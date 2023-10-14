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
	void setPosition(pos, pos);
	void setSize(const int);
	
	//getters
	int getCoordSize();
	int getSize();
	
	//functions
	bool checkBlock(pos, pos);
	void printBoard();	
	void popPosition(pos, pos);
	bool coordinates(pos, pos);
};
#endif // !1