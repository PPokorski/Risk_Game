#include "header/cgame.h"

CGame::CGame()
{

}

CGame::CGame(vector<pair<string, QColor> > player_names_and_colors,
             bool is_distribution_random, bool are_troops_given_all,
             string path_to_map)
{
    rules = CRules(is_distribution_random, are_troops_given_all);

    try
    {
        if(path_to_map.empty())
        {
            map = CMap();
        }
        else
        {
            map = CMap(path_to_map);
        }
    }
    catch(...)
    {
        throw;
    }

    new_turn = true;
    turn = 0;

    for(unsigned int i = 0; i < player_names_and_colors.size(); i++)
    {
        CPlayer tmp(player_names_and_colors.at(i).first, i, player_names_and_colors.at(i).second);
        players.push_back(tmp);
    }

    whose_turn.first = players.at(0).getName();
    whose_turn.second = 0;
}


void CGame::nextPlayer()
{
    if(players.size() == whose_turn.second + 1)
    {
        whose_turn.first = players.at(0).getName();
        whose_turn.second = 0;

        incrementTurn();

        new_turn = true;
    }
    else
    {
        whose_turn.first = players.at(whose_turn.second + 1).getName();
        whose_turn.second ++;

        new_turn = false;
    }
}

void CGame::incrementTurn()
{
    turn++;
}

string CGame::checkIfFinished()
{
    winner = map.belongsToOne();

    return winner;
}

CRules &CGame::getRules()
{
    return rules;
}

CMap &CGame::getMap()
{
    return map;
}

vector<CPlayer> &CGame::getPlayers()
{
    return players;
}

CPlayer &CGame::getPlayer(int id)
{
    for(unsigned int i = 0; i < players.size(); i++)
    {
        if(players.at(i).getId() == id)
        {
            return players.at(i);
        }
    }

    CExceptionNoRegionContinentPlayer except(id);
    throw except;
}

CPlayer &CGame::getPlayer(string name)
{
    for(unsigned int i = 0; i < players.size(); i++)
    {
        if(players.at(i).getName() == name)
        {
            return players.at(i);
        }
    }

    CExceptionNoRegionContinentPlayer except(name);
    throw except;
}

string CGame::getWinner()
{
    return winner;
}

pair<string, int> CGame::getWhoseTurn()
{
    return whose_turn;
}

bool CGame::getNewTurn()
{
    return new_turn;
}

int CGame::getTurn()
{
    return turn;
}
