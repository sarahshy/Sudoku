
#include <iostream>
#include "Block.h"
using namespace std;

Block::Block(GameBoard* board, char userRow, int userCol) : Group() { // userRow is a character (65-73)
    blockValues = new int[9];
    int rowMult; // stores row group
    int colMult; // stores col group
    int i{0};

    switch((userRow-'A')/3){
        case 0:
            rowMult = 0;
            break;
        case 1:
            rowMult = 1;
            break;
        case 2:
            rowMult = 2;
    }
    switch((userCol-1)/3){
        case 0:
            colMult = 0;
            break;
        case 1:
            colMult = 1;
            break;
        case 2:
            colMult = 2;
    }

    for(char row=65+3*rowMult; row<65+3*rowMult+3; row++){
        for(int col=1+3*colMult; col<1+3*colMult+3; col++){
            blockValues[i] = board->getCellValue(row, col-1); // -1 for 0-idx
            i++;
        }
    }
}

int* Block::getBlockPtr(){
    return blockValues;
}

bool Block::checkValidEntry(int* ptrValues, int newValue){
    for(int i=0; i<9; i++){
        if(ptrValues[i] == newValue){
            cout << "\n\x1B[31mValue already exists in BLOCK.\033[0m\t\t\n" << endl;
            return false;
        }
    }
    return true;
}