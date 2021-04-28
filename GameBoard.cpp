#include <iostream>
#include <algorithm>    /* STL */
#include <vector>       /* STL */
#include "GameBoard.h"
#include "Row.h"
#include "Column.h"
#include "Block.h"
using namespace std;

GameBoard::GameBoard(vector<int> values){
    for(int i=0; i<81; i++){
        cellValues[i] = values[i];
        originalCellValues[i] = values[i];
    }

}

void GameBoard::printBoard(){
    
    cout << "   1   2   3   4   5   6   7   8   9  " << endl;
    printSolidLine();

    int cellVal;

    for(int row=1; row<=9; row++){
        cout << static_cast<char>(row+64) << "| " ; // letter A begins at 65
        for(int col=1; col<=9; col++){
            cellVal = cellValues[col + 9*(row-1) - 1];
            if(cellVal == 0){cout << " ";} // if cell value is 0, print empty space
                else{cout << cellVal;}

            if(col % 3 != 0){cout << "   ";} // only print pipe at end of group col
            else{cout << " | ";}
        }
        cout << "\n";
        if(row % 3 == 0) // print line at end of group row
            printSolidLine();
    }

}

void GameBoard::printSolidLine(){
    cout << " +---+---+---+---+---+---+---+---+---+" << endl;
}

int GameBoard::getCellValue(char row, int col){
    return cellValues[col + 9*(row-'A')];
    //return cellValues[col + 9*(row-64-1) - 1];
}

int GameBoard::getOriginalCellValue(char row, int col){
    return originalCellValues[col + 9*(row-'A') - 1];
}

void GameBoard::updateCellValue(char row, int col, int value){
    if(getOriginalCellValue(row, col) != 0){ // if original board had a value, can't update it
        cout << "\x1B[31mThis is a fixed cell. Value cannot be changed.\033[0m\t\t" << endl;
    } else if(checkValidRow(row, value) == true && checkValidColumn(col, value) == true && checkValidBlock(row, col, value)) {
        cellValues[col + 9*(row-64-1) - 1] = value;
    }
}

bool GameBoard::checkValidRow(char row, int value){
    bool valid;
    Row selectedRow(this, row);
    valid = selectedRow.checkValidEntry(selectedRow.getRowPtr(), value);
    return valid;
}

bool GameBoard::checkValidColumn(int col, int value){
    bool valid;
    Column selectedCol(this, col);
    valid = selectedCol.checkValidEntry(selectedCol.getColPtr(), value);
    return valid;
}

bool GameBoard::checkValidBlock(char row, int col, int value){
    bool valid;
    Block selectedBlock(this, row, col);
    valid = selectedBlock.checkValidEntry(selectedBlock.getBlockPtr(), value);
    return valid;
}

// use all_of from STL to check if puzzle is complete
bool GameBoard::boardComplete(){
    return all_of(cellValues, cellValues+81, [](int x){ return x!=0; }); // checks if any element is 0
}