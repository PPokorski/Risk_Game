#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEventLoop>
#include <QMessageBox>
#include "inputplayersdialog.h"
#include "inputrulesdialog.h"
#include "inputarmydialog.h"
#include "cmapdisplay.h"
#include "cmodelview.h"

using namespace std;

/// \enum EngineAction
/// \brief Enum for two main types of action - attack and move
enum EngineAction {Attack, Move};

namespace Ui {
class MainWindow;
}

/// \class MainWindow
/// \brief MainWindow class inheriting from QMainWindow for the main interaction
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// \brief Default constructor
    explicit MainWindow(QWidget *parent = 0);

    /// \brief Default destructor
    ~MainWindow();

private slots:
    void on_pbNewGame_clicked();

    void activeRegionChanged(int new_region);

    void currentPlayerChanged(string name);

    void gameFinished(string winner);

    void on_pbPass_clicked();

    void on_pbMove_clicked();

    void on_pbAttack_clicked();

private:
    void setWidgetsVisible(bool visible);
    void setActionsDisabled(bool disabled);
    void executeAction(int action);
    void createDialogs();
    void connectSignalsToSlots();

    Ui::MainWindow *ui;

    InputPlayersDialog *player_dialog;
    InputRulesDialog *rules_dialog;
    InputArmyDialog *army_dialog;

    CModelView model_view;

    vector<pair<string, QColor> > players;
    bool is_distrib_random;
    bool are_troops_given_all;
};

#endif // MAINWINDOW_H
