#include "header/inputplayersdialog.h"
#include "ui_inputplayersdialog.h"

InputPlayersDialog::InputPlayersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputPlayersDialog)
{
    ui->setupUi(this);

    addToVectors();
}

vector<pair<string, QColor> > InputPlayersDialog::getPlayers()
{
    return names_and_colours;
}

InputPlayersDialog::~InputPlayersDialog()
{
    delete ui;
}

void InputPlayersDialog::on_pbOk_clicked()
{
    vector<string> names;
    vector<QColor> colours;

    names_and_colours.clear();

    for(unsigned int i = 0; i < line_edits.size(); i++)
    {
        if(line_edits.at(i)->text().toStdString().empty()) break;

        names.push_back(line_edits.at(i)->text().toStdString());
        colours.push_back(QColor(boxes.at(i)->currentText()));

        names_and_colours.push_back(make_pair(names.at(i), colours.at(i)));
    }

    accept();
}

void InputPlayersDialog::on_pbCancel_clicked()
{
    reject();
}

void InputPlayersDialog::changeLabelColour(QString name, int number)
{
    QImage img(labels.at(number)->width(), labels.at(number)->height(), QImage::Format_RGB32);

    img.fill(QColor(name));

    labels.at(number)->setPixmap(QPixmap::fromImage(img));
}

void InputPlayersDialog::addToVectors()
{
    avalaible_colors =
    {
        QColor(Qt::red),
        QColor(Qt::green),
        QColor(Qt::blue),
        QColor(Qt::yellow),
        QColor(Qt::cyan),
        QColor(Qt::magenta),
        QColor(Qt::black)
    };

    color_names << "red"
                << "green"
                << "blue"
                << "yellow"
                << "cyan"
                << "magenta"
                << "black";

    line_edits.push_back(ui->lineEdit);
    line_edits.push_back(ui->lineEdit_2);
    line_edits.push_back(ui->lineEdit_3);
    line_edits.push_back(ui->lineEdit_4);
    line_edits.push_back(ui->lineEdit_5);
    line_edits.push_back(ui->lineEdit_6);

    boxes.push_back(ui->comboBox);
    boxes.push_back(ui->comboBox_2);
    boxes.push_back(ui->comboBox_3);
    boxes.push_back(ui->comboBox_4);
    boxes.push_back(ui->comboBox_5);
    boxes.push_back(ui->comboBox_6);

    labels.push_back(ui->label_3);
    labels.push_back(ui->label_4);
    labels.push_back(ui->label_5);
    labels.push_back(ui->label_6);
    labels.push_back(ui->label_7);
    labels.push_back(ui->label_8);

    for(unsigned int i = 0; i < boxes.size(); i++)
    {
        boxes.at(i)->addItems(color_names);
    }
}

void InputPlayersDialog::on_comboBox_currentTextChanged(const QString &arg1)
{
    changeLabelColour(arg1, 0);
}

void InputPlayersDialog::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    changeLabelColour(arg1, 1);
}

void InputPlayersDialog::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    changeLabelColour(arg1, 2);
}

void InputPlayersDialog::on_comboBox_4_currentTextChanged(const QString &arg1)
{
    changeLabelColour(arg1, 3);
}

void InputPlayersDialog::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    changeLabelColour(arg1, 4);
}

void InputPlayersDialog::on_comboBox_6_currentTextChanged(const QString &arg1)
{
    changeLabelColour(arg1, 5);
}
