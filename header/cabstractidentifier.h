#ifndef CABSTRACTIDENTIFIER_H
#define CABSTRACTIDENTIFIER_H

#include <string>
#include <vector>

using namespace std;

/// \class CAbstractIdentifier
/// \brief An abstract class containing methods and attributes for identifing the object
class CAbstractIdentifier
{
public:
    /// \brief A default constructor
    CAbstractIdentifier();

    /// \brief A setter for the name
    void setName(string new_name);
    /// \brief A setter for the id
    void setId(int new_id);

    /// \brief A getter for the name
    string getName();
    /// \brief A getter for the id
    int getId();

protected:
    /// \brief Name of an object
    string name;
    /// \brief Id of an object
    int id;
};

#endif // CABSTRACTIDENTIFIER_H
