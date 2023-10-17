#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
    setWindowTitle("手工UI");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::do_SetFontUnder()
{

}

void Dialog::do_SetFontBold()
{

}

void Dialog::do_SetFontItalic()
{

}

void Dialog::do_SetFontColor()
{

}

void Dialog::iniUI()
{
    chkUnder = new QCheckBox;
    chkUnder->setText("Underline");
    chkBold = new QCheckBox("Bold");
    chkItalic = new QCheckBox("Italic");

    QGroupBox* grpBox1 = new QGroupBox(this);
    grpBox1->setTitle("字体");
    grpBox1->move(10, 10);
    grpBox1->setFixedSize(300, 100);


}

void Dialog::iniSignalSlots()
{

}

