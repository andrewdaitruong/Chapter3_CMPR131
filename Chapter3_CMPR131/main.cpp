//Name:

//Group:
//
//      Guadalupe Roman-Sanchez
//      Jessica Nguyen
//      Therese Pham
//      Danny Hernandez
//      Andrewdai Truong
//      Nguyen Tran

//Assignment: Chapter 3

//Date: September 20, 2023

//Description: This program will allow you to
#include <vector>
#include <iostream>
#include<chrono>
#include "input.h"
#include "Option1.h"
#include <ctime>
#include <chrono>
#include "Tower.h"
#include "Option3.h"

void subMenu2();
int menuOption();
void option1();
void option2();
void option3();

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
    Option1 tictac;
    tictac.displayBoard();

    while (tictac.playingStatus())
    {
        //Player
        tictac.getPlayerMove();
        if (tictac.playingStatus())
        {
            tictac.getAIMove();
            if (!tictac.playingStatus()) // AI won
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
    tictac.numberofWins();
    tictac.gameStats();
    system("pause");
    return;

}

void displayTowers(Tower& Tower1, Tower& Tower2, Tower& Tower3, int userInput)
{
    if (userInput > 0 && userInput < 10)
    {
		for (int i = (userInput-1); i >= 0; i--)
        {
            Tower1.displayTowerPart(i, false, userInput);
            Tower2.displayTowerPart(i, false, userInput);
            Tower3.displayTowerPart(i, true, userInput);
        }
        cout << "\t\t";
        for (int i = 0; i < ((userInput * 2) + 1); i++)
            cout << char(205);
        cout << "\t\t";
        for (int i = 0; i < ((userInput * 2) + 1); i++)
            cout << char(205);
        cout << "\t\t";
        for (int i = 0; i < ((userInput * 2) + 1); i++)
            cout << char(205);
        cout << "\t\t";
    }
    else if (userInput >= 10)
    {
		for (int i = userInput; i > 0; i--)
        {
            Tower1.TowerDisplayPart2(i, false, userInput);
            Tower2.TowerDisplayPart2(i, false, userInput);
            Tower3.TowerDisplayPart2(i, true, userInput);
        }
    }
}

void option2() //Tower of Hanoi
{
	int steps = 0;
	system("cls");

	//Description
	subMenu2();


	auto start = chrono::steady_clock::now();
	auto stop = chrono::steady_clock::now();
	auto diff = stop - start;


	start = chrono::steady_clock::now(); // start clock 
	int userInput = inputInteger("\n\tEnter the number of rings (1..64) to begin:", 1, 64);
	Tower Tower1(userInput);
	Tower Tower2(0);
	Tower Tower3(0);
	char choice = ' ';
	char subchoice = ' ';
	bool doAgain = true;
	while (toupper(choice) != 'Q' || toupper(subchoice) != 'Q' || doAgain == false)
	{
		int counter = 0;
		if (userInput > 0 && userInput < 10)
		{
			for (int i = userInput; i > 0; i--)
			{
				Tower1.displayTowerPart(i, false, userInput);
				Tower2.displayTowerPart(i, false, userInput);
				Tower3.displayTowerPart(i, true, userInput);
			}
		}
		else if (userInput >= 10)
		{
			for (int i = userInput; i >= 0; i--)
			{
				Tower1.TowerDisplayPart2(i, false, userInput);
				Tower2.TowerDisplayPart2(i, false, userInput);
				Tower3.TowerDisplayPart2(i, true, userInput);
			}
		}
		Rings something;
		//subMenu2(userInput, Tower1, Tower2, Tower3);
		choice = inputChar("\n\tSelect the top disk from the start peg (A, B, C, or Q-quit):", static_cast<string>("ABCQ"));
		switch (toupper(choice))
		{
		case 'A':Tower1.getTopofRing();  break;
		case 'B':Tower2.getTopofRing(); break;
		case 'C':Tower3.getTopofRing(); break;
		case 'Q': return;
		default:
			cout << "\n\tERROR: Invalid Option. Must be A, B, C, or Q-quit\n\n";
		}

		subchoice = inputChar("\n\tSelectSelect the end peg (A, B, C or Q-quit) to move the selected disk:", static_cast<string>("ABCQ"));
		bool madeMove = false;
		switch (toupper(subchoice))
		{
		case 'A':madeMove = Tower1.takeInRing(something); break;
		case 'B':madeMove = Tower2.takeInRing(something); break;
		case 'C':madeMove = Tower3.takeInRing(something); break;
		case 'Q': return;
		default:
			cout << "\n\tERRR:Invalid Option. Must be A, B. C. or Q-quit\n\n";
		}
		if (madeMove == true)
			steps++;
		else if (madeMove == false)
		{
			switch (toupper(choice))
			{
			case 'A':Tower1.takeInRing(something); break;
			case 'B':Tower2.takeInRing(something); break;
			case 'C':Tower3.takeInRing(something); break;
			}
		}

		if (Tower3.checkIfDone(userInput))
		{
			bool doAgain1 = true;
			cout << "\n\t Good job you finished!\n";
			cout << steps;
			char again;
			cout << "\n\tDo you want to do it again Y or N";
			cin >> again;
			while (doAgain1 == true)
			{
				if (toupper(again) == 'Y')
				{
					doAgain = true;
					doAgain1 = false;
				}
				else if (toupper(again) == 'N')
				{
					doAgain = false;
					doAgain1 = false;
				}
				else
				{
					cout << "\n\tYou have to put either Y or N";
					doAgain1 = true;
				}
			}
		}
	}

	stop = chrono::steady_clock::now(); // end clock

	diff = stop - start; // displace timer
	cout << " : " << chrono::duration<double, nano>(diff)
		.count() << " ns" << endl;
	system("pause");
}

void subMenu2()
{
    cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
    cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
    cout << "\n\tany peg. The game starts with the rings in a neat stack in ascending order of size on one";
    cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";

    cout << "\n\n\tThe objective of the game is to move the entire stack from the starting peg-A to ending peg-B,";
    cout << "\n\tobeying the following simple rules:";

    cout << "\n\t\t1. Only one disk can be moved at a time.";
    cout << "\n\t\t2. Each move consists of taking the upper disk from one of the stacks and";
    cout << "\n\t\t   placing it on top of another stack or on an empty peg.";
    cout << "\n\t\t3. No larger disk may be placed on top of a smaller disk.";
}

//precondition: none
//postcondition: calculates average time
double getAverage(vector<double> time)
{
	double sum = 0.0;
	for (auto i : time)
		sum += i;
	return sum;
}

//precondition: needs to start the clock first
//postcondition: displays all time from fastest, slowest, average and amount of moves
template <typename T>
static void timeStop(const T* start, int move) {
	static vector<double> timeStop;
	static map< double, int> moves;
	auto stop = steady_clock::now();

	double second = chrono::duration<double>(stop - *start).count();

	moves.insert(pair<double, int>(second, move));

	timeStop.push_back(second);
	cout << "\n\tThis run's time: " << second << " seconds, " << moves.at(second) << " move(s) was used" << endl;
	sort(timeStop.begin(), timeStop.end());
	cout << "\n\tFastest run's time: " << timeStop.at(0) << "s, " << moves.at(timeStop.at(0)) << " move(s) was used" << endl;
	cout << "\n\tSlowest run's time: " << timeStop.at(timeStop.size() - 1) << "s, " << moves.at(timeStop.at(timeStop.size() - 1)) << " move(s) was used" << endl;

	double average = getAverage(timeStop) / static_cast<double>(timeStop.size());
	cout << "\n\tAverage run time: " << average << "s" << endl;

}


int gameAmount = 0; //global variable to count numbers for option 3

//precondition: n is greater than or equal to zero
//postcondition: asides from (n=2||n=3) solveable N-Queens game correlates to dimension
void option3() //n-Queens
{
	system("cls");
	Option3 option;
	Board board;
	//Description
	cout << "\n\tThe n-queens puzzle is the problem of placing n chess queens on a n" << char(215) << "n chessboard";
	cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
	cout << "\n\tqueens share the same row, column, or diagonal. Solutions exist for all natural";
	cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";	

	option.setDimension(inputInteger("\n\t\tEnter the board dimension nxn: ", true)); //validation for getting board size

	auto start = steady_clock::now(); //initializing start time
	auto stop = steady_clock::now(); //initializing stop time
	auto diff = stop - start; //difference
	start = steady_clock::now(); //starts the timer

	int move = 0; //initializing move counter

	do
	{
		option.printBoard(); //initializing option

		if (option.isWin())
		{
			gameAmount++; //incrementing gameAmount after winning
			cout << "\n\tCongratulation! You have solved N-Queens in " << move << " moves.\n";
			stop = steady_clock::now(); //ends the timer
			char choice = inputChar("\n\t\tPlay again? (Y = yes || N = no): ", true);

			//if function to try again after winning
			if (choice == 'Y' || choice == 'y')
			{
				return option3();
			}
			else if (choice == 'N' || choice == 'n')
			{
				cout << "\n\t\tGames Played: " << gameAmount;
				timeStop(&start, move);
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
			int row = inputInteger("\n\t\tPosition a queen in the row", true);
			int col = inputInteger("\n\t\tPosition a queen in the column: ", true);
			option.setPos(col - 1, row - 1);
			move++; //move +1 when A completes
		}
		break;
		case 'B': //Deleting a queen
		{
			int rowp = inputInteger("\n\t\tDelete a queen in position row: ", true);
			int colp = inputInteger("\n\t\tDelete a queen in position column: ", true);
			option.pop(colp - 1, rowp - 1);
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
				return option3();
			}
			else if (choice1 == 'N' || choice1 == 'n')
			{
				timeStop(&start, move);
				return;
			}
			else
			{
				cout << "\n\t\tGames Played: " << gameAmount;
				cout << "\n\tInvalid Choice. Please enter (Y = yes || N = no)";
			}
		}

		}
	} while (true);
}