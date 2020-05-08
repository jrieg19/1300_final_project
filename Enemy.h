#ifndef ENEMY_H
#define ENEMY_H
#include<string>
using namespace std;
class Enemy
{
    private:
        int enRowPos;
        int enColPos;
        string name;
        int health;
        int strength;
        int speed;
    public:
        //-------------Constructor
        Enemy();
        //-------------Getters
        int getEnRowPos();
        int getEnColPos();
        string getEnemyName();
        int getEnemyHealth();
        int getEnemyStrength();
        int getEnemySpeed();
        //--------------Setters
        void setEnRowPos(int);
        void setEnColPos(int);
        void setEnemyName(string);
        void setEnemyHealth(int);
        void setEnemyStrength(int);
        void setEnemySpeed(int);
};

#endif