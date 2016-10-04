#ifndef INPUTARMYDIALOG_H
#define INPUTARMYDIALOG_H

#include <QDialog>

namespace Ui {
class InputArmyDialog;
}

/// \class InputArmyDialog
/// \brief Class inheriting from QDialog for army numbers input
class InputArmyDialog : public QDialog
{
    Q_OBJECT

public:
    /// \brief Default constructor
    explicit InputArmyDialog(QWidget *parent = 0);

    /// \brief Method for setting horizontal sliders' maximum values
    void setMaximumAmounts(int infantry, int archery, int cavalry);

    /// \brief Getter for the number of infantry
    int getInfantry();
    /// \brief Getter for the number of archers
    int getArchery();
    /// \brief Getter for the number of cavalry
    int getCavalry();

    /// \brief Default destructor
    ~InputArmyDialog();

private slots:
    void on_hsInfantry_valueChanged(int value);

    void on_hsArchers_valueChanged(int value);

    void on_hsCavalry_valueChanged(int value);

    void on_pbOk_clicked();

    void on_pbCancel_clicked();

private:
    Ui::InputArmyDialog *ui;

    int infantry;
    int archery;
    int cavalry;
};

#endif // INPUTARMYDIALOG_H
