#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int Game::split(string str, char delim, string arr[], int size)
{
    string temp;//Temporary holding space for each section of the original string
    int splits = 0;
    if(str == "")
    {
        splits = 0;//There is no string in order to split
    }
    else
    {
        int current_size = 0;
        str[str.length()] = delim;//In order for the final word to be stored, the delimiter character must be added to the end
        for(int i = 0; i <= str.length(); i++)//Checks every character to see if it is the delimiter character marking a section to split
        {
            if(str[i] != delim)//If the character is not the delimiter character
            {
                temp = temp + str[i];//The temporary string is filled with the characters from the original string 
            }
            else
            {
                if(current_size <= size)//Makes sure the given array has enough space to store the splits
                {
                    if(temp != "")
                    {
                        arr[current_size] = temp;//The temporary word is store in the given array
                        current_size++;//The iterative position of the storage array is incremented
                        temp = "";//The temporary string is emptied for the next word
                        splits++;//The number of splits is incremented by one 
                    }
                }
                else
                {
                    splits = -1;//If there are too many sections than spaces in the storage array, then the splits is given an error value
                }
            }
        }
    }
    return splits;//The number of splits is returned as an integer
}

Game::Game()
{
    numPuzzlePieces = 0;
    maxHealth = 10;
}

int Game::readMap(string fileName)
{
    ifstream mapData;
    string temp;
    int rowCounter = 0;
    int const TEMP_ARR_SIZE = 6;
    string temporary[6];
    mapData.open(fileName);//Opens the file
    
    if(mapData.fail())//If the file is not accessed, then the function returns -1
    {
        return -1;
    }
    else
    {
        while(getline(mapData, temp))//While there are lines to be read from mapData, store them in temp
        {
            if(temp != "")//If the line was not empty
            {
                char delimiter = ',';
                split(temp, delimiter, temporary, TEMP_ARR_SIZE);
                for(int i = 0; i < 6; i++)
                {
                    if(temporary[i] == "L")
                    {
                        rooms[rowCounter][i].changeLockRoom(true);
                    }
                    rooms[rowCounter][i].setRoomType(temporary[i]);//Sets the given room to the type that was found in the same position of the map
                }
            }
            rowCounter++;
        }
    }
    mapData.close();
    return 0;
}

void Game::fight()
{
    /*
    Turn based fight in which the player's and enemy's speed are used to determine
    who attacks first. When the opponent attacks, the player's health is decreased by
    the amount of the strength of the enemy
    The fight ends when either the player's health or the opponent's health reaches 0
    **/
}

void Game::addPuzzlePiece()
{
    numPuzzlePieces++;
}

void Game::searchBackpack()
{
    user.listItems();
}

void Game::printMap()
{
    //Prints a 3x3 grid of the area in which the player is in the middle room
    for(int i = user.getRowPos() - 1; i <= user.getRowPos() + 1; i++)
    {
        for(int k = user.getColPos() - 1; k <= user.getColPos() + 1; k++)
        {
            if(i >= 0 && k >= 0 && i < 6 && k < 6)
            {
                cout << rooms[i][k].getRoomType();
            }
            else
            {
                cout << "-";
            }
            cout << " ";
        }
        cout << endl;
    }
}

void Game::printStats()
{
    cout << "Your stats" << endl;
    cout << "Location: Row " << user.getRowPos() << ", Column " << user.getColPos() << endl;
    cout << "Health: " << user.getHealthPoints() << endl;
    cout << "Hydration Level: " << user.getHydrationLevel() << endl;
    cout << "Speed: " << user.getSpeed() << endl;
}

void Game::writeStats(string oFileName)
{
    //Opens a file stream and writes the stats of the player once they quit or win the game
}

void Game::printObjectsInRoom()
{
    bool enemyPresent = checkForEnemy(user.getRowPos(), user.getColPos());
    bool ItemPresent = checkForItem(user.getRowPos(), user.getColPos());
    if(enemyPresent)
    {
        cout << "When you walk in, you encounter a ";
    }
}

void Game::unlockRoom()
{
    
}

void Game::printMenu()
{
    cout << "What do you do next?" << endl;
    cout << "1. Go to another room" << endl;
    cout << "2. Use an item" << endl;
    cout << "3. Take a rest" << endl;
    cout << "4. Listen to a door" << endl;
    cout << "5. Check the room for anything...unusual." << endl;
    cout << "6. Quit wandering" << endl;
}

void Game::printDirectionMenu()
{
    cout << "What direction would you like to go?" << endl;
    cout << "1. East" << endl;
    cout << "2. North" << endl;
    cout << "3. West" << endl;
    cout << "4. South" << endl;
}

int Game::readEnemies(string fileName)
{
    ifstream enemyData;
    string temp;
    int enemyCounter = 0;
    int const TEMP_ARR_SIZE = 4;
    string temporary[4];
    enemyData.open(fileName);//Opens the file
    
    if(enemyData.fail())//If the file is not accessed, then the function returns -1
    {
        return -1;
    }
    else
    {
        while(getline(enemyData, temp))//While there are lines to be read from enemyData, store them in temp
        {
            if(temp != "")//If the line was not empty
            {
                char delimiter = ',';
                split(temp, delimiter, temporary, TEMP_ARR_SIZE);
                allEnemies[enemyCounter].setEnemyName(temporary[0]);
                allEnemies[enemyCounter].setEnemyHealth(stoi(temporary[1]));
                allEnemies[enemyCounter].setEnemyStrength(stoi(temporary[2]));
                allEnemies[enemyCounter].setEnemySpeed(stoi(temporary[3]));
            }
            enemyCounter++;
        }
    }
    enemyData.close();
    return 0;
}

int Game::useItem(int itemNum)
{
    return 0;
}

bool Game::checkForEnemy(int row, int col)
{
    bool enemyPresent = false;
    return enemyPresent;
}

bool Game::checkForItem(int row, int col)
{
    return false;
}

void Game::movePlayer(int direction)
{
    if(direction == 1)//1 indicates the player chose to move right/east
    {
        if(user.getColPos() >= 0 && user.getColPos() < 5)
        {
            if(rooms[user.getRowPos()][user.getColPos() + 1].isLocked())
            {
                cout << "This door is locked" << endl;
            }
            else
            {
                user.setColPos(user.getColPos() + 1);
            }
        }
        else
        {
            cout << "There is no door there." << endl;
        }
    }
    else if(direction == 2)//2 indicates the player chose to move up/north
    {
        if(user.getRowPos() > 0 && user.getRowPos() <= 5)
        {
            if(rooms[user.getRowPos() - 1][user.getColPos()].isLocked())
            {
                cout << "This door is locked" << endl;
            }
            else
            {
                user.setRowPos(user.getRowPos() - 1);
            }
        }
        else
        {
            cout << "There is no door there." << endl;
        }
    }
    else if(direction == 3)//3 indicates the player chose to move left/west
    {
        if(user.getColPos() > 0 && user.getColPos() <= 5)
        {
            if(rooms[user.getRowPos()][user.getColPos() - 1].isLocked())
            {
                cout << "This door is locked" << endl;
            }
            else
            {
                user.setColPos(user.getColPos() - 1);
            }
        }
        else
        {
            cout << "There is no door there." << endl;
        }
    }
    else if(direction == 4)//4 indicates the player chose to move down/south
    {
        if(user.getRowPos() >= 0 && user.getRowPos() < 5)
        {
            if(rooms[user.getRowPos() + 1][user.getColPos()].isLocked())
            {
                cout << "This door is locked" << endl;
            }
            else
            {
                user.setRowPos(user.getRowPos() + 1);
            }
        }
        else
        {
            cout << "There is no door there." << endl;
        }
    }
}

void Game::takeARest()
{
    if(user.getHealthPoints() < maxHealth)
    {
        user.setHealth(user.getHealthPoints() + 1);
        cout << "You take a rest and find that you've recovered a bit." << endl;
    }
    else
    {
        cout << "You pause for a moment, yet you find yourself right where you started." << endl;
    }
}

int Game::findEnemyIndex(int row, int col)
{
    bool correctRow;
    bool correctCol;
    int counter = 0;
    while(!correctRow && !correctCol)
    {
        correctRow = false;
        correctCol = false;
        if(allEnemies[counter].getEnRowPos() == row)
        {
            correctRow = true;
        }
        if(allEnemies[counter].getEnColPos() == col)
        {
            correctCol = true;
        }
        counter++;
    }
    return counter;
}

void Game::populateEnemies()
{
    //Goes through each location on the map that will have a enemy and assigns the coordinates to that enemy
    int enemyCounter = 0;
    for(int r = 0; r < 6; r++)//r stands for row
    {
        for(int c = 0; c < 6; c++)//c stands for column
        {
            string roomType = rooms[r][c].getRoomType();
            if(roomType == "E" || roomType == "e" || roomType == "L")
            {
                allEnemies[enemyCounter].setEnRowPos(r);
                allEnemies[enemyCounter].setEnColPos(c);
                enemyCounter++;
            }
        }
    }
}

void Game::randomizeItems()
{
    {
    //Goes through each location on the map that will have an item and assigns the item within the room a type
    for(int r = 0; r < 6; r++)//r stands for row
    {
        for(int c = 0; c < 6; c++)//c stands for column
        {
            string roomType = rooms[r][c].getRoomType();
            if(roomType == "E" || roomType == "e")
            {
                
            }
        }
    }
}
}
void Game::TEST_FUNCTION()
{
    cout << "The enemy's name is " <<  allEnemies[13].getEnemyName() << endl;    
    cout << "The enemy's health is " << allEnemies[13].getEnemyHealth() << endl;
    cout << "The enemy's speed is " << allEnemies[13].getEnemySpeed() << endl;
    cout << "The enemy's row is " << allEnemies[13].getEnRowPos() << endl;
    cout << "The enemy's column position is " << allEnemies[13].getEnColPos() << endl;
}