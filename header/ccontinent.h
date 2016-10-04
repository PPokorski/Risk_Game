#ifndef CCONTINENT_H
#define CCONTINENT_H

#include "cregion.h"

/// \class CContinent
/// \brief A class defining continent, containing pointers to regions
class CContinent : public CAbstractIdentifier
{
public:
    /// \brief Default constructor
    CContinent();
    /// \brief Overloaded constructor for copying
    CContinent(const CContinent &continent);
    /// \brief Overloaded constructor for initializing with right parameters
    CContinent(string new_name, int new_id, vector<CRegion *> new_regions);

    /// \brief Check if all the regions in continent belong to one player
    /// \return The functions returns the name of the player who owns the whole continent. If no one does it returns empty string
    string belongsToOne();

private:
    vector<CRegion *> regions;
};

#endif // CCONTINENT_H
