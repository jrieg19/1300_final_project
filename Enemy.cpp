#include "Enemy.h"
#include<iostream>
#include<string>
using namespace std;

Enemy::Enemy()
{
    enRowPos = -1;
    enColPos = -1;
    health = -1;
    strength = -1;
    speed = -1;
}
int Enemy::getEnRowPos()
{
    return enRowPos;
}

int Enemy::getEnColPos()
{
    return enColPos;
}

string Enemy::getEnemyName()
{
    return name;
}

int Enemy::getEnemyHealth()
{
    return health;
}

int Enemy::getEnemyStrength()
{
    return strength;
}

int Enemy::getEnemySpeed()
{
    return speed;
}

void Enemy::setEnRowPos(int enemyRow)
{
    enRowPos = enemyRow;
}

void Enemy::setEnColPos(int enemyCol)
{
    enColPos = enemyCol;
}

void Enemy::setEnemyName(string enemyName)
{
    name = enemyName;
}

void Enemy::setEnemyHealth(int enemyHealth)
{
    health = enemyHealth;
}

void Enemy::setEnemyStrength(int enemyStrength)
{
    strength = enemyStrength;
}

void Enemy::setEnemySpeed(int enemySpeed)
{
    speed = enemySpeed;
}