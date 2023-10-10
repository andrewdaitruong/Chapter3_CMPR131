#include "Option1.h"

//precondition: user starts the game
//postcondition: sets up the board placement for row and columns, and status that player is now playing
Option1::Option1()
{
    row = 3;
    col = 3;

    playerMoves = 0;
    numOfGames = 0;

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

    vectCheck.push_back({ "00", "11", "22" });//6
    vectCheck.push_back({ "20", "11", "02" }); //7   

  
    //SetCheck
    for (int i = 0; i < 8; i++)
    {
        winSets.insert({ i, ' '});
    }

 /*   for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < vectCheck[i].size(); j++)
        {
            cout << vectCheck[i][j] << " ";
        }
        cout << endl;
    }*/
    playing = true;

    cout << "\n\tGame begins...";

}


//precondition: player pressed option1 in main menu
//postcondition: displays the board of tic tac toe
void Option1::displayBoard()
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

//precondition: user is playing and chooses option1
//postcondition: resets the board so player can play again.
void Option1::resetBoard()
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


    playing = true;

    cout << "\n\tGame begins...";

    displayBoard();
}



//precondition: user is playing option1 tic tac toe
//postcondition: gets the players move of either 0, 1, 2, or 3
void Option1::getPlayerMove()
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



//precondition: user must be playing option1 and passes chooses 1, 2, or 3 for the column and row
//postcondition: sets an X up on the board for the user's input
void Option1::setX(int r, int c)
{

    boardPlacement[r - 1][c - 1] = 'X';

    string placeSearch = to_string(r - 1) + to_string(c - 1);

    boardCheck.erase(remove(boardCheck.begin(), boardCheck.end(), placeSearch), boardCheck.end());

    string tempX = "X";
    for (vector<string>& vInner : vectCheck) //ref to inner vector
    {
        replace(vInner.begin(), vInner.end(), placeSearch, tempX);
    }
    
   /* for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < vectCheck[i].size(); j++)
        {
            cout << vectCheck[i][j] << " ";
        }
        cout << endl;
    }*/

    checkforWinner();

    //Debug test to see if vector search/remove is working as intended
  /*  for (vector<string>::iterator it = boardCheck.begin(); it < boardCheck.end(); ++it)
    {
        cout << "\n" << *it;
    }*/

}

//precondition: user is playing Option1 and selects option 1, 2, or 3, function recieves both column and row
//postcondition: checks if the option was valid or not
bool Option1::checkBoard(int r, int c)
{

    string placeSearch = to_string(r - 1) + to_string(c - 1);


    if (find(boardCheck.begin(), boardCheck.end(), placeSearch) != boardCheck.end()) //means element was found and has NOT been used
    {
        return true; //means that NO ELEMENT IS PLACED THERE
    }
    else
    {
        return false; //means THAT ELEMENT IS PLACED THERE. NO MOVE CAN BE MADE THERE
    }

}

//precondition: user pressed a valid number for row and column and is playing option1
//postcondition: call's setO function and sets up random numbers for row and column
void Option1::getAIMove()
{
    cout << "\n\tDumb AI moves...\n";
    

    //Check for middle location (always)
    string middleSearch = to_string(1) + to_string(1);
    if (find(boardCheck.begin(), boardCheck.end(), middleSearch) != boardCheck.end())
    {
        setO(1, 1);
    }

    else
    {
        int setCheck = checkVectSets();
        cout << "setCheck check : " << setCheck;

        if (setCheck != -1)
        {
            for (int j = 0; j < vectCheck[setCheck].size(); j++)
            {
                if (vectCheck[setCheck][j] != "O")
                {
                    string priorityMove = vectCheck[setCheck][j];
                    cout << "priorityMove check = " << priorityMove;
                    int digit1, digit2;
                    
                    char digit = priorityMove[0];
                    digit1 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii
                    cout << "Digit 1" << digit1;
                    digit = priorityMove[1];
                    digit2 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii
                    cout << "Digit 2" << digit2;
                    setO(digit1, digit2);
                }
            }
        }
        else //if there are no checkmate moves in play
        {
            srand(time(0));
            int placesLeft = boardCheck.size();

            //cout << "Check boardSize: " << placesLeft;
            //cout << "\n\tCheck 00: " << boardCheck[0];


            int random = (rand() % placesLeft);

            string temp = boardCheck[random];

            /*cout << "\n\tTEMP: " << temp;*/

            int random1, random2;
            char digit = temp[0];
            random1 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii


            digit = temp[1];
            random2 = digit - '0'; // - '0' changes it from char to its integer value, since it retrieved digit as ascii


            setO(random1, random2);
        }

    }
    
}

int Option1::checkVectSets()
{
    int countX = 0;
    int countO = 0;
    int rowLeft = 3;
    for (int i = 0; i < 8; i++)
    {
        countX = 0;
        countO = 0;
        rowLeft = 3;
        //cout << "row" << i << "UPDATED Z";
        auto itr = winSets.find((i));
        if (itr->second == 'Z') //already marked as an unwinnable set, should skip iteration to check
        {
            i++;
            //cout << i << "skipped";
        }
        else
        {
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
                //cout << vectCheck[i][j] << " ";
            }
            if (rowLeft == 0 && (!(countX == 3) || !(countO == 3))) //Neutral Priority = Find Other Path
            {
                //cout << "row" << i << "UPDATED Z";
                auto itr = winSets.find((i));
                if (itr != winSets.end())
                {
                    itr->second = 'Z'; // no longer a winnable playset
                }
            }
            if (countO == 2 && rowLeft == 1) //PRIORITY 1 = Win With O
            {
                //cout << "row" << i << "UPDATED O";
                cout << "LOOP HITS";
                auto itr = winSets.find((i));
                if (itr != winSets.end())
                {
                    itr->second = 'O'; //checkmate for O
                    cout << "Set return = " << i;
                    return i; // this is the set O needs to play first to win
                    //return set
                }
            }
            else
            {
                if (countX == 2 && rowLeft == 1) //PRIORITY 2 = Block Win For X
                {
                    //cout << "row" << i << "UPDATED X";
                    auto itr = winSets.find((i)); //row (win Set)
                    if (itr != winSets.end())
                    {
                        itr->second = 'X'; //checkmate for X
                        return i; // this is the set O needs to block
                        //return set
                    }
                }
                //if no threatened states found //return negative flag num to indicate random
            }

        }
        
    }

    /*auto it = winSets.begin();
    cout << "\n";
    while (it != winSets.end())
    {
        cout << "Set #" << it->first << " | Status: ";
        if (it->second == 'X')
        {
            cout << "X Checkmate";
        }
        else if (it->second == 'O')
        {
            cout << "O Checkmate";
        }
        else if (it->second == 'Z')
        {
            cout << "Non-Winnable Set";
        }
        else
        {
            cout << "None";
        }
        cout << "\n";
        ++it;
    }*/

    return -1; // no checkmate sets yet, ai can play at random

}

//precondition: recieves a row and column after the user input a valid row and column
//postcondition: sets up an O on the board for the random AI
void Option1::setO(int r, int c)
{


    boardPlacement[r][c] = 'O';

    string placeSearch = to_string(r) + to_string(c);

    boardCheck.erase(remove(boardCheck.begin(), boardCheck.end(), placeSearch), boardCheck.end());

    string tempO = "O";
    for (vector<string>& vInner : vectCheck) //ref to inner vector
    {
        replace(vInner.begin(), vInner.end(), placeSearch, tempO);
    }

     for (int i = 0; i < 8; i++)
     {
       for (int j = 0; j < vectCheck[i].size(); j++)
       {
           cout << vectCheck[i][j] << " ";
       }
       cout << endl;
     }
    checkforWinner();
    //debug print
    //for (vector<string>::iterator it = boardCheck.begin(); it < boardCheck.end(); ++it)
    //{
    //    cout << "\n" << *it;
    //}
}

//precondition: user is playing option1
//postcondition: returns the playing status of the user
bool Option1::playingStatus()
{
    return playing;
}

//precondition: user pressed 0 on the row or column option
//postconditon: sets playing boolean to false and displays that the user forfeited
void Option1::playerForfeit()
{
    playing = false;
    cout << "\n\t You forfeited the game. Therefore, Dumb AI has won.";
    CPUwins++;

}

//precondition: user finished a tic tac toe game
//postcondition: returns if the user chooses to still play or not
bool Option1::playAgain()
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

//precondition: user input a valid choice for row and column
//postcondition: displays the winner if there is a winner for tic tac toe
void Option1::checkforWinner()
{

    displayBoard();

    //Check Rows
    for (int i = 0; i < row; i++)
    {
        if ((boardPlacement[i][0] == boardPlacement[i][1]) && (boardPlacement[i][0] == boardPlacement[i][2]) && (boardPlacement[i][0] != ' '))

        {

            if (boardPlacement[i][0] == 'X')// Player win
            {
                cout << "\n\tHuman player wins.";
                Playerwins++;
                playing = false;
                return;
            }
            else if (boardPlacement[i][0] == 'O')// AI win
            {
                cout << "\n\tDumb AI has actually won.";
                CPUwins++;
                playing = false;
                return;
            }


        }

    }

    //Check Columns
    for (int i = 0; i < col; i++)

    {

        if ((boardPlacement[0][i] == boardPlacement[1][i]) && (boardPlacement[0][i] == boardPlacement[2][i]) && (boardPlacement[0][i] != ' '))

        {
            if (boardPlacement[0][i] == 'X')// Player win
            {
                cout << "\n\tHuman player wins.";
                Playerwins++;
                playing = false;
                return;
            }
            else if (boardPlacement[0][i] == 'O')// AI win
            {
                cout << "\n\tDumb AI has actually won.";
                CPUwins++;
                playing = false;
                return;
            }

        }

    }

    //Check Diagonals
    if ((boardPlacement[0][0] == boardPlacement[1][1]) && (boardPlacement[0][0] == boardPlacement[2][2]) && (boardPlacement[0][0] != ' '))

    {
        if (boardPlacement[0][0] == 'X')// Player win
        {
            cout << "\n\tHuman player wins.";
            Playerwins++;
            playing = false;
            return;
        }
        else if (boardPlacement[0][0] == 'O')// AI win
        {
            cout << "\n\tDumb AI has actually won.";
            CPUwins++;
            playing = false;
            return;
        }

    }

    if ((boardPlacement[0][2] == boardPlacement[1][1]) && (boardPlacement[0][2] == boardPlacement[2][0]) && (boardPlacement[0][2] != ' '))

    {
        if (boardPlacement[0][2] == 'X')// Player win
        {
            cout << "\n\tHuman player wins.";
            Playerwins++;
            playing = false;
            return;
        }
        else if (boardPlacement[0][2] == 'O')// AI win
        {
            cout << "\n\tDumb AI has actually won.";
            CPUwins++;
            playing = false;
            return;
        }

    }

    //If none of the above checks pass & the board is empty, then it's a draw.
    if (boardCheck.empty())
    {
        cout << "\n\tIt's a draw.";
        playing = false;
        return;
    }


}


//precondition; user must finish at least one game of tic tac toe
//postcondition: returns the number of times player won, and computer won
void Option1::numberofWins()
{
    cout << "\n\tNumber of times the Player has won " << Playerwins;
    cout << "\n\tNumber of times Dumb AI has won " << CPUwins;
}


//Add each individual playtime.
//precondition: recieves seconds and moves throughout playing
//postcondition; increments the amount of games and inserts the time and number of moves
void Option1::addTime(seconds time, int moves)
{
    playTimes.insert({ time, moves });
    numOfGames++;

}

//precondition: user finished a game of tic tac toe
//postcondition: returns the number of moves played in tic tac toe by the user
int Option1::getNumberOfMoves()
{
    return playerMoves;
}

//precondition: user must have completed a game
//postcondition: displays the stats of the game
void Option1::gameStats()
{
    multimap<seconds, int>::const_iterator itr;

    //Debug check print
   //for (itr = playTimes.begin(); itr != playTimes.end(); ++itr)
   // {
   //     cout << "\n\t\tTime: " << itr->first.count() << " seconds";
   //     cout << "\n\t\tMoves: " << itr->second;
   // }

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
    //cout << "\n\t\tDebug Total: " << durationTotal << " second(s).";


}
