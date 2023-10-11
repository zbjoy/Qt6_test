#include "dialog.h"
#include    <QHBoxLayout>
#include    <QVBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("手工创建UI");
}

Dialog::~Dialog()
{
}

void Dialog::iniUI()
{
    chkBoxUnder = new QCheckBox("Underline");
    chkBoxItalic = new QCheckBox("Italic");
    chkBoxBold = new QCheckBox("Bold");

    QHBoxLayout* HLay1 = new QHBoxLayout();

    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);


    radioBlack = new QRadioButton("Black");
    radioRed = new QRadioButton("Red");
    radioBlue = new QRadioButton("Blue");

    QHBoxLayout* HLay2 = new QHBoxLayout();

    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioRed);
    HLay2->addWidget(radioBlue);


    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("关闭");

    QHBoxLayout* HLay3 = new QHBoxLayout();

    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);


    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello World\n手工创建");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout* VLay = new QVBoxLayout(this);
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void Dialog::iniSignalSlots()
{
    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxUnder(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxItalic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxBold(bool)));

    connect(radioBlack, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(radioRed, SIGNAL(clicked()), this, SLOT(do_setFontColor()));
    connect(radioBlue, SIGNAL(clicked()), this, SLOT(do_setFontColor()));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

void Dialog::do_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    if(radioBlack->isChecked())
    txtEdit->setStyleSheet("color:Black");
    else if(radioRed->isChecked())
    txtEdit->setStyleSheet("color:Red");
    else if(radioBlue->isChecked())
    txtEdit->setStyleSheet("color:Blue");
    else
    txtEdit->setStyleSheet("color:Black");
}















