#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <stdlib.h>          /* srand, rand */
#include <time.h> 
#include <vector>            /* STL */
#include <SFML/Audio.hpp>    /* 3rd party - play audio */
#include "GameBoard.h"
#include "UserInfo.h"
using namespace std;

void importBoard(int level, vector<int> &values);
void gameFinish(UserInfo& user);

int main() {
    // create user profile
    UserInfo user;

    cout << "\nWelcome to Sudoku!" << endl;
    user.setName();
    cout << "\nHello, " << user.getName() << "!" << endl;

    while(user.getContinuePlaying()){
        // choose level
        user.setLevel();

        // import game board values
        vector<int> cellValues;
        importBoard(user.getLevel(), cellValues);

        // initialize board
        GameBoard board{cellValues};

        // play game until board is filled
        while(!board.boardComplete()){
            board.printBoard();

            // get user input
            user.promptBoardInput();

            // update board if possible
            board.updateCellValue(user.getRowLetter(), user.getColNum(), user.getUserCellValue());
        }
        board.printBoard();

        // play congratulatory music
        sf::SoundBuffer buffer;
        if(!buffer.loadFromFile("music.wav"))

        gameFinish(user);
    }

    return 0;
}

void importBoard(int level, vector<int>& cellValues){
    string fileName;
    srand(time(NULL)); // set random seed
    int fileNum{rand()%3+1}; // random int
    string levelStr;

    if(level == 1){
        levelStr = "easy";
    } else if (level==2){
        levelStr = "medium";
    } else {
        levelStr = "hard";
    }
    fileName = "boards/" + levelStr + to_string(fileNum) + ".txt";

    int cellValue;
    ifstream file(fileName);
    if(file.is_open()){
        for(int i=0; i<81; i++){
            file >> cellValue;
            cellValues.push_back(cellValue);
        }    
    }
}

void gameFinish(UserInfo& user){
    cout << "Congratulations, you completed the puzzle!" << endl;
    cout << "Would you like to play another game? (Enter y for yes, n for no)... ";

    string endGameInput;
    cin >> endGameInput;
    if(endGameInput == "n"){
        user.setContinuePlaying(false);
        cout << "\nThank you for playing! You completed a total of " << user.getGamesPlayed() << " games." << endl;
    } else {
        user.setGamesPlayed(user.getGamesPlayed()+1);
    }
        
}