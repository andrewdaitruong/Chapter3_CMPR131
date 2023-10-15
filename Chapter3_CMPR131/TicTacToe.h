#pragma once
#include<iostream>
#include"input.h"
#include<vector>
#include<chrono>
#include<algorithm>
#include<map>


using namespace std;
using namespace::chrono;

class TicTacToe
{
private: 
	char boardPlacement[3][3]; //2d array for tic-tac-toe board placements
	vector<string> boardCheck; //vector containing available board placements

	vector<vector<string>>vectCheck; //2d vector containing sets of possible wins and their board placement
	map<int, char> winSets; //map of current status of win sets 
							//(value marked O for possible AI win, marked X for possible player win, marked F for impossible win)

	multimap<seconds, int> playTimes; //time to play game, mapped to number of moves

	int playerMoves; //number of moves a player has made in a single game
	int numOfGames; //number of games a player has played
	bool playingStatus; //bool value indicating whether player is still playing game or not
	char winState; //flag value to check if game has been won by AI or player or neither

	int row; //number of rows on board
	int col; //number of columns on board
	int CPUwins; //the amount of times the computer wins
	int Playerwins; //the amount of timess the player wins

public:
	// Constructor
	TicTacToe(); 

	//Accessors
	bool getPlayingStatus(); //returns playingStatus (true if player is still playing game)
	int getNumberOfMoves(); //returns number of moves in one game
	

	//Mutators
	void setPlayerMove(); //Get player move and validates it
	void setX(int rowVal, int colVal); //Sets X on board (player move)
	void setAIMove(); //Gets AI move from available spots
	void setO(int rowVal, int colVal); //Sets 0 move on board (AI move)
	void resetBoard(); //Resets board for new game
	void addTime(seconds time, int moves); // adds duration of a game with how many moves it took from player to multimap
	void updateVectSets(); //Updates possible winning sets (vectSets) with current status of moves made so far. 
						 //Updates map of possible winning sets (winSets) with char-based flags to help decide next best move for AI.
	void playerForfeit(); //ends current game, gives win to AI
	void checkForWinner();//checks board placements for possible win/draw/loss. Sets playingStatus to false if game has ended.

	void displayBoard(); //Display current tic-tac-toe board
	bool checkBoard(int rowVal, int colVal); //checks selection of board placement (argument) to see if available
	bool playAgain(); //verify if user wishes to play again or not
	void displayGameStats(); //displays number of games played. Displays fastest, slowest, & average game times w/ their corresponding player moves.
};



