#include "header/cmap.h"

CMap::CMap()
{
    default_path_to_map = "map.xml";

    try
    {
        loadMap();
    }
    catch(...)
    {
        throw;
    }
}

CMap::CMap(string path_to_map)
{
    default_path_to_map = path_to_map;

    try
    {
        loadMap();
    }
    catch(...)
    {
        throw;
    }
}

bool CMap::areRegionsNeighbours(int begin, int end)
{
    try
    {
        return areRegionsNeighboursPrivate(getRegion(begin), getRegion(end));
    }
    catch(...)
    {
        throw;
    }

}

bool CMap::areRegionsNeighbours(string begin, string end)
{
    try
    {
        return areRegionsNeighboursPrivate(getRegion(begin), getRegion(end));
    }
    catch(...)
    {
        throw;
    }
}

bool CMap::isWayBetweenRegion(int begin, int end, vector<int> region_to_consider)
{
    try
    {
        return isWayBetweenRegionPrivate(getRegion(begin), getRegion(end), region_to_consider);
    }
    catch(...)
    {
        throw;
    }
}

bool CMap::isWayBetweenRegion(string begin, string end, vector<int> region_to_consider)
{
    try
    {
        return isWayBetweenRegionPrivate(getRegion(begin), getRegion(end), region_to_consider);
    }
    catch(...)
    {
        throw;
    }
}

string CMap::belongsToOne()
{
    string first_owner = continents.at(0).belongsToOne();

    if(first_owner.empty())
    {
        return first_owner;
    }

    for (unsigned int i = 0; i < continents.size(); i++)
    {
        if(first_owner != continents.at(i).belongsToOne())
        {
            first_owner.clear();
            return first_owner;
        }
    }

    return first_owner;
}


void CMap::setPathToMap(string new_path)
{
    default_path_to_map = new_path;
}

vector<CContinent> &CMap::getContinents()
{
    return continents;
}

CContinent &CMap::getContinent(int id)
{
    for(unsigned int i = 0; i < continents.size(); i++)
    {
        if(continents.at(i).getId() == id)
        {
            return continents.at(i);
        }
    }

    CExceptionNoRegionContinentPlayer except(id);
    throw except;
}

CContinent &CMap::getContinent(string name)
{
    for(unsigned int i = 0; i < continents.size(); i++)
    {
        if(continents.at(i).getName() == name)
        {
            return continents.at(i);
        }
    }

    CExceptionNoRegionContinentPlayer except(name);
    throw except;
}

vector<CRegion> &CMap::getRegions()
{
    return regions;
}

CRegion &CMap::getRegion(int id)
{
    for(unsigned int i = 0; i < regions.size(); i++)
    {
        if(regions.at(i).getId() == id)
        {
            return regions.at(i);
        }
    }

    CExceptionNoRegionContinentPlayer except(id);
    throw except;
}

CRegion &CMap::getRegion(string name)
{
    for(unsigned int i = 0; i < regions.size(); i++)
    {
        if(regions.at(i).getName() == name)
        {
            return regions.at(i);
        }
    }

    CExceptionNoRegionContinentPlayer except(name);
    throw except;
}

bool CMap::areRegionsNeighboursPrivate(CRegion begin, CRegion end)
{
    int i_end = end.getId();

    for(unsigned int i = 0; i < begin.getPaths().size(); i++)
    {
        if(begin.getPaths().at(i) == i_end)
        {
            return true;
        }
    }

    return false;
}

bool CMap::isWayBetweenRegionPrivate(CRegion begin, CRegion end, vector<int> region_to_consider)
{
    int i_begin = begin.getId();
    int i_end = end.getId();

    vector<int> visited;
    vector<int> visited_to_check;

    visited.push_back(i_begin);
    visited_to_check.push_back(i_begin);

    while(!visited.empty())
    {
        int current = visited.back();
        visited.pop_back();

        if(current == i_end)
        {
            return true;
        }

        for(unsigned int i = 0; i < getRegion(current).getPaths().size(); i++)
        {
            bool was_visited = false;
            for(unsigned int j = 0; j < visited_to_check.size(); j++)
            {
                if(visited_to_check.at(j) == getRegion(current).getPaths().at(i))
                {
                    was_visited = true;
                }
            }

            bool to_ignore = true;
            for(unsigned int j = 0; j < region_to_consider.size(); j++)
            {
                if(region_to_consider.at(j) == getRegion(current).getPaths().at(i))
                {
                    to_ignore = false;
                }
            }

            if(was_visited || to_ignore)
            {
                continue;
            }
            else
            {
                visited.push_back(getRegion(current).getPaths().at(i));
                visited_to_check.push_back(getRegion(current).getPaths().at(i));
            }
        }
    }

    return false;
}

void CMap::loadMap()
{
    const char *map = default_path_to_map.c_str();

    XMLDocument doc;
    XMLError result = doc.LoadFile(map);
    if(result != XML_SUCCESS)
    {
        throw result;
    }

    int total_number_of_regions = 0;
    int number_of_continents;

    doc.FirstChildElement()->FirstChildElement("number_of_continents")->QueryIntText(&number_of_continents);

    for (int i = 0; i < number_of_continents; i++)
    {
        string string_continent_tmp = "continent";
        string_continent_tmp += to_string(i);

        int number_of_regions;

        XMLElement *continent_element = doc.FirstChildElement("map")->FirstChildElement(string_continent_tmp.c_str());
        continent_element->FirstChildElement("number_of_regions")->QueryIntText(&number_of_regions);

        total_number_of_regions += number_of_regions;
    }

    regions.reserve(total_number_of_regions);

    for (int i = 0; i < number_of_continents; i++)
    {
        string string_continent_tmp = "continent";
        string_continent_tmp += to_string(i);

        string continent_name_tmp;
        int continent_id_tmp;
        int number_of_regions;

        vector<CRegion *> _regions;

        XMLElement *continent_element = doc.FirstChildElement("map")->FirstChildElement(string_continent_tmp.c_str());

        continent_name_tmp = continent_element->FirstChildElement("name")->GetText();
        continent_element->FirstChildElement("id")->QueryIntText(&continent_id_tmp);
        continent_element->FirstChildElement("number_of_regions")->QueryIntText(&number_of_regions);

        for(int j = 0; j < number_of_regions; j++)
        {
            string string_region_tmp = "region";
            string_region_tmp += to_string(j);

            string region_name_tmp;
            int region_id_tmp;
            int number_of_paths;

            vector<int> paths;

            int initial_infantry;
            int initial_archer;
            int initial_cavalry;

            int infantry_income;
            int archer_income;
            int cavalry_income;

            XMLElement *region_element = continent_element->FirstChildElement(string_region_tmp.c_str());

            region_name_tmp = region_element->FirstChildElement("name")->GetText();
            region_element->FirstChildElement("id")->QueryIntText(&region_id_tmp);
            region_element->FirstChildElement("paths")->FirstChildElement("number_of_paths")->QueryIntText(&number_of_paths);

            for(int k = 0; k < number_of_paths; k++)
            {
                int path;
                string string_path_tmp = "path";
                string_path_tmp += to_string(k);

                region_element->FirstChildElement("paths")->FirstChildElement(string_path_tmp.c_str())->QueryIntText(&path);
                paths.push_back(path);
            }

            region_element->FirstChildElement("initial_infantry")->QueryIntText(&initial_infantry);
            region_element->FirstChildElement("initial_archer")->QueryIntText(&initial_archer);
            region_element->FirstChildElement("initial_cavalry")->QueryIntText(&initial_cavalry);

            region_element->FirstChildElement("infantry_income")->QueryIntText(&infantry_income);
            region_element->FirstChildElement("archer_income")->QueryIntText(&archer_income);
            region_element->FirstChildElement("cavalry_income")->QueryIntText(&cavalry_income);

            CRegion region;

            try
            {
                region = CRegion(region_name_tmp, region_id_tmp, paths, "", initial_infantry, initial_archer, initial_cavalry, infantry_income, archer_income, cavalry_income);
            }
            catch(...)
            {
                throw;
            }

            regions.push_back(region);
            _regions.push_back(&(regions.back()));
        }

        CContinent continent(continent_name_tmp, continent_id_tmp, _regions);
        continents.push_back(continent);
    }
}
