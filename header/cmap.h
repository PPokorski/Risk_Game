#ifndef CMAP_H
#define CMAP_H

#include "tinyxml2.h"
#include "ccontinent.h"
#include "cregion.h"

using namespace tinyxml2;

/// \class CMap
/// \brief A class defining map
class CMap
{
public:
    /// \brief Default constructor
    CMap();
    /// \brief Overloaded constructor which sets the path_to_map
    /// \param path_to_map The path should point the .xml file defining the structure of map, continents and regions
    CMap(string path_to_map);

    /// \brief A method which checks if regions of given ids are direct neighbours
    bool areRegionsNeighbours(int begin, int end);
    /// \brief A overloaded method which checks if regions of given names are direct neighbours
    bool areRegionsNeighbours(string begin, string end);
    /// \brief A method which checks if regions of given ids are connected by regions in region_to_consider
    /// \details It's main use is checking if there is a connection between two regions of some player
    bool isWayBetweenRegion(int begin, int end, vector<int> region_to_consider);
    /// \brief Overloaded method which checks if regions of given names are connected by regions in region_to_consider
    /// \details It's main use is checking if there is a connection between two regions of some player
    bool isWayBetweenRegion(string begin, string end, vector<int> region_to_consider);
    /// \brief Check if all the continents in the map belong to one player
    /// \return The functions returns the name of the player who owns the whole map. If no one does it returns empty string
    string belongsToOne();

    /// \brief A setter for path_to_map
    void setPathToMap(string new_path);

    /// \brief A getter for reference to all the continents
    vector<CContinent> &getContinents();
    /// \brief A getter for reference to the continent of given id
    CContinent &getContinent(int id);
    /// \brief Overloaded getter for reference to the continent of given name
    CContinent &getContinent(string name);

    /// \brief A getter for reference to all the continents
    vector<CRegion> &getRegions();
    /// \brief A getter for reference to the region of given id
    CRegion &getRegion(int id);
    /// \brief Overloaded getter for reference to the region of given name
    CRegion &getRegion(string name);

private:
    bool areRegionsNeighboursPrivate(CRegion begin, CRegion end);
    bool isWayBetweenRegionPrivate(CRegion begin, CRegion end, vector<int> region_to_consider);

    void loadMap();

    vector<CContinent> continents;
    vector<CRegion> regions;

    string default_path_to_map;
};

#endif // CMAP_H
