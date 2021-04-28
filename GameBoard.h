#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <stdio.h>
using namespace std;

class GameBoard { // holds board objects
    public:
        //GameBoard(int* p);
        GameBoard(vector<int>);
        void printBoard();
        void printSolidLine();

        void updateCellValue(char row, int col, int value);
        int getCellValue(char row, int col);
        int getOriginalCellValue(char row, int col);

        bool checkValidRow(char row, int value);
        bool checkValidColumn(int col, int value);
        bool checkValidBlock(char row, int col, int value);

        bool boardComplete();
    private:
        int cellValues[81];
        int originalCellValues[81];
};

#endif
