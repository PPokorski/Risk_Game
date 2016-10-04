#ifndef CMODELVIEW_H
#define CMODELVIEW_H

#include <QObject>
#include "cengine.h"

/// \Class CModelView
/// \brief Class containing game engine
/// \details This class serves as to communicate between game engine and the user interface
class CModelView : public QObject
{
    Q_OBJECT

public:
    /// \brief Default constructor
    CModelView();

    /// \brief Method to initialize a new game
    void executeInit(vector<pair<string, QColor> > players_names_and_colors, bool is_distribution_random, bool are_troops_given_all, string path_to_map = "");
    /// \brief Method to execute attack
    void executeAttack(int attacking, int attacked, int infantry, int archery, int cavalry);
    /// \brief Method to execute moving army
    void executeMoveArmy(int begin, int end, int infantry, int archery, int cavalry);
    /// \brief Method to execute passnig the turn to the next player
    void executePass();
    /// \brief Method to end game
    void executeEndGame();

    /// \brief Getter for the active region
    pair<CRegion, QColor> getActiveRegion();
    /// \brief Getter for the current player
    string getCurrentPlayer();

public slots:
    /// \brief Slots activated when the active region is changed
    void activeRegionChanged(int new_id);

signals:
    /// \brief Signal emited when something is changed with regions
    void regionsColours(vector<QColor> regions_colors);
    /// \brief Signal emited when the current player is changed
    void currentPlayerChaned(string name);
    /// \brief Signal emited when the game is changed
    void gameFinished(string winner);

private:
    vector<QColor> getRegionsColors();

    int active_region;
    CEngine engine;
};

#endif // CMODELVIEW_H
