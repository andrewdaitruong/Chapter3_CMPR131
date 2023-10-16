#include "Tower.h"

// pre condition: user input for the number of rings
// post condition: intilizes the data variables
Tower::Tower(int size, bool firstTower) : Ring()
{
	if (firstTower == true)
	{
		rings = new Ring[size];
		//for loop for getting diameter from bottom as largest to top as smallest
		for (int i = 0; i < size; i++)
		{
			rings[i].setDiameter(size - i);
		}
		used = size;

	}
	else if(firstTower == false)
	{
		rings = new Ring[size];
		for (int i = 0; i < size; i++)
		{
			rings[i].setDiameter(0);
		}
		used = 0;
	}
}

// pre condition: none
// post condition: Destructor (deallocates used memory)
Tower::~Tower()
{
	delete rings;
}

//precondition: none
//postcondition:return true if it's empty, false if it's empty
bool Tower::checkEmpty() const
{
	if (used == 0)
		return true;
	else
		return false;
}

//precondition: two integers, and a bool
//postcondition: display parts of our tower for <= 9
void Tower::displayPartOfTower(int i, bool end, int userInput) const
{
	if(userInput < 10)
	{
		int ringLength = rings[i].getDiameter();
		cout << "\t\t";

		//special character for the boxes for rings < 10
		char seperator = 223;
		if (i < used)
		{
			int space = userInput - ringLength;

			//display to evenly space out towers of left side
			for (int j = 0; j < space; j++)
				cout << " ";

			//special character for left side of ring < 10
			for (int j = 0; j < ringLength; j++)
				cout << seperator;

			//display for the numbers
			if (rings[i].getDiameter() == 0)
				cout << char(186); //double vertical line
			else
				cout << rings[i].getDiameter(); //ring number

			//special character for right side of ring < 10
			for (int j = 0; j < ringLength; j++)
				cout << seperator;

			//evens out the spacing on the right side
			for (int j = 0; j < space; j++)
				cout << " ";
			if (end == true)
				cout << "\n";
		}
		else if (i >= used)
		{
			//evens out the spaces
			int space = userInput;
			for (int i = 0; i < space; i++)
				cout << " ";

			cout << char(186);

			for (int i = 0; i < space; i++)
				cout << " ";

			//hardcoded? line breaks 
			if (end == true)
				cout << "\n";
		}
	}
	else if (userInput >= 10)
	{
		cout << "\t";
		if (used > i)
		{
			cout << (rings[i].getDiameter());
			if (end == true)
				cout << "\n";
		}
		else if (i >= used)
		{
			cout << char(186);
			//hardcoded. linebreak
			if (end == true)
				cout << "\n";
		}
	}
}

//precondition: takes in a ring object
//postcondition: return true or false
void Tower::setTopRing(Ring input)
{
	if (used == 0)
	{
		rings[used] = input;
		used++;
	}
	else if(input.getDiameter() < rings[used - 1].getDiameter())
	{
		rings[used] = input;
		used++;
	}
	else
		cout << "\n\tERROR: Cannot make the move. \n\n";
}

//precondition: none
//precondition: returns are ring
void Tower::getTopRing()
{
	int newused = used - 1;
	rings[used-1].setDiameter(0);
	used = newused; // we are getting rid of a ring off one of the stacks so array decrements by 1
}

//precondition: takes in an interger
//postcondition: returns true or false depending on whether the user is done
bool Tower::checkIfDone(int userInput) const
{
	if (used == userInput)
		return true;
	else
		return false;
}


// Pre  condition: Takes in a tower Object
// Post condition: returns true if input object is less than the other tower object , else false 
bool Tower::operator>(const Ring& right)
{
	Ring newTry = this->tryNewRing();
	if (newTry.getDiameter() > right.getDiameter())
		return true;
	else
		return false;
}

//precondition: none
//postcondition: returns a object ring
Ring Tower::tryNewRing()
{
	return rings[used - 1];
}

