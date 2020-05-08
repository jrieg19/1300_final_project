#ifndef ROOM_H
#define ROOM_H
#include<string>
#include "Item.h"

class Room
{
    private:
        bool locked;
        string roomType;
        Item roomItem;
        
    public:
        Room();
        //----------Getters
        bool isLocked();
        Item getRoomItem();
        string getRoomType();
        //---------Setters
        void changeLockRoom(bool);
        void setRoomItem(int);
        void setRoomType(string);

};

#endif