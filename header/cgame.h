#ifndef CGAME_H
#define CGAME_H

#include "crules.h"
#include "cplayer.h"
#include "cmap.h"

/// \class CGame
/// \brief Class defining current game: players, map and rules
class CGame
{
public:
    /// \brief Default constructor
    CGame();
    /// \brief Overload constructor with parameters to initialize players and rules
    CGame(vector<pair<string, QColor> > player_names_and_colors, bool is_distribution_random, bool are_troops_given_all, string path_to_map = "");

    /// \brief Method which passes the turn to the next player
    void nextPlayer();
    /// \brief Method which checks if the game is finished.
    /// \details If yes it returns the name of the player, otherwise returns empty string
    string checkIfFinished();

    /// \brief Getter for the winner
    string getWinner();
    /// \brief Getter for whose_turn : name and id of player
    pair<string, int> getWhoseTurn();
    /// \brief Method which checks if turn was incremented
    bool getNewTurn();
    /// \brief Getter for turn number
    int getTurn();

    /// \brief Getter for the reference to rules
    CRules &getRules();
    /// \brief Getter for the reference to map
    CMap &getMap();
    /// \brief Getter for reference to all players
    vector<CPlayer> &getPlayers();
    /// \brief Getter for reference to the player of given id
    CPlayer &getPlayer(int id);
    /// \brief Getter for reference to the player of given name
    CPlayer &getPlayer(string name);

private:
    void incrementTurn();

    CRules rules;
    CMap map;
    vector<CPlayer> players;

    string winner;
    pair<string, int> whose_turn;
    bool new_turn;
    int turn;
};

#endif // CGAME_H
