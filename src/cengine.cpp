#include "header/cengine.h"

CEngine::CEngine()
{

}

CEngine::~CEngine()
{
    if(game != NULL)
    {
        delete game;
    }
}

CGame &CEngine::getGame()
{
    return *game;
}


void CEngine::attack(int attacking, int attacked, int infantry, int archery, int cavalry)
{
    if(!(game->getMap().areRegionsNeighbours(attacking, attacked)))
    {
        return;
    }
    game->getMap().getRegion(attacking).increaseTroops(-infantry, -archery, -cavalry);

    CRegion &region = game->getMap().getRegion(attacked);

    try
    {
        privateAttack(infantry, archery, cavalry, region);
    }
    catch(...)
    {
        game->getMap().getRegion(attacking).increaseTroops(infantry, archery, cavalry);
        throw;
    }
}

void CEngine::attack(string attacking, string attacked, int infantry, int archery, int cavalry)
{
    if(!(game->getMap().areRegionsNeighbours(attacking, attacked)))
    {
        return;
    }
    game->getMap().getRegion(attacking).increaseTroops(-infantry, -archery, -cavalry);

    CRegion &region = game->getMap().getRegion(attacked);

    try
    {
        privateAttack(infantry, archery, cavalry, region);
    }
    catch(...)
    {
        game->getMap().getRegion(attacking).increaseTroops(infantry, archery, cavalry);
        throw;
    }
}

void CEngine::moveArmy(int begin, int end, int infantry, int archery, int cavalry)
{
    try
    {
        if(!(game->getMap().isWayBetweenRegion(begin, end, game->getPlayer(game->getWhoseTurn().first).getRegions())))
        {
            return;
        }

        game->getMap().getRegion(begin).increaseTroops(-infantry, -archery, -cavalry);
        game->getMap().getRegion(end).increaseTroops(infantry, archery, cavalry);
    }
    catch(...)
    {
        throw;
    }
}

void CEngine::moveArmy(string begin, string end, int infantry, int archery, int cavalry)
{
    try
    {
        if(!(game->getMap().isWayBetweenRegion(begin, end, game->getPlayer(game->getWhoseTurn().first).getRegions())))
        {
            return;
        }

        game->getMap().getRegion(begin).increaseTroops(-infantry, -archery, -cavalry);
        game->getMap().getRegion(end).increaseTroops(infantry, archery, cavalry);
    }
    catch(...)
    {
        throw;
    }
}

void CEngine::initGame(vector<pair<string, QColor> > players_names_and_colors, bool is_distribution_random, bool are_troops_given_all, string path_to_map)
{
    try
    {
        game = new CGame(players_names_and_colors, is_distribution_random, are_troops_given_all, path_to_map);
    }
    catch(...)
    {
        throw;
    }
}

void CEngine::pass()
{
    game->nextPlayer();
}

void CEngine::giveTroops()
{
    if(game->getRules().getTroopsGivenToAll())
    {
        if(game->getNewTurn())
        {
            for(unsigned int i = 0; i < game->getMap().getRegions().size(); i++)
            {
                game->getMap().getRegions().at(i).increaseTroops();
            }
        }
    }
    else
    {
        for(unsigned int i = 0; i < game->getPlayer(game->getWhoseTurn().second).getRegions().size(); i++)
        {
            int index = game->getPlayer(game->getWhoseTurn().second).getRegions().at(i);
            game->getMap().getRegion(index).increaseTroops();
        }
    }
}

void CEngine::giveRandomRegions()
{
    srand(time(NULL));

    vector<int> regions_id;
    for(unsigned int i = 0; i < game->getMap().getRegions().size(); i++)
    {
        regions_id.push_back(game->getMap().getRegions().at(i).getId());
    }

    while(!regions_id.empty())
    {
        for(unsigned int i = 0; i < game->getPlayers().size(); i++)
        {
            if(regions_id.empty())
            {
                return;
            }
            else
            {
                int region = rand()%regions_id.size();
                game->getPlayers().at(i).addNewRegion(regions_id.at(region));
                game->getMap().getRegion(regions_id.at(region)).setOwner(game->getPlayers().at(i).getName());
                regions_id.erase(regions_id.begin() + region);
            }
        }
    }
}

void CEngine::endGame()
{
    delete game;
}

void CEngine::privateAttack(int attack_infantry, int attack_archery, int attack_cavalry, CRegion &attacked)
{
    CSoldier infantry;
    CSoldier archery;
    CSoldier cavalry;

    try
    {
        infantry = CSoldier(Soldats::Infantry, attack_infantry);
        archery = CSoldier(Soldats::Archery, attack_archery);
        cavalry = CSoldier(Soldats::Cavalry, attack_cavalry);
    }
    catch(...)
    {
        throw;
    }

    bool lasts = true;

    while(lasts)
    {
        attackWithOneTroop(cavalry, attacked);
        attackWithOneTroop(infantry, attacked);
        attackWithOneTroop(archery, attacked);

        if(infantry.getAmount() <= 0)
        {
            if(archery.getAmount() <= 0)
            {
                if(cavalry.getAmount() <= 0)
                {
                    lasts = false;
                }
            }
        }
        else
        {
            if(attacked.getTroops(Soldats::Infantry).getAmount() <= 0)
            {
                if(attacked.getTroops(Soldats::Archery).getAmount() <= 0)
                {
                    if(attacked.getTroops(Soldats::Cavalry).getAmount() <= 0)
                    {
                        lasts = false;

                        game->getPlayer(attacked.getOwner()).removeRegion(attacked.getId());
                        game->getPlayer(game->getWhoseTurn().first).addNewRegion(attacked.getId());

                        attacked.setOwner(game->getWhoseTurn().first);
                        int remain_inf = 0;
                        int remain_arch = 0;
                        int remain_cav = 0;

                        if(infantry.getAmount() > 0)
                        {
                            remain_inf = infantry.getAmount();
                        }
                        if(archery.getAmount() > 0)
                        {
                            remain_arch = archery.getAmount();
                        }
                        if(cavalry.getAmount() > 0)
                        {
                            remain_cav = cavalry.getAmount();
                        }

                        attacked.setTroopsNumbers(remain_inf, remain_arch, remain_cav);
                    }
                }
            }
        }
    }

    game->checkIfFinished();
}

void CEngine::attackWithOneTroop(CSoldier &troop, CRegion &attacked_region)
{
    if(troop.getAmount() > 0)
    {
        if(attacked_region.getTroops(Soldats::Cavalry).getAmount() > 0)
        {
            attackOneTroop(troop, attacked_region, Soldats::Cavalry);
        }
        else
        {
            if(attacked_region.getTroops(Soldats::Infantry).getAmount() > 0)
            {
                attackOneTroop(troop, attacked_region, Soldats::Infantry);
            }
            else
            {
                if(attacked_region.getTroops(Soldats::Archery).getAmount() > 0)
                {
                    attackOneTroop(troop, attacked_region, Soldats::Archery);
                }
            }
        }
    }
}

void CEngine::attackOneTroop(CSoldier &troop, CRegion &attacked_region, int attacked_troop)
{
    attacked_region.getTroops(attacked_troop).getDamage(troop.doDamage());
    if(attacked_region.getTroops(attacked_troop).getAmount() > 0) troop.getDamage(attacked_region.getTroops(attacked_troop).doDamage());
}
