#include "header/csoldier.h"

CSoldier::CSoldier()
{
    amount = 0;
    health = 0;
    attack_min = 0;
    attack_max = 0;
    speed = 0;

    srand(time(NULL));
}

CSoldier::CSoldier(const CSoldier &soldier)
{
    type = soldier.type;

    health = soldier.health;
    attack_min = soldier.attack_min;
    attack_max = soldier.attack_max;
    speed = soldier.speed;
    amount = soldier.amount;

    srand(time(NULL));
}

CSoldier::CSoldier(int new_health, int new_attack_min, int new_attack_max, int new_speed, int new_amount)
{
    type = 0;

    health = new_health;
    attack_min = new_attack_min;
    attack_max = new_attack_max;
    speed = new_speed;
    amount = new_amount;

    srand(time(NULL));
}

CSoldier::CSoldier(int new_type, int new_amount)
{
    type = new_type;
    amount = new_amount;

    switch(type)
    {
    case Soldats::Infantry:
        health = 5;
        attack_min = 1;
        attack_max = 3;
        speed = 2;
        break;

    case Soldats::Archery:
        health = 3;
        attack_min = 7;
        attack_max = 10;
        speed = 1;
        break;

    case Soldats::Cavalry:
        health = 4;
        attack_min = 3;
        attack_max = 4;
        speed = 3;
        break;

    default:
        CExceptionWrongSoldierType except(new_type);
        throw except;
    }
}

void CSoldier::setAmount(int new_amount)
{
    amount = new_amount;
}

void CSoldier::changeAmount(int difference)
{
    amount += difference;
}


int CSoldier::doDamage()
{
    int min_damage = amount*attack_min;
    int max_damage = amount*attack_max;

    //Return random value from min_damage to max_damage
    return rand()%(max_damage + 1 - min_damage) + min_damage;
}

void CSoldier::getDamage(int damage)
{
    double loss = (double)damage/health;
    //We want upper floor
    loss += 0.5;

    amount -= loss;
}


int CSoldier::getAmount()
{
    return amount;
}

int CSoldier::getHealth()
{
    return health;
}

int CSoldier::getAttackMin()
{
    return attack_min;
}

int CSoldier::getAttackMax()
{
    return attack_max;
}

int CSoldier::getSpeed()
{
    return speed;
}
