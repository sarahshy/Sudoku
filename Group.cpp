#include <iostream>
#include "Group.h"
using namespace std;

Group::Group(){
}

bool Group::checkValidEntry(int* ptrValues, int newValue){
    for(int i=0; i<9; i++){
        if(ptrValues[i] == newValue)
            return false;
    }
    return true;
}
