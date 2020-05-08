#include<iostream>
#include "Item.h"
using namespace std;

Item::Item()
{
    itemType = Nothing;
}

int Item::getItemType()
{
    return int(itemType);
}

string Item::getItemName()
{
    return name;
}

void Item::setItemType(int type)
{
    itemType = item_type(type);
}

void Item::setItemName(string itemName)
{
    name = itemName;
}