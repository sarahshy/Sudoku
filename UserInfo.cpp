#include <iostream>
#include <limits>
#include "UserInfo.h"
using namespace std;

UserInfo::UserInfo(){ // userRow is a character (65-73)
    level = 1;
    gamesPlayed = 1;
    continuePlaying = true;
}

// setters and getters
void UserInfo::setName(){
    cout << "Enter a player name: ";
    cin >> name;
}

string UserInfo::getName(){
    return name;
}

void UserInfo::setLevel(){
    cout << "\nChoose the level of difficulty:" << endl;
    cout << "Enter 1 for EASY..." << endl;
    cout << "Enter 2 for MEDIUM..." << endl;
    cout << "Enter 3 for HARD..." << endl;
    cin >> level;
    while(level < 1 || level > 4 || cin.fail()) { // check if input is valid
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // prevents repeated printing in case of input error
        cout << "\x1B[31mInvalid selection.\033[0m\t\t" << endl;
        cout << "Please enter a number between 1 and 3 (inclusive): ";
        cin >> level;
    }
}

int UserInfo::getLevel(){
    return level;
}

int UserInfo::getGamesPlayed(){
    return gamesPlayed;
}

void UserInfo::setGamesPlayed(int gameNum){
    gamesPlayed = gameNum;
}

bool UserInfo::getContinuePlaying(){
    return continuePlaying;
}

void UserInfo::setContinuePlaying(bool cont){
    continuePlaying = cont;
}

char UserInfo::getRowLetter(){
    return rowLetter;
}

void UserInfo::setRowLetter(char row){
    rowLetter = row;
}

int UserInfo::getColNum(){
    return colNum;
}

void UserInfo::setColNum(int col){
    colNum = col;
}

int UserInfo::getUserCellValue(){
    return userCellValue;
}

void UserInfo::setUserCellValue(int value){
    userCellValue = value;
}

// user input functions
void UserInfo::promptUserRow(){
    cout << "Choose a row (A-I): "; // can collapse each of these user entries into a function
    cin >> rowLetter;
    while(rowLetter < 65 | rowLetter > 73) { // check if row input is valid
        cout << "\x1B[31mInvalid row selection.\033[0m\t\t" << endl;;
        cout << "Please enter a capital letter A-I: ";
        cin >> rowLetter;
    }
}

void UserInfo::promptUserColumn(){
    cout << "Choose a column (1-9): ";
    cin >> colNum;
    while(colNum < 1 | colNum > 9 | cin.fail()) { // check if column input is valid
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\x1B[31mInvalid column selection.\033[0m\t\t" << endl;
        cout << "Please enter a number between 1 and 9 (inclusive): ";
        cin >> colNum;
    }
}

void UserInfo::promptUserValue(){
    cout << "Enter the value to fill (1-9): ";
    cin >> userCellValue;
    while(userCellValue < 1 || userCellValue > 9 || cin.fail()) { // check if value input is valid
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\x1B[31mInvalid value entered.\033[0m\t\t" << endl;
        cout << "Please enter a number between 1 and 9 (inclusive): ";
        cin >> userCellValue;
    }
}

void UserInfo::promptBoardInput(){
    promptUserRow();
    promptUserColumn();
    promptUserValue();
}