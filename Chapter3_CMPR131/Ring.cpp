#include "Ring.h"

// precondition: none
// postcondition: initilizes the data for Ring class
Ring::Ring()
{
	diameter = 0;
}

// precondition: user input for diameter (int)
// postcondition: set data value for diameter
void Ring::setDiameter(int input)
{
	diameter = input;
}

// precondition: none
// postcondition: returns the data value for diameter
int Ring::getDiameter() const
{
	return diameter;
}

//precondition: none
//postcondition: assigns diameter of other rings
void Ring::operator=(const Ring& other)
{
	diameter = other.diameter;
}
