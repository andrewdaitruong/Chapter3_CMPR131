#include "TicTacToe.h"

//precondition: user starts Tic-Tac-Toe game
//postcondition: initializes TicTacToe object with containers (2d array, 2d vector, vector, map) with starting values 
//               for tictactoe game. Sets initial winState, playerMoves, and number of games to 0 and ' '.
TicTacToe::TicTacToe()
{
    row = 3;
    col = 3;

    playerMoves = 0;
    numOfGames = 0;
    winState = ' ';

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            boardPlacement[i][j] = ' ';
        }
    }

    //00 | 01 | 02
    //10 | 11 | 12
    //20 | 21 | 22

    boardCheck = { "00", "01", "02",
                   "10", "11", "12",
                   "20", "21", "22" };

    //VECT CHECK (SETS)
    vectCheck.push_back({ "00", "01", "02" }); //0
    vectCheck.push_back({ "10", "11", "12" }); //1
    vectCheck.push_back({ "20", "21", "22" }); //2

    vectCheck.push_back({ "00", "10", "20" }); //3
    vectCheck.push_back({ "01", "11", "21" }); //4
    vectCheck.push_back({ "02", "12", "22" }); //5

    vectCheck.push_back({ "00", "11", "22" }); //6
    vectCheck.push_back({ "20", "11", "02" }); //7   


    //SetCheck
    for (int i = 0; i < 8; i++)
    {
        winSets.insert({ i, ' ' });
    }

    playingStatus = true;

    cout << "\n\tGame begins...";

}

//precondition: none
//postcondition: returns the playing status of the user
bool TicTacToe::getPlayingStatus()
{
    return playingStatus;
}

//precondition: user finished a game of tic-tac-toe
//postcondition: returns the number of moves played in one game of tictactoe by the user
int TicTacToe::getNumberOfMoves()
{
    return playerMoves;
}

//precondition: boardCheck is not empty (there must be moves left to play on the board)
//postcondition: sets valid input from user for row & column to setX function for player move.
void TicTacToe::setPlayerMove()
{
    bool valid = false;
    int rowSelect;
    int colSelect;
    cout << "\n\n\tHUMAN MOVES...";
    while (!valid)
    {
        rowSelect = inputInteger("\n\n\t\tEnter the board's row # (1..3) or 0 to forfeit: ", 0, 3);
        if (rowSelect == 0)
        {
            playerForfeit();
            return;
        }

        colSelect = inputInteger("\n\t\tEnter the board's col # (1..3) or 0 to forfeit: ", 0, 3);
        if (colSelect == 0)
        {
            playerForfeit();
            return;
        }

        if (checkBoard(rowSelect, colSelect))
        {
            valid = true;
        }
        else
        {
            cout << "\n\n\tERROR: Illegal move.The square is already owned. Please re - specify.";
        }
    }

    playerMoves++;
    setX(rowSelect, colSelect);
}

//precondition: rowVal(int), colVal(int) are valid integer inputs for row & col placement that are empty
//postcondition: sets an X up on the board for the user's input
void TicTacToe::setX(int rowVal, int colVal)
{
    boardPlacement[rowVal - 1][colVal - 1] = 'X';

    string placeSearch = to_string(rowVal - 1) + to_string(colVal - 1);

    boardCheck.erase(remove(boardCheck.begin(), boardCheck.end(), placeSearch), boardCheck.end());

    string tempX = "X";
    for (vector<string>& vInner : vectCheck) //ref to inner vector
    {
        replace(vInner.begin(), vInner.end(), placeSearch, tempX);
    }

    updateVectSets();
    checkForWinner();
}

//precondition: boardCheck is not empty (there must be moves left to play on the board)
//postcondition: call's setO function based on AI move priority based on winSet's map values for each possible winning set
void TicTacToe::setAIMove()
{
    cout << "\n\tDumb AI moves...\n";

    int priorityMoveValue = -1;
    int priorityMoveSet = -1;

    //Check for middle location (always)
    string middleSearch = to_string(1) + to_string(1);
    if (find(boardCheck.begin(), boardCheck.end(), middleSearch) != boardCheck.end())
    {
        setO(1, 1);
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            auto itr = winSets.find((i));
            if (itr->second != 'F') //skip Z sets (those are already marked as unwinnable)
            {
                if (itr->second == 'O') //First priority, get O win
                {
                    priorityMoveSet = i;
                    priorityMoveValue = 3;

                }
                else if (itr->second == 'X') //Second priority, prevent x win
                {
                    if (priorityMoveValue < 2)
                    {
                        priorityMoveSet = i;
                        priorityMoveValue = 2;
                    }
                }
                else if (itr->second == 'P') //Third priority, set up for O win (choose a set that has two spots open alongside already set up 'O')
                {
                    if (priorityMoveValue < 1)
                    {
                        priorityMoveSet = i;
                        priorityMoveValue = 1;
                    }

                }
            }
        }

        if (priorityMoveValue > 1) //set x or o
        {
            for (int j = 0; j < vectCheck[priorityMoveSet].size(); j++)
            {
                if (vectCheck[priorityMoveSet][j] != "O" && vectCheck[priorityMoveSet][j] != "X")
                {
                    string priorityMove = vectCheck[priorityMoveSet][j];
                    int digit1, digit2;

                    char digit = priorityMove[0];
                    digit1 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii

                    digit = priorityMove[1];
                    digit2 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii
                    setO(digit1, digit2);
                }
            }
        }
        else if (priorityMoveValue == 1) //set P
        {
            for (int j = 0; j < vectCheck[priorityMoveSet].size(); j++)
            {
                if (vectCheck[priorityMoveSet][j] != "O" && vectCheck[priorityMoveSet][j] != "X")
                {
                    string priorityMove = vectCheck[priorityMoveSet][j];
                    int digit1, digit2;

                    char digit = priorityMove[0];
                    digit1 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii

                    digit = priorityMove[1];
                    digit2 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii
                    setO(digit1, digit2);
                    return;
                }
            }
        }
        else //final places left on the board, random if not needed to prevent X win or get O win
        {
            srand(time(0));

            int placesLeft = boardCheck.size();
            int random = (rand() % placesLeft);

            string temp = boardCheck[random];

            int random1, random2;
            char digit = temp[0];
            random1 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii


            digit = temp[1];
            random2 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii

            setO(random1, random2);
        }
    }
}

//precondition: rowVal(int), colVal(int)
//postcondition: sets an O up on the board for the AI move
void TicTacToe::setO(int rowVal, int colVal)
{
    boardPlacement[rowVal][colVal] = 'O';

    string placeSearch = to_string(rowVal) + to_string(colVal);

    boardCheck.erase(remove(boardCheck.begin(), boardCheck.end(), placeSearch), boardCheck.end());

    string tempO = "O";
    for (vector<string>& vInner : vectCheck) //ref to inner vector
    {
        replace(vInner.begin(), vInner.end(), placeSearch, tempO);
    }
    updateVectSets();
    checkForWinner();
}

//precondition: previous game has ended
//postcondition: resets the class containers (including board) so player can play again.
void TicTacToe::resetBoard()
{

    playerMoves = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            boardPlacement[i][j] = ' ';
        }
    }

    //00 | 01 | 02
    //10 | 11 | 12
    //20 | 21 | 22

    boardCheck.clear();

    boardCheck = { "00", "01", "02",
                   "10", "11", "12",
                   "20", "21", "22" };


    playingStatus = true;

    //VECT CHECK (SETS)
    vectCheck.clear();
    vectCheck.push_back({ "00", "01", "02" }); //0
    vectCheck.push_back({ "10", "11", "12" }); //1
    vectCheck.push_back({ "20", "21", "22" }); //2

    vectCheck.push_back({ "00", "10", "20" }); //3
    vectCheck.push_back({ "01", "11", "21" }); //4
    vectCheck.push_back({ "02", "12", "22" }); //5

    vectCheck.push_back({ "00", "11", "22" });//6
    vectCheck.push_back({ "20", "11", "02" }); //7   



    //SetCheck
    winSets.clear();
    for (int i = 0; i < 8; i++)
    {
        winSets.insert({ i, ' ' });
    }

    cout << "\n\tGame begins...";
    winState = ' ';
    displayBoard();
}

//precondition: game must of tictactoe must have ended (playingStatus = false)
//postcondition; increments the amount of games and inserts the time and number of moves into multimap
void TicTacToe::addTime(seconds time, int moves)
{
    playTimes.insert({ time, moves });
    numOfGames++;
}

//precondition: board is not empty & playingStatus of game is still true (ongoing game)
//postcondition: updates vectCheck vector & winSets map to current status of board. 
//               winSet saves map values that indicates flag values for potential AI move.
void TicTacToe::updateVectSets()
{

    for (int i = 0; i < 8; i++)
    {
        int countX = 0;
        int countO = 0;
        int rowLeft = 3;
        auto itr = winSets.find((i));
        if (itr->second != 'F') //skip F sets (those are already marked as unwinnable)
        {
            //Checks Sets
            for (int j = 0; j < vectCheck[i].size(); j++)
            {
                if (vectCheck[i][j] == "X")
                {
                    countX++;
                    rowLeft--;
                }
                if (vectCheck[i][j] == "O")
                {
                    countO++;
                    rowLeft--;
                }
            }

            if (rowLeft == 0 && countX == 3)
            {
                itr = winSets.find(i);
                if (itr != winSets.end())
                {
                    itr->second = 'Y'; // Y is a X win ("yes")
                    winState = 'X';
                }
            }
            if (rowLeft == 0 && countO == 3)
            {
                auto itr = winSets.find(i);
                if (itr != winSets.end())
                {
                    itr->second = 'M'; // M is an AI win (O, "machine")
                    winState = 'O';
                }
            }
            if (rowLeft == 0 && (!(countX == 3) || !(countO == 3)))
            {
                //cout << "row" << i << "UPDATED Z";
                auto itr = winSets.find((i));
                if (itr != winSets.end())
                {
                    itr->second = 'F'; // no longer a winnable playset
                }
            }
            if (countO == 2 && rowLeft == 1)
            {
                auto itr = winSets.find((i));
                if (itr != winSets.end())
                {
                    itr->second = 'O'; //checkmate for O

                }
            }
            if (countX == 2 && rowLeft == 1)
            {
                //cout << "row" << i << "UPDATED X";
                auto itr = winSets.find((i)); //row (win Set)
                if (itr != winSets.end())
                {
                    itr->second = 'X'; //checkmate for X
                }
            }
            if (countO == 1 && rowLeft == 2) //more viable play than random
            {
                auto itr = winSets.find((i));
                if (itr != winSets.end())
                {
                    itr->second = 'P'; //possible play for O
                }
            }
        }
    }
}

//precondition: user pressed 0 on the row or column option for setPlayerMove
//postconditon: sets playing boolean to false and displays that the user forfeited. CPU gets a win.
void TicTacToe::playerForfeit()
{
    playingStatus = false;
    cout << "\n\t You forfeited the game. Therefore, Dumb AI has won.";
    CPUwins++;
}

//precondition: none
//postcondition: displays board and checks for winner or a possible draw for game. setsPlayingStatus to false if game has ended.
void TicTacToe::checkForWinner()
{
    displayBoard();
    if (winState == 'O')
    {
        cout << "\n\tDumb AI has actually won.";
        CPUwins++;
        playingStatus = false;
        return;
    }
    if (winState == 'X')
    {
        cout << "\n\tHuman player wins.";
        Playerwins++;
        playingStatus = false;
        return;
    }

    if (boardCheck.empty())
    {
        cout << "\n\tIt's a draw.";
        playingStatus = false;
        return;
    }
}


//precondition: none
//postcondition: displays the board of tic tac toe
void TicTacToe::displayBoard()
{

    cout << "\n\t\tTic-Tac-Toe";
    //top row
    cout << "\n\t\t" << char(201) << string(3, char(205)) << char(203)
        << string(3, char(205)) << char(203) << string(3, char(205)) << char(187);
    //middle of row 1
    cout << "\n\t\t";
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < col; j++) {
            cout << char(186) << " " << boardPlacement[i][j] << " ";
        }
    }
    cout << char(186);

    //bottom of row
    cout << "\n\t\t" << char(204) << string(3, char(205)) << char(206) << string(3, char(205))
        << char(206) << string(3, char(205)) << char(185);

    //middle of row 2
    cout << "\n\t\t";
    for (int i = 1; i < 2; i++) {
        for (int j = 0; j < col; j++) {
            cout << char(186) << " " << boardPlacement[i][j] << " ";
        }
    }
    cout << char(186);

    //bottom of row
    cout << "\n\t\t" << char(204) << string(3, char(205)) << char(206) << string(3, char(205))
        << char(206) << string(3, char(205)) << char(185);

    //middle of row 3
    cout << "\n\t\t";
    for (int i = 2; i < 3; i++) {
        for (int j = 0; j < col; j++) {
            cout << char(186) << " " << boardPlacement[i][j] << " ";
        }
    }
    cout << char(186);

    //bottom final row
    cout << "\n\t\t" << char(200) << string(3, char(205)) << char(202)
        << string(3, char(205)) << char(202) << string(3, char(205)) << char(188);
}




//precondition: rowVal (int), colVal(int) are valid row & col options for boardCheck (1-3)
//postcondition: checks if the option was valid or not
bool TicTacToe::checkBoard(int rowVal, int colVal)
{
    string placeSearch = to_string(rowVal - 1) + to_string(colVal - 1);

    if (find(boardCheck.begin(), boardCheck.end(), placeSearch) != boardCheck.end()) //means element was found and has NOT been used
    {
        return true; //means that NO ELEMENT IS PLACED THERE
    }
    else
    {
        return false; //means THAT ELEMENT IS PLACED THERE. NO MOVE CAN BE MADE THERE
    }
}



//precondition: user finished a tic tac toe game
//postcondition: returns true if player chooses to play again, false if player decides no
bool TicTacToe::playAgain()
{
    char answer = inputChar("\n\tPlay again? (Y-yes or N-no): ", "YN");

    if (toupper(answer) == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//precondition: user must have completed a game
//postcondition: displays the stats of the game, including player & cpu wins, as well as fastest, slowest, and avg gameplay times
//               w/ their corresponding times.
void TicTacToe::displayGameStats()
{
    cout << "\n\tNumber of times the Player has won " << Playerwins;
    cout << "\n\tNumber of times Dumb AI has won " << CPUwins;
    multimap<seconds, int>::const_iterator itr;

    cout << "\n\tGame Statistics: \n";
    auto durationTotal = playTimes.begin()->first.count();
    int count = 0;

    auto fastestDuration = playTimes.begin()->first.count();
    int fastestMoves = playTimes.begin()->second;

    auto slowestDuration = playTimes.begin()->first.count();
    int slowestMoves = playTimes.begin()->second;

    if (playTimes.begin() != --playTimes.end())
    {
        slowestDuration = (--playTimes.end())->first.count();
        slowestMoves = (--playTimes.end())->second;
    }


    if (playTimes.begin() != --playTimes.end()) //first element is not last element
    {
        for (itr = playTimes.begin(); itr != playTimes.end(); ++itr)
        {
            if (itr == playTimes.begin())
            {
                ++itr;
                durationTotal += itr->first.count();
                count++;
            }
            else
            {
                durationTotal += itr->first.count();
                count++;
            }
        }
    }

    auto avg = durationTotal / (playTimes.size() * 1.0);

    cout << "\n\t" << numOfGames << " game(s) of Tic-Tac-Toe played.";
    cout << "\n\t\tThe fastest time was " << fastestDuration << " seconds in " << fastestMoves << " moves.";
    cout << "\n\t\tThe slowest time was " << slowestDuration << " seconds in " << slowestMoves << " moves.";
    cout << "\n\t\tThe average time was " << avg << " second(s).";
}
