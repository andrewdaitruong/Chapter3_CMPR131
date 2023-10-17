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
    Ring getTopRing();
    void displayPartOfTower(int i, bool end, int userInput) const;
    bool checkIfDone(int userInput) const;
    void removeTopRing();
    bool operator >(const Ring& right);


   
};
       


#endif