#ifndef ROW_H
#define ROW_H

#include <stdio.h>
#include "Group.h"
#include "GameBoard.h"
using namespace std;

class Row : public Group { // assemble row group
    public:
        Row(GameBoard* board, char userRow);
        int* getRowPtr();
        bool checkValidEntry(int* ptrValues, int newValue);
    protected:
        int* rowValues;
        
};

#endif
