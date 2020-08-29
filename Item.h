#ifndef ITEM_H
#define ITEM_H
#include<string>
using namespace std;


class Item
{
    private:
        string name;
    public:
        //------------Constructor
        Item();
        //------------Getters
        string getItemName();//DONE
        //------------setters
        void setItemName(string);//DONE
};

#endif