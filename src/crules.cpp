#include "header/crules.h"

CRules::CRules()
{
    setRules();
}

CRules::CRules(bool is_distribution_random, bool are_troops_given_all)
{
    setRules(is_distribution_random, are_troops_given_all);
}


void CRules::setRules(bool is_distribution_random, bool are_troops_given_all)
{
    random_distribution = is_distribution_random;
    troops_given_all = are_troops_given_all;
}


bool CRules::getRandomDistribution()
{
    return random_distribution;
}

bool CRules::getTroopsGivenToAll()
{
    return troops_given_all;
}
