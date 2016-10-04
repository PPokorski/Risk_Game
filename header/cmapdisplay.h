#ifndef CMAPDISPLAY_H
#define CMAPDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QColor>
#include <vector>
#include <QDebug>

using namespace std;

/// \class CMapDisplay
/// \brief Class inheriting from QLabel responsible for displaying the map and mouse, resize events
class CMapDisplay : public QLabel
{
    Q_OBJECT
public:
    /// \brief Default constructor
    CMapDisplay(QWidget *parent = 0);

    /// \brief Method initializing the instance of the class, executing first map upate
    void init();

public slots:
    /// \brief Slots which gets the colors of region and updates the map
    void regionsColours(vector<QColor> regions_colors);
    /// \brief Slots which is activated when current player is changed to update active region
    void currentPlayerChanged(string name);

signals:
    /// \brief Signal which is emited after clicking on a region providing its it
    void activeRegionChanged(int new_id);
    /// \brief Signal which is emited after clicking on a region
    void activeRegionChanged();

private:
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void updateMap();

    void updateMapToDisplay();
    pair<int, int> calculatePressedCoord(int clicked_x, int clicked_y);
    int colorToId(int red_canal);


    QImage map;
    QImage map_info;
    QImage rescaled;

    QPixmap map_to_display;

    vector<QColor> regions_and_colors;
    int active_region;
};

#endif // CMAPDISPLAY_H
