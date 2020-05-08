#include<iostream>
#include<string>
#include "Room.h"
#include "Item.h"
using namespace std;

Room::Room()
{
    locked = false;
}

bool Room::isLocked()
{
    return locked;
}

void Room::setRoomType(string type)
{
    roomType = type;
}

string Room::getRoomType()
{
    return roomType;
}

void Room::changeLockRoom(bool lockState)
{
    locked = lockState;
}
