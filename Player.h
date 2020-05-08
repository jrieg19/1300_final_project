//CS1300 Fall 2019
//Author: Jason Rieger
//Recitation 303
//Project 3
#include<iostream>
#include<vector>
#include<string>
#include "Item.h"
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private:
        int rowPos;
        int columnPos;
        string name;
        int healthPoints;
        int hydrationLevel;
        double speed;
        Item backpack[10]; //Can hold a max of 10 items
        int numItems;
        
    public:
        //--------------Constructor
        Player();
        //--------------Getters
        int getRowPos();//---------------
        int getColPos();//---------------
        string getName();//-------------
        int getHealthPoints();//---------
        int getHydrationLevel();//----------
        double getSpeed();//------------
        void listItems();
        //-------------Setters
        void setRowPos(int);//-----------
        void setColPos(int);//-----------
        void setName(string);//----------
        void setHealth(int);//----------
        void setHydrationLevel(int);//----------
        void setSpeed(double);
};

#endif