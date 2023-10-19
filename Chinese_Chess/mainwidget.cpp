#include "mainwidget.h"
#include "ui_mainwidget.h"
//#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    initChssMap(ChessMap);

    iniUI();

}



MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::iniUI()
{
    this->setFixedSize(500, 700);
    QLabel* mainImage = new QLabel(this);
    mainImage->setGeometry(0, 0, 500, 700);
    mainImage->setPixmap(QPixmap(":/MainImage/image/MainScene.jpg").scaled(500, 700));

    QPushButton* MainSceneBtn_Start = new QPushButton(this);
    MainSceneBtn_Start->move(200, 450);
    QPixmap* MainSceneBtn_StartImage = new QPixmap(":/MainImage/image/MainStart.png");
    MainSceneBtn_Start->resize(110, 50);
    MainSceneBtn_Start->setIcon(QPixmap(*MainSceneBtn_StartImage));
    MainSceneBtn_Start->setIconSize(QSize(130, 70));

    QPushButton* MainSceneBtn_Exit = new QPushButton(this);
    MainSceneBtn_Exit->move(200, 530);
    MainSceneBtn_Exit->resize(110, 50);
    QPixmap* MainSceneBtn_ExitImage = new QPixmap(":/MainImage/image/MainExit.png");
    MainSceneBtn_Exit->setIcon(QPixmap(*MainSceneBtn_ExitImage));
    MainSceneBtn_Exit->setIconSize(QSize(130, 70));

    connect(MainSceneBtn_Start, SIGNAL(clicked()),this, SLOT(hide()));


    playScene = new PlayScene(ChessMap);

    connect(MainSceneBtn_Start, QPushButton::clicked, [=](){
        this->hide();
        playScene->show();
    });

    connect(MainSceneBtn_Exit, SIGNAL(clicked()), this, SLOT(close()));

    connect(playScene, &PlayScene::PlaySceneBack, [=](){
        this->show();
        playScene->hide();
    });

}

void MainWidget::initChssMap(int ChessMap[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (((i == 0 || i == ROW - 1) && j == 0) || ((i == 0 || i == ROW - 1) && j == COL - 1))
            {
                if (i == 0)
                {
                    ChessMap[i][j] = 3;
                }
                else
                {
                    ChessMap[i][j] = 10;
                }
            }
            else if (((i == 0 || i == ROW - 1) && j == 1) || ((i == 0 || i == ROW - 1) && j == COL - 2))
            {
                if (i == 0)
                {
                    ChessMap[i][j] = 4;
                }
                else
                {
                    ChessMap[i][j] = 11;
                }

            }
            else if (((i == 0 || i == ROW - 1) && j == 2) || ((i == 0 || i == ROW - 1) && j == COL - 3))
            {
                if (i == 0)
                {
                    ChessMap[i][j] = 5;
                }
                else
                {
                    ChessMap[i][j] = 12;
                }
            }
            else if (((i == 0 || i == ROW - 1) && j == 3) || ((i == 0 || i == ROW - 1) && j == COL - 4))
            {
                if (i == 0)
                {
                    ChessMap[i][j] = 6;
                }
                else
                {
                    ChessMap[i][j] = 13;
                }
            }
            else if (((i == 0 || i == ROW - 1) && j == 4))
            {
                if (i == 0)
                {
                    ChessMap[i][j] = 7;
                }
                else
                {
                    ChessMap[i][j] = 14;
                }
            }
            else if ((i == 3 || i == ROW - 4) && (j == 0 || j == 2 || j == 4 || j == 6 || j == 8 || j == 10))
            {
                if (i == 3)
                {
                    ChessMap[i][j] = 1;
                }
                else
                {
                    ChessMap[i][j] = 8;
                }
            }
            else if ((i == 2 || i == ROW - 3) && (j == 1 || j == COL - 2))
            {
                if (i == 2)
                {
                    ChessMap[i][j] = 2;
                }
                else
                {
                    ChessMap[i][j] = 9;
                }
            }
            else
            {
                ChessMap[i][j] = 0;
            }

        }
    }
}

