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
	//This is not really needed. Why set the diameter of all 64 rings to zero? Also in constructor that isnt used
	//else
	//{
	//	for (int i = 0; i < MAX; i++)
	//	{
	//		ring[i].setDiameter(0);
	//	}
	//}
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
	if (i <= used)
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
	}

	else if (i > used)
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
bool Tower::takeInRing(Rings input)
{
	if (input.getDiameter() == 0)
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg. Please choose again.\n";
		return false;
	}

	if (used == 0)
	{
		ring[used] = input;
		used++;
		return true;
	}

	if (input.getDiameter() == ring[used - 1].getDiameter())
	{
		cout << "\n\tCannot make the move. The selected end peg cannot be the same as the selected start peg.\n\t\tPlease choose again.\n";
		return false;
	}

	if (input.getDiameter() < ring[used - 1].getDiameter())
	{
		ring[used] = input;
		used++;
		return true;
	}

	cout << "\n\tERROR: Cannot make the move. \n";
	return false;
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
	if (takeInRing(ring[(used - 1)]))
	{
		--used;
	}
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

//Is this a deconstructor? Is this for the play again?
//precondition: none
//postcondition: deletes our tower
//void Tower::deleteTower()
//{
//	for (int i = 0; i < MAX; i++)
//		ring[i].setDiameter(0);
//	used = 0;
//}

//precondition: takes in an interger
//postcondition: returns true or false depending on whether the user is done
bool Tower::checkIfDone(int userInput) const
{
	if (used == userInput)
		return true;
	else
		return false;
}