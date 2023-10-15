#ifndef TOWER_H
#define TOWER_H
#include "Ring.h" // base class
#include <iostream>
using namespace std;

class Tower : public Ring
{
private:
    Ring* rings; // max number of rings
    int used;
public:
    Tower(); // defualt constructor
    Tower(int size, bool firstTower);  // constructor
    ~Tower();
    // functions 
    bool checkEmpty() const;
    void setTopRing(Ring input);
    void getTopRing();
    void displayTowerPart(int i, bool end, int userInput) const;
    bool checkIfDone(int userInput) const;
    Ring trythisRing();
    bool operator >(const Ring& right);


   
};
       


#endif