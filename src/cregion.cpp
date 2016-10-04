#include "header/cregion.h"

CRegion::CRegion()
{
    try
    {
        infantry = CSoldier(Soldats::Infantry);
        archer = CSoldier(Soldats::Archery);
        cavalry = CSoldier(Soldats::Cavalry);
    }
    catch(...)
    {
        throw;
    }

}

CRegion::CRegion(const CRegion &region)
{
    infantry = region.infantry;
    archer = region.archer;
    cavalry = region.cavalry;

    name = region.name;
    id = region.id;
    paths = region.paths;
    owner = region.owner;

    infantry_income = region.infantry_income;
    archery_income = region.archery_income;
    cavalry_income = region.cavalry_income;
}

CRegion::CRegion(string new_name, int new_id, vector<int> new_paths, string new_owner,
                 int start_inf, int start_arch, int start_cav, int new_inf_income,
                 int new_arch_income, int new_cav_income)
{
    try
    {
        infantry = CSoldier(Soldats::Infantry, start_inf);
        archer = CSoldier(Soldats::Archery, start_arch);
        cavalry = CSoldier(Soldats::Cavalry, start_cav);
    }
    catch(...)
    {
        throw;
    }

    name = new_name;
    id = new_id;
    paths = new_paths;
    owner = new_owner;

    infantry_income = new_inf_income;
    archery_income = new_arch_income;
    cavalry_income = new_cav_income;
}

void CRegion::increaseTroops()
{
    infantry.changeAmount(infantry_income);
    archer.changeAmount(archery_income);
    cavalry.changeAmount(cavalry_income);
}

void CRegion::increaseTroops(int infantry_number, int archery_number, int cavalry_number)
{
    infantry.changeAmount(infantry_number);
    archer.changeAmount(archery_number);
    cavalry.changeAmount(cavalry_number);
}

void CRegion::setPaths(vector<int> new_paths)
{
    paths = new_paths;
}

void CRegion::setTroopsNumbers(int infantry_number, int archery_number, int cavalry_number)
{
    infantry.setAmount(infantry_number);
    archer.setAmount(archery_number);
    cavalry.setAmount(cavalry_number);
}

void CRegion::setInfantryIncome(int new_income)
{
    infantry_income = new_income;
}

void CRegion::setArcherIncome(int new_income)
{
    archery_income = new_income;
}

void CRegion::setCavalryIncome(int new_income)
{
    cavalry_income = new_income;
}

void CRegion::setOwner(string new_owner)
{
    owner = new_owner;
}

CSoldier &CRegion::getTroops(int type)
{
    switch(type)
    {
    case Soldats::Infantry:
        return infantry;

    case Soldats::Archery:
        return archer;

    case Soldats::Cavalry:
        return cavalry;

    default:
        CExceptionWrongSoldierType except(type);
        throw except;
    }
}

vector<int> CRegion::getPaths()
{
    return paths;
}

int CRegion::getInfantryIncome()
{
    return infantry_income;
}

int CRegion::getArcherIncome()
{
    return archery_income;
}

int CRegion::getCavalryIncome()
{
    return cavalry_income;
}

string CRegion::getOwner()
{
    return owner;
}
