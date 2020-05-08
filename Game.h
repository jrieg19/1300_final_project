#include<string>
#include<iostream>
#include "Player.h"
#include "Room.h"
#include "Enemy.h"
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        Player user;
        int maxHealth;
        const int maxPuzzlePieces = 3;
        int const NUM_ENEMIES = 14;
        Room rooms[6][6];
        Enemy allEnemies[14];
        int numPuzzlePieces;
        int split(string, char, string[], int);
        
        
    public:  
        Game();
        int readMap(string);//--------------
        void fight();
        void addPuzzlePiece();//---------------
        void searchBackpack();
        void printMap();//-------------
        void printStats();//------------
        void writeStats(string);
        void printObjectsInRoom();
        void unlockRoom();//----------
        void printMenu();//
        void printDirectionMenu();//-----------
        int readEnemies(string);//-----------
        int useItem(int);
        bool checkForEnemy(int, int);
        bool checkForItem(int, int);
        void movePlayer(int);//------------
        void takeARest();//--------------
        int findEnemyIndex(int, int);
        void randomizeItems();
        void populateEnemies();
        
        void TEST_FUNCTION();
};

#endif