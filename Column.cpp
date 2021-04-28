
#include <iostream>
#include "Column.h"
using namespace std;

Column::Column(GameBoard* board, int userCol) : Group() { // userRow is a character (65-73)
    colValues = new int[9];
    for(char i=0; i<9; i++)
        colValues[i] = board->getCellValue(static_cast<char>(i+65), userCol-1); // -1 for 0-idx
}

int* Column::getColPtr(){
    return colValues;
}

bool Column::checkValidEntry(int* ptrValues, int newValue){
    for(int i=0; i<9; i++){
        if(ptrValues[i] == newValue){
            cout << "\n\x1B[31mValue already exists in COLUMN.\033[0m\t\t\n" << endl;
            return false;
        }
    }
    return true;
}