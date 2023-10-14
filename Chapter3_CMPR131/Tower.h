#ifndef TOWER_H
#define TOWER_H
#include "Ring.h" // base class
#include <iostream>
using namespace std;

class Tower : public Ring
{
private:
    static const int MAX = 64;
    Ring* rings; // max number of rings
    int used;
public:
    Tower(); // defualt constructor
    Tower(int size, bool firstTower);  // constructor

   // int getSize() const;
    bool checkEmpty() const;
    void takeInRing(Ring input);
    void getTopofRing();
    bool compareItTo0();
    void deleteTower();
    void displayTowerPart(int i, bool end, int userInput) const;
    bool checkIfDone(int userInput) const;
    Tower& operator=(const Tower& right);
    bool operator >(const Ring& right);
    Ring trythisRing();
    int returnTopDiameter();

   
};
       


#endif