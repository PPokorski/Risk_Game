#ifndef INPUTRULESDIALOG_H
#define INPUTRULESDIALOG_H

#include <QDialog>
#include <vector>

using namespace std;

namespace Ui {
class InputRulesDialog;
}

/// \class InputRulesDialog
/// \brief Class inheriting from QDialog for rules' input
class InputRulesDialog : public QDialog
{
    Q_OBJECT

public:
    /// \brief Default constructor
    explicit InputRulesDialog(QWidget *parent = 0);

    /// \brief Getter for the is_distribution_random rule
    bool isDistribRandom();
    /// \brief Getter for the are_troops_given_all rule
    bool areTroopsGivenAll();

    /// \brief Default destructor
    ~InputRulesDialog();

private slots:
    void on_pbOk_clicked();

    void on_pbCancel_clicked();

private:
    Ui::InputRulesDialog *ui;

    bool is_distrib_random;
    bool are_troops_given_all;
};

#endif // INPUTRULESDIALOG_H
