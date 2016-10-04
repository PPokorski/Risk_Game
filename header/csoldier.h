#ifndef CSOLDIER_H
#define CSOLDIER_H

#include <cstdlib>
#include <ctime>
#include <string>
#include "cexceptions.h"

using namespace std;
/// \enum Soldats
/// \brief The enum contains types of soldiers
enum Soldats {Infantry, Archery, Cavalry};

/// \class CSoldier
/// \brief The class is a definition of soldier
class CSoldier
{
public:
    /// \brief Default constructor
    CSoldier();
    /// \brief Overloaded constructor for copying
    CSoldier(const CSoldier &soldier);
    /// \brief Overloaded constructor for creating a custom soldier
    CSoldier(int new_health, int new_attack_min, int new_attack_max, int new_speed, int new_amount = 0);
    /// \brief Overloaded constructor for a pre-defined soldier
    /// \param new_type Avalaible types are those defined by enum Soldats
    CSoldier(int new_type, int new_amount = 0);

    /// \brief A setter for amount of soldiers
    void setAmount(int new_amount);
    /// \brief Method for changing amount of soldiers
    /// \param difference If it's negative the number of soldiers decreases
    void changeAmount(int difference);

    /// \brief Method which generates random amount of damage
    /// \details The damage generates varies in range from amount*attack_min to amount*attack_max
    int doDamage();
    /// \brief Decreases amount of soldiers equivalent to received damage
    /// \details The number of soldiers decreased is damage/health + 0.5 for getting the upper floor
    void getDamage(int damage);

    /// \brief A getter for amount
    int getAmount();
    /// \brief A getter for health
    int getHealth();
    /// \brief A getter for attack_min
    int getAttackMin();
    /// \brief A getter for attack_max
    int getAttackMax();
    /// \brief A getter for speed
    int getSpeed();

private:
    int type;

    int amount;
    int health;
    int attack_min;
    int attack_max;
    int speed;
};

#endif // CSOLDIER_H
