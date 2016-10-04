#ifndef CENGINE_H
#define CENGINE_H

#include "cgame.h"

/// \class CEngine
/// \brief Class responsible for game mechanics
class CEngine
{
public:
    /// \brief Default constructor
    CEngine();
    /// \brief Default destructor
    ~CEngine();


    /// \brief Method which executes attack from one region to another with given number of troops
    void attack(int attacking, int attacked, int infantry, int archery, int cavalry);
    /// \brief Overload method which executes attack from one region to another with given number of troops
    void attack(string attacking, string attacked, int infantry, int archery, int cavalry);
    /// \brief Method which executes moving army from one region to another
    void moveArmy(int begin, int end, int infantry, int archery, int cavalry);
    /// \brief Overload method which executes moving army from one region to another
    void moveArmy(string begin, string end, int infantry, int archery, int cavalry);
    /// \brief Method which executes passing turn to the next player
    void pass();
    /// \brief Method which executes income considering rules
    void giveTroops();
    /// \brief Method which distributes all regions randomly among players
    void giveRandomRegions();
    /// \brief Method which creates new instance of game
    void initGame(vector<pair<string, QColor> > players_names_and_colors, bool is_distribution_random, bool are_troops_given_all, string path_to_map = "");
    /// \brief Method which destroy an instance of game
    void endGame();

    /// \brief getter for the game
    CGame &getGame();

private:
    void privateAttack(int attack_infantry, int attack_archery, int attack_cavalry, CRegion &attacked);
    void attackWithOneTroop(CSoldier &troop, CRegion &attacked_region);
    void attackOneTroop(CSoldier &troop, CRegion &attacked_region, int attacked_troop);

    CGame *game;
};

#endif // CENGINE_H
