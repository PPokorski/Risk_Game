#ifndef CRULES_H
#define CRULES_H


/// \class CRules
/// \brief Class defining the rules inside the game
class CRules
{
public:
    /// \brief Default constructor
    CRules();
    /// \brief Overload constructor initializing rules
    CRules(bool is_distribution_random, bool are_troops_given_all);

    /// \brief Setter for the rules
    void setRules(bool is_distribution_random = false, bool are_troops_given_all = false);

    /// \brief Getter for the rule telling if all the regions should be distributed randomly at the beginning of the game
    bool getRandomDistribution();
    /// \brief Getter for the rule telling whenn the troops' income should occur.
    /// \details The rules tells if the troops' income should occur at the beginning of the turn to everyone
    /// or to the one player at the beginning of his round
    bool getTroopsGivenToAll();

private:
    bool random_distribution;
    bool troops_given_all;
};

#endif // CRULES_H
