#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(ui->radioButton_3, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
}


void Dialog::on_checkBox_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_2_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_3_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    if(ui->radioButton->isChecked())
    {
        ui->plainTextEdit->setStyleSheet("color:black");
    }
    else if(ui->radioButton_2->isChecked())
    {
        ui->plainTextEdit->setStyleSheet("color:red");
    }
    else if(ui->radioButton_3->isChecked())
    {
        ui->plainTextEdit->setStyleSheet("color:blue");
    }
    else
    {
        ui->plainTextEdit->setStyleSheet("clor:black");
    }

}





















