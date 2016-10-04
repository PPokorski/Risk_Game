#include "header/inputarmydialog.h"
#include "ui_inputarmydialog.h"

InputArmyDialog::InputArmyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputArmyDialog)
{
    ui->setupUi(this);
}

void InputArmyDialog::setMaximumAmounts(int infantry, int archery, int cavalry)
{
    ui->hsInfantry->setMaximum(infantry);
    ui->hsArchers->setMaximum(archery);
    ui->hsCavalry->setMaximum(cavalry);
}

int InputArmyDialog::getInfantry()
{
    return infantry;
}

int InputArmyDialog::getArchery()
{
    return archery;
}

int InputArmyDialog::getCavalry()
{
    return cavalry;
}

InputArmyDialog::~InputArmyDialog()
{
    delete ui;
}

void InputArmyDialog::on_hsInfantry_valueChanged(int value)
{
    ui->lInfantry->setText(QString::number(value));
}

void InputArmyDialog::on_hsArchers_valueChanged(int value)
{
    ui->lArchers->setText(QString::number(value));
}

void InputArmyDialog::on_hsCavalry_valueChanged(int value)
{
    ui->lCavalry->setText(QString::number(value));
}

void InputArmyDialog::on_pbOk_clicked()
{
    infantry = ui->hsInfantry->value();
    archery = ui->hsArchers->value();
    cavalry = ui->hsCavalry->value();

    ui->hsInfantry->setValue(0);
    ui->hsArchers->setValue(0);
    ui->hsCavalry->setValue(0);

    accept();
}

void InputArmyDialog::on_pbCancel_clicked()
{
    reject();
}
