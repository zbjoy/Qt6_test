#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void do_SetFontUnder();
    void do_SetFontBold();
    void do_SetFontItalic();
    void do_SetFontColor();

private:
    Ui::Dialog *ui;

    QCheckBox* chkUnder;
    QCheckBox* chkItalic;
    QCheckBox* chkBold;
    QRadioButton* radioBlack;
    QRadioButton* radioRed;
    QRadioButton* radioBlue;
    QPushButton* btnOk;
    QPushButton* btnCancal;
    QPushButton* btnClose;

    void iniUI();
    void iniSignalSlots();
};
#endif // DIALOG_H
