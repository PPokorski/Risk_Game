#include "header/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWidgetsVisible(false);

    createDialogs();

    connectSignalsToSlots();

    QMessageBox box;
    box.setText("Please move the PATH/TO/PROJECT/resource/map/map.xml file to the build file.");
    box.exec();
}

MainWindow::~MainWindow()
{
    delete player_dialog;
    delete rules_dialog;
    delete army_dialog;

    delete ui;
}

void MainWindow::on_pbNewGame_clicked()
{
    if(player_dialog->exec())
    {
        players = player_dialog->getPlayers();
    }
    else
    {
        return;
    }

    if(rules_dialog->exec())
    {
        is_distrib_random = rules_dialog->isDistribRandom();
        are_troops_given_all = rules_dialog->areTroopsGivenAll();
    }
    else
    {
        return;
    }

    model_view.executeInit(players, is_distrib_random, are_troops_given_all);

    ui->pbNewGame->hide();
    setWidgetsVisible(true);

    setActionsDisabled(true);
}

void MainWindow::activeRegionChanged(int new_region)
{
    if(new_region >= 0)
    {
        CRegion region = model_view.getActiveRegion().first;

        if(region.getOwner() == model_view.getCurrentPlayer())
        {
            setActionsDisabled(false);
        }
        else
        {
            setActionsDisabled(true);
        }

        ui->listRegion->item(1)->setText(QString::fromStdString(region.getName()));
        ui->listRegion->item(3)->setText(QString::number(region.getId()));
        ui->listRegion->item(5)->setText(QString::fromStdString(region.getOwner()));

        ui->listRegion->item(8)->setText(QString::number(region.getTroops(Infantry).getAmount()));
        ui->listRegion->item(10)->setText(QString::number(region.getInfantryIncome()));
        ui->listRegion->item(12)->setText(QString::number(region.getTroops(Archery).getAmount()));
        ui->listRegion->item(14)->setText(QString::number(region.getArcherIncome()));
        ui->listRegion->item(16)->setText(QString::number(region.getTroops(Cavalry).getAmount()));
        ui->listRegion->item(18)->setText(QString::number(region.getCavalryIncome()));
    }
    else
    {
        ui->listRegion->item(1)->setText(QString());
        ui->listRegion->item(3)->setText(QString());
        ui->listRegion->item(5)->setText(QString());

        ui->listRegion->item(8)->setText(QString());
        ui->listRegion->item(10)->setText(QString());
        ui->listRegion->item(12)->setText(QString());
        ui->listRegion->item(14)->setText(QString());
        ui->listRegion->item(16)->setText(QString());
        ui->listRegion->item(18)->setText(QString());
    }
}

void MainWindow::currentPlayerChanged(string name)
{
    ui->lWhoseTurn->setText(QString("It's the turn of ") + QString::fromStdString(name));
}

void MainWindow::gameFinished(string winner)
{
    QMessageBox new_box;
    new_box.setText(QString("And the winner is ") + QString::fromStdString(winner) + QString("!!"));
    new_box.setIcon(QMessageBox::Information);
    new_box.setStandardButtons(QMessageBox::Ok);

    new_box.exec();

    model_view.executeEndGame();

    this->close();
}

void MainWindow::setWidgetsVisible(bool visible)
{
    ui->pbAttack->setVisible(visible);
    ui->pbMove->setVisible(visible);
    ui->pbPass->setVisible(visible);

    ui->listRegion->setVisible(visible);
}

void MainWindow::setActionsDisabled(bool disabled)
{
    ui->pbAttack->setDisabled(disabled);
    ui->pbMove->setDisabled(disabled);
}

void MainWindow::executeAction(int action)
{
    CRegion region = model_view.getActiveRegion().first;

    army_dialog->setMaximumAmounts(region.getTroops(Infantry).getAmount(),
                            region.getTroops(Archery).getAmount(),
                            region.getTroops(Cavalry).getAmount());

    switch(action)
    {
    case Move: army_dialog->setWindowTitle("Move troops"); break;
    case Attack: army_dialog->setWindowTitle("Attack other region"); break;
    }

    if(army_dialog->exec())
    {
        QEventLoop loop;

        connect(ui->MapDisplay, SIGNAL(activeRegionChanged()), &loop, SLOT(quit()));

        loop.exec();

        switch(action)
        {
        case Move: model_view.executeMoveArmy(region.getId(), model_view.getActiveRegion().first.getId(),
                                              army_dialog->getInfantry(),
                                              army_dialog->getArchery(),
                                              army_dialog->getCavalry());
            break;

        case Attack: model_view.executeAttack(region.getId(), model_view.getActiveRegion().first.getId(),
                                              army_dialog->getInfantry(),
                                              army_dialog->getArchery(),
                                              army_dialog->getCavalry());
            break;
        }

        activeRegionChanged(model_view.getActiveRegion().first.getId());
    }
    else
    {
        return;
    }
}

void MainWindow::createDialogs()
{
    player_dialog = new InputPlayersDialog(this);
    rules_dialog = new InputRulesDialog(this);
    army_dialog = new InputArmyDialog(this);
}

void MainWindow::connectSignalsToSlots()
{
    connect(ui->MapDisplay, SIGNAL(activeRegionChanged(int)), &model_view, SLOT(activeRegionChanged(int)));
    connect(ui->MapDisplay, SIGNAL(activeRegionChanged(int)), this, SLOT(activeRegionChanged(int)));

    connect(&model_view, SIGNAL(regionsColours(vector<QColor>)), ui->MapDisplay, SLOT(regionsColours(vector<QColor>)));
    connect(&model_view, SIGNAL(currentPlayerChaned(string)), this, SLOT(currentPlayerChanged(string)));
    connect(&model_view, SIGNAL(currentPlayerChaned(string)), ui->MapDisplay, SLOT(currentPlayerChanged(string)));
    connect(&model_view, SIGNAL(gameFinished(string)), this, SLOT(gameFinished(string)));
}

void MainWindow::on_pbPass_clicked()
{
    model_view.executePass();
}

void MainWindow::on_pbMove_clicked()
{
    executeAction(Move);
}

void MainWindow::on_pbAttack_clicked()
{
    executeAction(Attack);
}
