#ifndef __AI_H__
#define __AI_H__
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include <windows.h>


class Player {
    public:
    void setPlayer(bool newPlayer); //Change the active player = new turn
    bool getPlayer(); //Gives the active player
    
    Player();
    
    private:
    bool player;
    
};

class Box {
    public:
    bool Empty; //Indicates if a token is in the box
    void setBox(Player player, bool token); //Play or cancel a play
    bool isEmpty(); //Indicates if a Box is Empty or not
    bool whichColor(); //Indicate the color of the token (true = AI)
    
    Box();
    
    private:
    Player color; //Whose is the token if any
    
};

class Board {
    
    public:
    int getScoreWinLose(Player P); //Actual Score in the board for the AI
    void setToken(int row, Player player); //Place a Token on the first Box available
    void cancelPlay(int row); //Cancel last token played in selected row
    void setBox(int line, int row, Player player, bool token); //Set Boxes to modify or init the playboard
    Box getBox(int line, int row); //get the box state on selected line and row (empty or not, color of the token)
    Board(Box tab[6][7], int line, int row);
    
    private:
    Box array[6][7];
    
    
};


#endif
