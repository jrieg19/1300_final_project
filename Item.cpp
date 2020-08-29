#include<iostream>
#include "Item.h"
using namespace std;

Item::Item()
{
    name = "null";
}

string Item::getItemName()
{
    return name;
}

void Item::setItemName(string itemName)
{
    name = itemName;
}