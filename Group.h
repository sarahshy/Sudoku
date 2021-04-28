#ifndef GROUP_H
#define GROUP_H

#include <stdio.h>
using namespace std;

class Group { // check repeated values of user entry
    public:
        Group();
        virtual bool checkValidEntry(int* ptrValues, int newValue);
    private:
};

#endif
