#ifndef COLUMN_H
#define COLUMN_H

#include <stdio.h>
#include "Group.h"
#include "GameBoard.h"
using namespace std;

class Column: public Group { // holds functions for validating groups
    public:
        Column(GameBoard* board, int userCol);
        int* getColPtr();
        bool checkValidEntry(int* ptrValues, int newValue);
        
    protected:
        int* colValues;
};

#endif
