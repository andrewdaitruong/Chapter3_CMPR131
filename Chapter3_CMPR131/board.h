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
	void setQueen(int, int);
	void setSize(const int);
	
	//getters
	int getCoordSize();
	int getSize();
	multimap<int,int> getDangerZone();
	multimap<int, int> getCoordinate();
	
	//functions
	
	void setDangerZone(int, int);
	bool isInDangerZone(int, int);
	bool searchForCoordinate(const int&, const int&, multimap<int, int>);
	void printBoard(bool);	
	void popQueen(int, int);
	
};

#endif // !1
//bool searchForDangerZone(const int&, const int&);