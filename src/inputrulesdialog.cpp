#include "header/inputrulesdialog.h"
#include "ui_inputrulesdialog.h"

InputRulesDialog::InputRulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputRulesDialog)
{
    ui->setupUi(this);
}

bool InputRulesDialog::isDistribRandom()
{
    return is_distrib_random;
}

bool InputRulesDialog::areTroopsGivenAll()
{
    return are_troops_given_all;
}

InputRulesDialog::~InputRulesDialog()
{
    delete ui;
}

void InputRulesDialog::on_pbOk_clicked()
{
    is_distrib_random = ui->cbDistribution->isChecked();
    are_troops_given_all = ui->cbIncome->isChecked();

    accept();
}

void InputRulesDialog::on_pbCancel_clicked()
{
    reject();
}
