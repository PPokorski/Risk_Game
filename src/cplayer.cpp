#include "header/cplayer.h"

CPlayer::CPlayer()
{

}

CPlayer::CPlayer(const CPlayer &player)
{
    name = player.name;
    id = player.id;
    color = player.color;
    owned_regions = player.owned_regions;
}

CPlayer::CPlayer(string new_name, int new_id, QColor new_color)
{
    name = new_name;
    id = new_id;
    color = new_color;
}

void CPlayer::addNewRegion(int new_region)
{
    owned_regions.push_back(new_region);
}

void CPlayer::removeRegion(int old_region)
{
    int index = -1;

    for(unsigned int i = 0; i < owned_regions.size(); i++)
    {
        if(owned_regions.at(i) == old_region)
        {
            index = i;
        }
    }
    if(index < 0)
    {
        CExceptionNoRegionAtPlayer except(name, old_region);
        throw except;
    }
    else
    {
        owned_regions.erase(owned_regions.begin() + index);
    }
}

void CPlayer::setColor(QColor new_color)
{
    color = new_color;
}

QColor CPlayer::getColor()
{
    return color;
}

vector<int> CPlayer::getRegions()
{
    return owned_regions;
}
