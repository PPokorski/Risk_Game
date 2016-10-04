#include "header/cabstractidentifier.h"

CAbstractIdentifier::CAbstractIdentifier()
{

}

void CAbstractIdentifier::setName(string new_name)
{
    name = new_name;
}

void CAbstractIdentifier::setId(int new_id)
{
    id = new_id;
}

string CAbstractIdentifier::getName()
{
    return name;
}

int CAbstractIdentifier::getId()
{
    return id;
}
