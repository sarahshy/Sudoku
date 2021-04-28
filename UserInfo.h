// will hold user info e.g. name, input selection (prompts)
#ifndef USERINFO_H
#define USERINFO_H

#include <stdio.h>
#include <string>
using namespace std;

class UserInfo { // check repeated values of user entry
    public:
        UserInfo();

        void setName();
        string getName();

        void setLevel();
        int getLevel();

        int getGamesPlayed();
        void setGamesPlayed(int);

        bool getContinuePlaying();
        void setContinuePlaying(bool);

        char getRowLetter();
        void setRowLetter(char);
        int getColNum();
        void setColNum(int);
        int getUserCellValue();
        void setUserCellValue(int);

        void promptUserRow();
        void promptUserColumn();
        void promptUserValue();
        void promptBoardInput();

    private:
        string name;
        int level; // 1-easy, 2-medium, 3-hard
        int gamesPlayed;
        bool continuePlaying;

        // board input
        char rowLetter;
        int colNum;
        int userCellValue;

};

#endif
