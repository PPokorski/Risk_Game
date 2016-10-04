#ifndef CEXCEPTIONS_H
#define CEXCEPTIONS_H

#include <string>

using namespace std;

/// \class CAbstractException
/// \brief An abstract class containing basic methods and attributes common for exceptions
class CAbstractException
{
public:
    /// \brief A default constructor
    CAbstractException();

    /// \brief Method returning what the exception was
    string what();

protected:
    /// \brief What was the exception
    string title;
    /// \brief A method for setting the title
    virtual void initTitle();
};


/// \class CExceptionNoRegionContinentPlayer
/// \brief Exception which is thrown when the object of given id/name was not found
class CExceptionNoRegionContinentPlayer : public CAbstractException
{
public:
    /// \brief Default constructor
    CExceptionNoRegionContinentPlayer();
    /// \brief Overloaded constructor when object was to be found by id
    /// \details Constructor sets appropriate text for title with this id
    CExceptionNoRegionContinentPlayer(int id);
    /// \brief Overloaded constructor when object was to be found by name
    /// \details Constructor sets appropriate text for title with this name
    CExceptionNoRegionContinentPlayer(string name);

private:
    void initTitle();
};


/// \class CExceptionWrongSoldierType
/// \brief Exception which is thrown when the wrong type of soldier was provided
class CExceptionWrongSoldierType : public CAbstractException
{
public:
    /// \brief Default constructor
    CExceptionWrongSoldierType();
    /// \brief Overloaded constructor when soldier was to be iitialized by type
    /// \details Constructor sets appropriate text for title with this type
    CExceptionWrongSoldierType(int type);

private:
    void initTitle();
};

/// \class CExceptionNoRegionAtPlayer
/// \brief Exception which is thrown when the region of given id/name was not found
class CExceptionNoRegionAtPlayer : public CAbstractException
{
public:
    /// \brief Default constructor
    CExceptionNoRegionAtPlayer();
    /// \brief Overloaded constructor when region was to be found by id at player of name
    /// \details Constructor sets appropriate text for title with this name and id
    CExceptionNoRegionAtPlayer(string name, int id);

private:
    void initTitle();
};

#endif // CEXCEPTIONS_H
