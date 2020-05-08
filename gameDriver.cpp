//CS1300 Fall 2019 
//Author: Jason Rieger
//Recitation 303
//Project 3
#include<iostream>
#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "Enemy.h"
#include<string>
using namespace std;

int main()
{
    //------------------------Initialization of Game, players, enemies and items----------------
    Game game;
    bool quit = false;
    game.readMap("map.txt");
    game.readEnemies("enemies.txt");
    game.populateEnemies();
    game.TEST_FUNCTION();
    //------------------------While loop everytime the player goes through an action / menu option
    while(!quit)
    {
        cout << endl;
        game.printStats();
        game.printMap();//Shows the player where they are in the dungeon from the map every turn
        game.printMenu();
        string _choice;
        int choice;
        getline(cin, _choice);
        choice = stoi(_choice);
        switch(choice)
        {
            case 1://Move on map/to another room
            {
                game.printDirectionMenu();
                getline(cin, _choice);
                choice = stoi(_choice);
                game.movePlayer(choice);
                break;
            }
            case 2:
            {
                
            }
            case 6:
            {
                quit = true;
                break;
            }
        }
    }
    
    
    return 0;
}