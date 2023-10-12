#include "Tower.h"


Tower& Tower::operator=(const Tower& right) {
	// Check for self-assignment
	if (this == &right)
		return *this;

	// Copy ring array
	for (int i = 0; i < MAX; ++i) {
		ring[i] = right.ring[i];
	}

	// Copy 'used' member variable
	used = right.used;

	// Return *this to allow for chained assignment
	return *this;
}

// pre condition: none
// post condition: intilize the data variables
Tower::Tower() : Rings()
{
	//NOT REALLY NEEDED. NOT CALLING DEFAULT CONSTRUCTOR EVER
	//for (int i = 0; i < MAX; i++)
	//	ring[i].setDiameter(0);
	//used = 0;
}

// pre condition: user input for the number of rings
// post condition: intilizes the data variables
Tower::Tower(int userInput) : Rings()
{
	if (userInput > 0)
	{
		//for loop for getting diameter from bottom as largest to top as smallest
		for (int i = 0; i < userInput; i++)
		{
			ring[i].setDiameter(userInput - i);
		}

	}
	else
	{
		for (int i = 0; i < MAX; i++)
		{
			ring[i].setDiameter(0);
		}
	}
	used = userInput;
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
void Tower::displayTowerPart(int i, bool end, int userInput) const
{
	int ringLength = ring[i].getDiameter();
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
		if (ring[i].getDiameter() == 0)
			cout << char(186); //double vertical line
		else
			cout << ring[i].getDiameter(); //ring number

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

//NOT NEEDED. NOT USED
////precondition: none
////postcondition: return the number that's used
//int Tower::getSize() const
//{
//	return used;
//}

//precondition: takes in a ring object
//postcondition: return true or false
void Tower::takeInRing(Rings input)
{
	if (used == 0)
	{
		ring[used] = input;
		used++;
	}
	else if(input.getDiameter() < ring[used - 1].getDiameter())
	{
		ring[used] = input;
		used++;
	}
	else
		cout << "\n\tERROR: Cannot make the move. \n\n";
}

//precondition: takes in two integers and a bool
//postcondition: displays the tower for one where the disks are greater than 9
void Tower::TowerDisplayPart2(int i, bool end, int userInput) const
{
	if(used > i)
	{
		cout << "\t";
		cout << (ring[i].getDiameter());
		if (end == true)
			cout << "\n";
	}
	else if (i > used)
	{
		cout << "\t";
		cout << char(186);
		
		//hardcoded. linebreak
		if (end == true)
			cout << "\n";

	}
}

//precondition: none
//precondition: returns are ring
void Tower::getTopofRing()
{
	int newused = used - 1;
	ring[used-1].setDiameter(0);
	used = newused; // we are getting rid of a ring off one of the stacks so array decrements by 1
}

// pre condition:
// post condition: 

/// If 10 >= i then we don't display the weird assci character
// 10 > i   thhen we display the rings assci character
/*


for(int i = 0; i < used; i++)
//need to find a a way to find the space
// int = space do the used - number of space = added space
for int i = int space
  cout << " ";
  for(int j = 0; j < ring[i].getdiameter();j++)
	  cout << ascii character
  cout << i;
  for(int j = 0; j < ring[i].getdiameter();j++)
	  cout << ascii character
  cout << "\n\t";


**/

//precondition: none
//postcondition: deletes our tower
void Tower::deleteTower()
{
	for (int i = 0; i < MAX; i++)
		ring[i].setDiameter(0);
	used = 0;
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

//Precondition:
//postcondition:
bool Tower::compareItTo0()
{
	int realUsed = 0;
	if (used > 0)
	{
		realUsed = used - 1;
	}
	if (ring[realUsed].getDiameter() == 0)
		return true;
	else
		return false;
}

// Pre  condition: Takes in a tower Object
// Post condition: returns true if input object is less than the other tower object , else false 
bool Tower::operator>(const Rings& right)
{
	int lookAtthisDiameter = this[used - 1].getDiameter();
	if (lookAtthisDiameter > right.getDiameter())
		return true;
	else
		return false;
}

Rings Tower::trythisRing()
{
	return ring[used - 1];
}