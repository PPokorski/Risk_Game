#include "header/ccontinent.h"

CContinent::CContinent()
{

}

CContinent::CContinent(const CContinent &continent)
{
    name = continent.name;
    id = continent.id;

    regions = continent.regions;
}

CContinent::CContinent(string new_name, int new_id, vector<CRegion *> new_regions)
{
    name = new_name;
    id = new_id;

    regions = new_regions;
}

string CContinent::belongsToOne()
{
    string first_owner = regions.at(0)->getOwner();
    bool belongs_to_one = true;

    for(unsigned int i = 0; i < regions.size(); i++)
    {
        if(first_owner != regions.at(i)->getOwner())
        {
            belongs_to_one = false;
        }
    }

    if(!belongs_to_one)
    {
        first_owner.clear();
    }

    return first_owner;
}
