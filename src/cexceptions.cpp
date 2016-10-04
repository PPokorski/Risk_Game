#include "header/cexceptions.h"

CAbstractException::CAbstractException()
{
    initTitle();
}

string CAbstractException::what()
{
    return title;
}

void CAbstractException::initTitle()
{
    title = "Exception!";
}


CExceptionNoRegionContinentPlayer::CExceptionNoRegionContinentPlayer()
{
    initTitle();
}

CExceptionNoRegionContinentPlayer::CExceptionNoRegionContinentPlayer(int id)
{
    initTitle();
    title += ("id " + to_string(id));
}

CExceptionNoRegionContinentPlayer::CExceptionNoRegionContinentPlayer(string name)
{
    initTitle();
    title += ("name " + name);
}

void CExceptionNoRegionContinentPlayer::initTitle()
{
    title = "Found no continent or region or player with ";
}


CExceptionWrongSoldierType::CExceptionWrongSoldierType()
{
    initTitle();
}

CExceptionWrongSoldierType::CExceptionWrongSoldierType(int type)
{
    initTitle();
    title += to_string(type);
}

void CExceptionWrongSoldierType::initTitle()
{
    title = "There's no such soldier type as: ";
}


CExceptionNoRegionAtPlayer::CExceptionNoRegionAtPlayer()
{
    initTitle();
}

CExceptionNoRegionAtPlayer::CExceptionNoRegionAtPlayer(string name, int id)
{
    initTitle();
    title += (name + "has no region " + to_string(id));
}

void CExceptionNoRegionAtPlayer::initTitle()
{
    title = "The player ";
}
