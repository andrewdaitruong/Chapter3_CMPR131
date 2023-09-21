#include "Rings.h"

// pre condition: none
// post condition: initilizes the data for Ring class
Rings::Rings()
{
	diameter = 0;
}
// pre condition: user input for diameter (int)
// post condition: set data value for diameter
void Rings::setDiameter(int input)
{
	diameter = input;
}

// pre condition: none
// post condition: returns the data value for diameter
int Rings::getDiameter() const
{
	return diameter;
}