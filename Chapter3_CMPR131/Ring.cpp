#include "Ring.h"

// pre condition: none
// post condition: initilizes the data for Ring class
Ring::Ring()
{
	diameter = 0;
}
// pre condition: user input for diameter (int)
// post condition: set data value for diameter
void Ring::setDiameter(int input)
{
	diameter = input;
}

// pre condition: none
// post condition: returns the data value for diameter
int Ring::getDiameter() const
{
	return diameter;
}
