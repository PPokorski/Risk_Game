#ifndef CREGION_H
#define CREGION_H

#include <vector>
#include "cabstractidentifier.h"
#include "csoldier.h"

using namespace std;
/// \class CRegion
/// \brief A class defining single region whith its properties
class CRegion : public CAbstractIdentifier
{
public:
    /// \brief A default constructor
    CRegion();
    /// \brief Overloaded constructor for copying
    CRegion(const CRegion &region);
    /// \brief Overloaded constructor for creating a new object setting all parameters
    CRegion(string new_name, int new_id, vector<int> new_paths, string new_owner, int start_inf, int start_arch, int start_cav, int new_inf_income, int new_arch_income, int new_cav_income);

    /// \brief A method which increases number of all troops by their respective income
    void increaseTroops();
    /// \brief A method which changes number of troops by their respective amount
    void increaseTroops(int infantry_number, int archery_number, int cavalry_number);

    /// \brief A setter for paths to other regions
    void setPaths(vector<int> new_paths);
    /// \brief A setter for troops numbers
    void setTroopsNumbers(int infantry_number, int archery_number, int cavalry_number);
    /// \brief A setter for infantry_income
    void setInfantryIncome(int new_income);
    /// \brief A setter for archery_income
    void setArcherIncome(int new_income);
    /// \brief A setter for cavalry_income
    void setCavalryIncome(int new_income);
    /// \brief A setter for owner
    void setOwner(string new_owner);

    /// \brief A method which returns the reference to the troops specified by type
    /// \param type A type defined by enum Soldats
    CSoldier &getTroops(int type);

    /// \brief A getter for troops
    vector<int> getPaths();
    /// \brief A getter for infantry_income
    int getInfantryIncome();
    /// \brief A getter for archery_income
    int getArcherIncome();
    /// \brief A getter for cavalry_income
    int getCavalryIncome();
    /// \brief A getter for owner
    string getOwner();

private:
    CSoldier infantry;
    CSoldier archer;
    CSoldier cavalry;

    vector<int> paths;
    string owner;

    int infantry_income;
    int archery_income;
    int cavalry_income;
};

#endif // CREGION_H
