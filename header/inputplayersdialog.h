#ifndef INPUTPLAYERSDIALOG_H
#define INPUTPLAYERSDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QStringList>
#include <vector>
#include <QDebug>

using namespace std;

namespace Ui {
class InputPlayersDialog;
}

/// \class InputPlayerDialog
/// \brief Class inheriting from QDialog for players' names and colours input
class InputPlayersDialog : public QDialog
{
    Q_OBJECT

public:
    /// \brief Default constructor
    explicit InputPlayersDialog(QWidget *parent = 0);

    /// \brief Getter for players' names and colours
    vector<pair<string, QColor> > getPlayers();

    /// \brief Default destructor
    ~InputPlayersDialog();

private slots:
    void on_pbOk_clicked();

    void on_pbCancel_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void on_comboBox_6_currentTextChanged(const QString &arg1);

private:
    void changeLabelColour(QString name, int number);
    void addToVectors();

    Ui::InputPlayersDialog *ui;

    vector<QLineEdit *> line_edits;
    vector<QComboBox *> boxes;
    vector<QLabel *> labels;

    vector<QColor> avalaible_colors;
    QStringList color_names;

    vector<pair<string, QColor> > names_and_colours;
};

#endif // INPUTPLAYERSDIALOG_H
