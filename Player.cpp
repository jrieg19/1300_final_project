#include<iostream>
#include<vector>
#include "Player.h"
#include "Item.h"
using namespace std;

Player::Player()//Player constructor 
{
    rowPos = 5;
    columnPos = 2;
    healthPoints = 10;
    hydrationLevel = 10;
    speed = 8;
    numItems = 0;
}

int Player::getRowPos()
{
    return rowPos;
}

int Player::getColPos()
{
    return columnPos;
}

string Player::getName()
{
    return name;
}

int Player::getHealthPoints()
{
    return healthPoints;
}

int Player::getHydrationLevel()
{
    return hydrationLevel;
}

double Player::getSpeed()
{
    return speed;
}

void Player::listItems()
{
    for(int i = 0; i < numItems; i++)
    {
        //Lists the name of each item and the position it is at in their backpack
    }
}

void Player::setRowPos(int row)
{
    rowPos = row;
}

void Player::setColPos(int col)
{
    columnPos = col;
}
void Player::setName(string _name)
{
    name = _name;
}

void Player::setHealth(int health)
{
    healthPoints = health;
}

void Player::setHydrationLevel(int hydration)
{
    hydrationLevel = hydration;
}

void Player::setSpeed(double _speed)
{
    speed = _speed;
}
