#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include "Group.h"
#include "GameBoard.h"
using namespace std;

class Block : public Group { // holds functions for validating groups
    public:
       Block(GameBoard* board, char userRow, int userCol);
        int* getBlockPtr();
        bool checkValidEntry(int* ptrValues, int newValue);
        
    protected:
        int* blockValues;
};

#endif
