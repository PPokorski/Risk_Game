#include "header/cmodelview.h"

CModelView::CModelView()
{

}

void CModelView::executeInit(vector<pair<string, QColor> > players_names_and_colors, bool is_distribution_random, bool are_troops_given_all, string path_to_map)
{
    try
    {
        engine.initGame(players_names_and_colors, is_distribution_random, are_troops_given_all, path_to_map);
        engine.giveRandomRegions();
    }
    catch(...)
    {
        throw;
    }

    emit regionsColours(getRegionsColors());
    emit currentPlayerChaned(engine.getGame().getWhoseTurn().first);
}

void CModelView::executeAttack(int attacking, int attacked, int infantry, int archery, int cavalry)
{
    try
    {
        engine.attack(attacking, attacked, infantry, archery, cavalry);
    }
    catch(...)
    {
        throw;
    }

    emit regionsColours(getRegionsColors());

    string winner = engine.getGame().getWinner();

    if(!winner.empty())
    {
        emit gameFinished(winner);
    }
}

void CModelView::executeMoveArmy(int begin, int end, int infantry, int archery, int cavalry)
{
    try
    {
        engine.moveArmy(begin, end, infantry, archery, cavalry);
    }
    catch(...)
    {
        throw;
    }
}

void CModelView::executePass()
{
    engine.pass();
    engine.giveTroops();

    emit currentPlayerChaned(engine.getGame().getWhoseTurn().first);
}

void CModelView::executeEndGame()
{
    engine.endGame();
}

pair<CRegion, QColor> CModelView::getActiveRegion()
{
    return make_pair(engine.getGame().getMap().getRegion(active_region), engine.getGame().getPlayer(engine.getGame().getMap().getRegion(active_region).getOwner()).getColor());
}

string CModelView::getCurrentPlayer()
{
    return engine.getGame().getWhoseTurn().first;
}

void CModelView::activeRegionChanged(int new_id)
{
    active_region = new_id;
}

vector<QColor> CModelView::getRegionsColors()
{
    vector<QColor> regions;

    for(unsigned int i = 0; i < engine.getGame().getMap().getRegions().size(); i++)
    {
        QColor color = engine.getGame().getPlayer(engine.getGame().getMap().getRegions().at(i).getOwner()).getColor();

        regions.push_back(color);
    }

    return regions;
}
