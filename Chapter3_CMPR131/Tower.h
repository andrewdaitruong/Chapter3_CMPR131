#ifndef TOWER_H
#define TOWER_H
#include "Rings.h" // base class
#include <iostream>
using namespace std;

class Tower : public Rings
{
private:
    static const int MAX = 64;
    Rings* ring; // max number of rings
    int used;
public:
    Tower(); // defualt constructor
    Tower(int size, bool firstTower);  // constructor

   // int getSize() const;
    bool checkEmpty() const;
    void takeInRing(Rings input);
    void getTopofRing();
    bool compareItTo0();
    void deleteTower();
    void displayTowerPart(int i, bool end, int userInput) const;
    bool checkIfDone(int userInput) const;
    Tower& operator=(const Tower& right);
    bool operator >(const Rings& right);
    Rings trythisRing();
    int returnTopDiameter();

   
};
       


#endif