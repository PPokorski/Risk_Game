#ifndef CPLAYER_H
#define CPLAYER_H

#include <QColor>
#include <vector>
#include "cabstractidentifier.h"
#include "cexceptions.h"

using namespace std;

/// \class CPlayer
/// \brief Class defining player of the game
class CPlayer : public CAbstractIdentifier
{
public:
    /// \brief Default constructor
    CPlayer();
    /// \brief Overloaded constructor for copying
    CPlayer(const CPlayer &player);
    /// \brief Overloaded constructor for initializing with given parameters
    CPlayer(string new_name, int new_id, QColor new_color);

    /// \brief Method which adds id to the owned_regions vector
    void addNewRegion(int new_region);
    /// \brief Method which removes id from the owned_regions vector
    void removeRegion(int old_region);

    /// \brief A setter for the color
    void setColor(QColor new_color);

    /// \brief A getter for the color
    QColor getColor();
    /// \brief A getter for owned_regions
    vector<int> getRegions();

private:
    QColor color;
    vector<int> owned_regions;
};

#endif // CPLAYER_H
