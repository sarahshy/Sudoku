
#include <iostream>
#include "Row.h"
using namespace std;

Row::Row(GameBoard* board, char userRow) : Group() { // userRow is a character (65-73)
    rowValues = new int[9];
    for(int i=0; i<9; i++)
        rowValues[i] = board->getCellValue(userRow, i);
}

int* Row::getRowPtr(){
    return rowValues;
}

bool Row::checkValidEntry(int* ptrValues, int newValue){
    for(int i=0; i<9; i++){
        if(ptrValues[i] == newValue){
            cout << "\n\x1B[31mValue already exists in ROW.\033[0m\t\t\n" << endl;
            return false;
        }
    }
    return true;
}