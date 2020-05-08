#ifndef ITEM_H
#define ITEM_H
#include<string>
using namespace std;
enum item_type
{
    Nothing = 0,
    Sword = 1,
    Axe = 2,
    Bandage = 3,
    WaterBottle = 4, 
    Potion = 5,
    Key = 6
};

class Item
{
    private:
        item_type itemType;
        string name;
    public:
        //------------Constructor
        Item();
        //------------Getters
        int getItemType();
        string getItemName();
        //------------setters
        void setItemType(int);
        void setItemName(string);
};

#endif