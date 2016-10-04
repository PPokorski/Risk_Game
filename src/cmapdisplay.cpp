#include "header/cmapdisplay.h"

CMapDisplay::CMapDisplay(QWidget *parent) :
    QLabel(parent)
{
    map = QImage(":/resource/image/MAPA.png");
    map_info = QImage(":/resource/image/MAPA_INFO.png");

    active_region = -1;
}

void CMapDisplay::init()
{
    updateMapToDisplay();
}

void CMapDisplay::regionsColours(vector<QColor> regions_colors)
{
    regions_and_colors = regions_colors;

    updateMap();
}

void CMapDisplay::currentPlayerChanged(string name)
{
    emit activeRegionChanged(active_region);
    emit activeRegionChanged();
}

void CMapDisplay::resizeEvent(QResizeEvent *event)
{
    updateMapToDisplay();
}

void CMapDisplay::mousePressEvent(QMouseEvent *event)
{
    int map_x = calculatePressedCoord(event->x(), event->y()).first;
    int map_y = calculatePressedCoord(event->x(), event->y()).second;

    int r_color = qRed(map_info.pixel(map_x, map_y));

    active_region = colorToId(r_color);

    emit activeRegionChanged(active_region);
    emit activeRegionChanged();

    updateMap();
}

void CMapDisplay::updateMap()
{
    for(int i = 0; i < map_info.width(); i++)
    {
        for(int j = 0; j < map_info.height(); j++)
        {
            int r_color = qRed(map_info.pixel(i, j));
            int id = colorToId(r_color);

            if(id >= 0)
            {
                QColor color = regions_and_colors.at(id);
                map.setPixel(i, j, qRgb(color.red(), color.green(), color.blue()));

                if(id == active_region)
                {
                    QColor active = color.lighter(150);
                    map.setPixel(i, j, qRgb(active.red(), active.green(), active.blue()));
                }
            }
        }
    }

    updateMapToDisplay();
}


void CMapDisplay::updateMapToDisplay()
{
    rescaled = map.scaled(width(), height());
    map_to_display.convertFromImage(rescaled);

    setPixmap(map_to_display);
}

pair<int, int> CMapDisplay::calculatePressedCoord(int clicked_x, int clicked_y)
{
    return make_pair(clicked_x*map_info.width()/width(), clicked_y*map_info.height()/height());
}

int CMapDisplay::colorToId(int red_canal)
{
    int id = (250 - red_canal)/5;

    if(red_canal <= 0 || red_canal%5 != 0 || id >= regions_and_colors.size())
    {
        id = -1;
    }

    return id;
}
