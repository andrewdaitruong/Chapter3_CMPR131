//Name:

//Group:
//      Guadalupe Roman-Sanchez
//      Jessica Nguyen
//      Therese Pham
//      Andrewdai Truong
//      Nguyen Tran

//Assignment: Chapter 3

//Date: 10/16/23

//Description: This program will allow you to understand how a class container works.
#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include "input.h"
#include "TicTacToe.h"
#include <ctime>
#include <chrono>
#include "Tower.h"
#include "nQueens.h"


int menuOption();
void option1();
void option2();
void option3();
double getAverage(multimap<int, double>::iterator begin, multimap<int, double>::iterator end);
multimap<int, double> reverseMap(map<double, int> inputMap);
template<typename T>
void timeStop(const T* time, int move, int ammount_of_object, string game, int gameCount, string filename, bool display);
using namespace std;
using namespace std::chrono;

//precondition: none
//postcondition: none
int main()
{
	do
	{
		switch (toupper(menuOption())) //switch case for main menu
		{
		case 0: exit(1); break;

		case 1: option1(); break;

		case 2:; option2(); break;

		case 3:; option3(); break;

		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");

	} while (true);

	return EXIT_SUCCESS;
}



//precondition: none
//postcondition: displays program's main menu
int menuOption()
{
	system("cls");
	cout << "\n\tCMPR131 Chapter 3 - Games Applications Using Containers";
	cout << "\n\t" + string(100, char(205));
	cout << "\n\t\t1> Tic-Tac-Toe";
	cout << "\n\t\t2> Tower of Hanoi";
	cout << "\n\t\t3> n-Queens";
	cout << "\n\t" + string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" + string(100, char(205));
	cout << "\n";

	return inputInteger("\t\tOption: ", 0, 3); //input validation
}

//precondition: none
//postcondition: starts game of tic-tac-toe with an AI opponent
void option1() //Tic-tac-toe
{
	system("cls");

	//Description
	cout << "\n\tTic - tac - toe(also known as Noughts and crosses or Xs and Os) is a game for two";
	cout << "\n\tplayers, Xand O, who take turns marking the spaces in a 3" << char(215) << "3 grid. The player who";
	cout << "\n\tsucceeds in placing three of their marks in a horizontal, vertical, or diagonal";
	cout << "\n\trow wins the game.";
	cout << "\n\tThis tic-tac-toe program plays against the computer. Human player, X, will always";
	cout << "\n\tfirst.Time will be recorded for the fastest and the slowest game.Average time will";
	cout << "\n\tthen be calculated and displayed.";

	auto start = high_resolution_clock::now();
	TicTacToe tictac;
	tictac.displayBoard();

	while (tictac.getPlayingStatus())
	{
		//Player
		tictac.setPlayerMove();
		if (tictac.getPlayingStatus())
		{
			tictac.setAIMove();
			if (!tictac.getPlayingStatus()) // AI won
			{
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);
				tictac.addTime(duration, tictac.getNumberOfMoves());

				if (tictac.playAgain()) // player selects play again
				{
					auto start = high_resolution_clock::now();
					tictac.resetBoard();
				}
			}
		}
		else // player forfeits OR game has ended
		{
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<seconds>(stop - start);
			tictac.addTime(duration, tictac.getNumberOfMoves());

			if (tictac.playAgain())
			{
				//Reset time & board
				auto start = high_resolution_clock::now();
				tictac.resetBoard();
			}
			else
			{
				break;
			}
		}
	}
	tictac.displayGameStats();
	system("pause");
	return;

}


 
int gameTwoCount = 0; //variable for option2()
//precondition: none
//postcondition: starts game and records the data for each ring played with moves made and time
void option2() //Tower of Hanoi
{
	int steps = 0;
	system("cls");

	cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
	cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
	cout << "\n\tany peg. The game starts with the rings in a neat stack in ascending order of size on one";
	cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";
	cout << "\n\n\tThe objective of the game is to move the entire stack from the starting peg-A to ending peg-B,";
	cout << "\n\tobeying the following simple rules:";
	cout << "\n\n\t\t1. Only one disk can be moved at a time.";
	cout << "\n\t\t2. Each move consists of taking the upper disk from one of the stacks and";
	cout << "\n\t\t   placing it on top of another stack or on an empty peg.";
	cout << "\n\t\t3. No larger disk may be placed on top of a smaller disk.";

	//Time stuff
	auto start = steady_clock::now(); //initializing start time
	auto stop = steady_clock::now(); //initializing stop time
	auto diff = stop - start; //difference
	start = steady_clock::now(); //starts the timer

	int userInput = inputInteger("\n\n\tEnter the number of rings (1..64) to begin:", 1, 64);
	Tower Tower1(userInput, true);
	Tower Tower2(userInput, false);
	Tower Tower3(userInput, false);
	char choice = ' ';
	char subchoice = ' ';
	bool doAgain = true;
	bool validStart = true;
	char validError = ' ';

	while (toupper(choice) != 'Q' || toupper(subchoice) != 'Q' || doAgain == false) // While user doesn't quit
	{
		int counter = 0;
		cout << "\n\tTower of Hanoi\n";
		//shows the special character for 1 to 9
		cout << "\n";
		if (userInput > 0)// display the towers
		{
			for (int i = (userInput - 1); i >= 0; i--)
			{
				Tower1.displayPartOfTower(i, false, userInput);
				Tower2.displayPartOfTower(i, false, userInput);
				Tower3.displayPartOfTower(i, true, userInput);
			}
			if (userInput <= 9)
			{
				cout << "\t\t";
				for (int i = 0; i < userInput; i++)
					cout << " ";
				cout << "A";
				for (int i = 0; i < userInput; i++)
					cout << " ";
				cout << "\t\t";
				for (int i = 0; i < userInput; i++)
					cout << " ";
				cout << "B";
				for (int i = 0; i < userInput; i++)
					cout << " ";
				cout << "\t\t";
				for (int i = 0; i < userInput; i++)
					cout << " ";
				cout << "C";
				for (int i = 0; i < userInput; i++)
					cout << " ";
				cout << "\n";
			}
			else
			{
				cout << "\t";
				cout << "A \tB \tC \n";
			}
		}

		int previousResponse = 0;
		validStart = true;
		choice = inputChar("\n\tSelect the top disk from the start peg (A, B, C, or Q-quit):", static_cast<string>("ABCQ"));
		subchoice = inputChar("\n\tSelect the end peg (A, B, C or Q-quit) to move the selected disk:", static_cast<string>("ABCQ"));
		bool madeMove = false;

		//check if the towers are empty 
		switch (toupper(choice))
		{
		case 'A':
		{
			if (Tower1.checkEmpty())
			{
				validError = 'A';
				validStart = false;
			}
		}
		break;
		case 'B':
		{
			if (Tower2.checkEmpty())
			{
				validError = 'B';
				validStart = false;
			}
		}
		break;
		case 'C':
		{
			if (Tower3.checkEmpty())
			{
				validError = 'C';
				validStart = false;
			}
		}
		break;
		default:
			validStart = true;
			break;
		}

		if (!validStart) // display why they can not make that move 
		{
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-" << validError << ".";
			cout << "\n\t\tPlease choose again.\n";
		}
		else //valid move
		{
			Ring ring;
			switch (toupper(choice)) // get the top ring 
			{
			case 'A':
				ring = Tower1.getTopRing();
				previousResponse = 1;
				break;
			case 'B':
				ring = Tower2.getTopRing();
				previousResponse = 2;
				break;
			case 'C':
				ring = Tower3.getTopRing();
				previousResponse = 3;
				break;
			case 'Q':
				return;
				break;
			default:
				cout << "\n\tERROR: Invalid Option. Must be A, B, C, or Q-quit\n\n";
				break;
			}

			switch (toupper(subchoice))//remove the top ring
			{
			case 'A':
				if (Tower1.checkEmpty())
				{
					Tower1.setTopRing(ring);
					if (previousResponse == 1)
						Tower1.removeTopRing();
					else if (previousResponse == 2)
						Tower2.removeTopRing();
					else if (previousResponse == 3)
						Tower3.removeTopRing();
					else
						cout << "\n\tThe move wasn't made.";
					madeMove = true;
				}
				else if (Tower1 > ring)
				{
					Tower1.setTopRing(ring);
					if (previousResponse == 1)
						Tower1.removeTopRing();
					else if (previousResponse == 2)
						Tower2.removeTopRing();
					else if (previousResponse == 3)
						Tower3.removeTopRing();
					else
						cout << "\n\tThe move wasn't made.";
					madeMove = true;
				}
				else
					cout << "\n\tThis ring isn't the right size\n";
				break;
			case 'B':
				if (Tower2.checkEmpty())
				{
					Tower2.setTopRing(ring);
					if (previousResponse == 1)
						Tower1.removeTopRing();
					else if (previousResponse == 2)
						Tower2.removeTopRing();
					else if (previousResponse == 3)
						Tower3.removeTopRing();
					else
						cout << "\n\tThe move wasn't made.";
					madeMove = true;
				}
				else if (Tower2 > ring)
				{
					Tower2.setTopRing(ring);
					if (previousResponse == 1)
						Tower1.removeTopRing();
					else if (previousResponse == 2)
						Tower2.removeTopRing();
					else if (previousResponse == 3)
						Tower3.removeTopRing();
					else
						cout << "\n\tThe move wasn't made.";
					madeMove = true;
				}
				else
					cout << "\n\tThis ring isn't the right size\n";
				break;
			case 'C':
				if (Tower3.checkEmpty())
				{
					Tower3.setTopRing(ring);
					if (previousResponse == 1)
						Tower1.removeTopRing();
					else if (previousResponse == 2)
						Tower2.removeTopRing();
					else if (previousResponse == 3)
						Tower3.removeTopRing();
					else
						cout << "\n\tThe move wasn't made.";
					madeMove = true;
				}
				else if (Tower3 > ring)
				{
					Tower3.setTopRing(ring);
					if (previousResponse == 1)
						Tower1.removeTopRing();
					else if (previousResponse == 2)
						Tower2.removeTopRing();
					else if (previousResponse == 3)
						Tower3.removeTopRing();
					else
						cout << "\n\tThe move wasn't made.";
					madeMove = true;
				}
				else
					cout << "\n\tThis ring isn't the right size\n";
				break;
			case 'Q':
				timeStop(&start, steps, userInput, "discs", gameTwoCount, "option2.dat",1);
				return;
			default:
				cout << "\n\tERRR:Invalid Option. Must be A, B. C. or Q-quit\n\n";
				break;
			}
			if (madeMove == true)
				steps++;
		}

		if (Tower3.checkIfDone(userInput))
		{
			gameTwoCount++;
			bool doAgain1 = true;
			//shows the special character for 1 to 9
			if (userInput > 0)
			{
				for (int i = (userInput - 1); i >= 0; i--)
				{
					Tower1.displayPartOfTower(i, false, userInput);
					Tower2.displayPartOfTower(i, false, userInput);
					Tower3.displayPartOfTower(i, true, userInput);
				}
				if (userInput <= 9)
				{
					cout << "\t\t";
					for (int i = 0; i < userInput; i++)
						cout << " ";
					cout << "A";
					for (int i = 0; i < userInput; i++)
						cout << " ";
					cout << "\t\t";
					for (int i = 0; i < userInput; i++)
						cout << " ";
					cout << "B";
					for (int i = 0; i < userInput; i++)
						cout << " ";
					cout << "\t\t";
					for (int i = 0; i < userInput; i++)
						cout << " ";
					cout << "C";
					for (int i = 0; i < userInput; i++)
						cout << " ";
					cout << "\n";
				}
				else
				{
					cout << "\t";
					cout << "A \tB \tC \n";
				}
			}
			cout << "\n\t Good job you finished!\n";
			cout << "\tYou completed this in " << steps << " steps";

			char again = (toupper(inputChar("\n\tDo you want to play again? (Y-yes or N-no)", 'YN')));
			do
			{
				switch (again)
				{
				case 'Y':
				{
					timeStop(&start, steps, userInput, "discs", gameTwoCount, "option2.dat", 0);
					return option2();
				}
				case 'N':
				{
					timeStop(&start, steps, userInput, "discs", gameTwoCount, "option2.dat", 1);
					return;
				}
				default: "\n\tYou have to put either Y or N";
				}
			} while (doAgain == false);
		}

	}
}

int gameThreeCount = 0; //variable for option3()

//precondition: n is greater than or equal to one... (n = 2 | n = 3) is not solvable 
//postcondition: Solvable N-Queens game correlates to dimension
void option3() //n-Queens
{
	system("cls");
	nQueens queen;

	//Description
	cout << "\n\tThe n-queens puzzle is the problem of placing n chess queens on a n" << char(215) << "n chessboard";
	cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
	cout << "\n\tqueens share the same row, column, or diagonal. Solutions exist for all natural";
	cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";

	queen.setDimension(inputInteger("\n\t\tEnter the board dimension nxn: ", true)); //validation for getting board size

	auto start = steady_clock::now(); //initializing start time
	auto stop = steady_clock::now(); //initializing stop time
	auto diff = stop - start; //difference
	start = steady_clock::now(); //starts the timer

	int move = 0; //initializing move counter

	do
	{
		queen.printBoard(); //initializing option

		if (queen.isWinning())
		{
			gameThreeCount++; //incrementing gameAmount after winning
			cout << "\n\tCongratulation! You have solved N-Queens in " << move << " moves.\n";
			stop = steady_clock::now(); //ends the timer
			char choice = inputChar("\n\t\tPlay again? (Y = yes || N = no): ", true);

			//if function to try again after winning
			if (choice == 'Y' || choice == 'y')
			{
				timeStop(&start, move, queen.getAmountOfQueen(), "queens", gameThreeCount, "option3.dat", 0);
				return option3();
			}
			else if (choice == 'N' || choice == 'n')
			{
				cout << "\n\t\tGames Played: " << gameThreeCount;
				timeStop(&start, move, queen.getAmountOfQueen(), "queens", gameThreeCount,"option3.dat", 1);
				return;
			}
			else
			{
				cout << "\n\tInvalid Choice. Please enter (Y = yes || N = no)";
			}
		}

		cout << "\n\tGame Options";
		cout << "\n\t" + string(100, char(205));
		cout << "\n\t\tA> Place a queen";
		cout << "\n\t\tB> Remove an existing queen";
		cout << "\n\t" + string(100, char(196));
		cout << "\n\t\t0> Return";
		cout << "\n\t" + string(100, char(205));
		cout << "\n";

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("AB0"))))
		{
		case 'A': //Adding a quene
		{
			int row = inputInteger("\n\t\tPosition a queen in the row: ", true);
			int col = inputInteger("\n\t\tPosition a queen in the column: ", true);
			queen.setQueen(col - 1, row - 1);
			move++; //move +1 when A completes
		}
		break;
		case 'B': //Deleting a queen
		{
			int rowp = inputInteger("\n\t\tDelete a queen in position row: ", true);
			int colp = inputInteger("\n\t\tDelete a queen in position column: ", true);
			queen.popQueen(colp - 1, rowp - 1);
			move++; //move +! when B completes
		}
		break;
	

		case '0'://Returning
		{
			stop = steady_clock::now();
			char choice1 = inputChar("\n\t\tPlay again? (Y = yes || N = no): ", true);

			//if function to try again for losing
			if (choice1 == 'Y' || choice1 == 'y')
			{
				timeStop(&start, move, queen.getAmountOfQueen(), "queens", gameThreeCount, "option3.dat", 0);
				return option3();
			}
			else if (choice1 == 'N' || choice1 == 'n')
			{
				timeStop(&start, move, queen.getAmountOfQueen(), "queens", gameThreeCount, "option3.dat", 1);
				return;
			}
			else
			{
				cout << "\n\t\tGames Played: " << gameThreeCount;
				cout << "\n\tInvalid Choice. Please enter (Y = yes || N = no)";
			}
		}

		}
	} while (true);
}

//precondition: a valid multimap<int,double>::iterator begin and a valid multimap<int,double>::iterator end
//postcondition: it will return a double value of the average of the multimap
double getAverage(multimap<int, double>::iterator begin, multimap<int, double>::iterator end)
{
	double sum = 0.0;
	for (auto it = begin; it != end; ++it) {
		sum += it->second;
	}
	return sum;
}

//precondition: valid <double, mint> map
//postcondition: it will return a reversed multimap<double,int>
multimap<int, double> reverseMap(map<double, int> inputMap) {
	multimap<int, double> reversedMultimap;
	for (const auto& pair : inputMap) {
		reversedMultimap.insert({ pair.second, pair.first });

	}
	return reversedMultimap;
}

//precondition: a valid chrono::steady_clock::time_point time that contain the time value of the start of the game and end of the game, an valid move integer,
//a valid ammount_of_object integer that is either discs or queens, a valid string game, a valid gameCount integer, a valid string filename(to store  and load game data), a valid boolean display(1- display, 0- dont display)
//postcondition: this function will store/load the data time, moves and ammount_of_object in the "filename".dat file and using that data to display and calculate the average time of the game for each ammount_of_object category
template <typename T>
void timeStop(const T* time, int move, int ammount_of_object, string game, int gameCount, string filename, bool display) {
	vector<double> timeStop;
	map<double, int > ammount_of_object_map;
	map<double, int> moves;

	// Read existing data from file
	if (gameCount != 1) {
		ifstream inFile(filename);
		double time;
		int read_move;
		int read_ammount_of_object;
		while (inFile >> time >> read_move >> read_ammount_of_object) {
			timeStop.push_back(time);
			moves.insert(pair<double, int>(time, read_move));
			ammount_of_object_map.insert(pair<double, int>(time, read_ammount_of_object));
		}
		inFile.close();
	}

	auto stop = steady_clock::now();
	double second = duration<double>(stop - *time).count();

	moves.insert(pair<double, int>(second, move));
	ammount_of_object_map.insert(pair<double, int>(second, ammount_of_object));

	timeStop.push_back(second);

	multimap<int, double> reversed_ammount_of_object_map = reverseMap(ammount_of_object_map);
	vector<int> temp;
	int temp_ammount_of_object = 0;
	cout << "\n\t\tThis run's time: " << second << " seconds, " << moves.at(second) << " move(s) was used with was playing with " << ammount_of_object << " " << game << endl;
	for (const auto& i : ammount_of_object_map)
	{
		if (temp_ammount_of_object != i.second)
		{
			temp_ammount_of_object = i.second;
			temp.push_back(temp_ammount_of_object);

		}
	}
	if (display)
		for (const auto& it : temp)
		{
			auto range = reversed_ammount_of_object_map.equal_range(it);
			double first_key = range.first->second;

			// Decrement the end iterator to get the last valid iterator in the range
			double last_key = first_key;
			int count = 0;
			for (auto itr = range.first; itr != range.second; ++itr) {
				last_key = itr->second;
				count++;
			}
			cout << "\n\t\t" << count << " game using " << it << " " << game << " was played.";
			cout << "\n\t\tFastest run's time: " << first_key << "s, " << moves.at(first_key) << " move(s) was used was playing with " << ammount_of_object_map.at(first_key) << " " << game << endl;
			cout << "\n\t\tSlowest run's time: " << last_key << "s, " << moves.at(last_key) << " move(s) was used was playing with " << ammount_of_object_map.at(last_key) << " " << game << endl;
			double average = getAverage(range.first, range.second) / static_cast<double>(count);
			cout << "\n\t\tAverage run time: " << average << "s" << endl;

		}
	ofstream outFile(filename);
	for (const auto& i : reversed_ammount_of_object_map) {
		outFile << i.second << " " << moves[i.second] << " " << ammount_of_object_map[i.second] << "\n";
	}
	outFile.close();

}