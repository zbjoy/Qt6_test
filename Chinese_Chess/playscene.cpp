#include "playscene.h"
#include <QDebug>

void initChssMap(Chess ChessMap[ROW][COL]) //怎么extern MainWidget中的initChssMap函数
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (((i == 0 || i == ROW - 1) && j == 0) || ((i == 0 || i == ROW - 1) && j == COL - 1))
            {
                if (i == 0)
                {
                    ChessMap[i][j].type = 3;
                }
                else
                {
                    ChessMap[i][j].type = 10;
                }
            }
            else if (((i == 0 || i == ROW - 1) && j == 1) || ((i == 0 || i == ROW - 1) && j == COL - 2))
            {
                if (i == 0)
                {
                    ChessMap[i][j].type = 4;
                }
                else
                {
                    ChessMap[i][j].type = 11;
                }

            }
            else if (((i == 0 || i == ROW - 1) && j == 2) || ((i == 0 || i == ROW - 1) && j == COL - 3))
            {
                if (i == 0)
                {
                    ChessMap[i][j].type = 5;
                }
                else
                {
                    ChessMap[i][j].type = 12;
                }
            }
            else if (((i == 0 || i == ROW - 1) && j == 3) || ((i == 0 || i == ROW - 1) && j == COL - 4))
            {
                if (i == 0)
                {
                    ChessMap[i][j].type = 6;
                }
                else
                {
                    ChessMap[i][j].type = 13;
                }
            }
            else if (((i == 0 || i == ROW - 1) && j == 4))
            {
                if (i == 0)
                {
                    ChessMap[i][j].type = 7;
                }
                else
                {
                    ChessMap[i][j].type = 14;
                }
            }
            else if ((i == 3 || i == ROW - 4) && (j == 0 || j == 2 || j == 4 || j == 6 || j == 8 || j == 10))
            {
                if (i == 3)
                {
                    ChessMap[i][j].type = 1;
                }
                else
                {
                    ChessMap[i][j].type = 8;
                }
            }
            else if ((i == 2 || i == ROW - 3) && (j == 1 || j == COL - 2))
            {
                if (i == 2)
                {
                    ChessMap[i][j].type = 2;
                }
                else
                {
                    ChessMap[i][j].type = 9;
                }
            }
            else
            {
                ChessMap[i][j].type = 0;
            }

        }
    }
}

PlayScene::PlayScene(Chess ChessMap[][COL], QWidget *parent)
    : QWidget{parent}
{
    //winLabel->show();
    this->Player = true; //红色先走
    initialChess(ChessMap);
    iniUI();
}

void PlayScene::iniUI()
{
    this->setWindowIcon(QIcon(":/MainImage/image/WindowIcon.png"));
    this->setFixedSize(800, 800);

    QPushButton* btn_Exit = new QPushButton(this);
    btn_Exit->resize(100, 60);
    btn_Exit->move(650, 420);
    btn_Exit->setText("退出");

    QPushButton* btn_Again = new QPushButton(this);
    btn_Again->resize(100, 60);
    btn_Again->move(650, 320);
    btn_Again->setText("重新开始");

    QPushButton* btn_Back = new QPushButton(this);
    btn_Back->resize(100, 60);
    btn_Back->move(650, 220);
    btn_Back->setText("悔棋");

    btn_Complex = new QRadioButton(this);
    btn_Complex->setChecked(false);
    btn_Complex->resize(100, 60);
    btn_Complex->move(670, 30);
    btn_Complex->setText("更多特效");

    winLabel = new QLabel;
    //winLabel->show();
    QPixmap tmpPix;
    tmpPix.load(":/MainImage/image/RedWin.png");
    //winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setGeometry(600, 100, 100, 100);
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->hide();

    moveSound = new QMediaPlayer(this);
    eatSound = new QMediaPlayer(this);
    moveSound->setMedia(QMediaContent(QUrl("qrc:/MainImage/image/move_1.mp3")));
    eatSound->setMedia(QMediaContent(QUrl("qrc:/MainImage/image/eat.mp3")));
    moveSound->setVolume(50);
    eatSound->setVolume(50);

    connect(btn_Exit, QPushButton::clicked, [=](){ //退出按钮
        emit this->PlaySceneBack();
    });

    connect(btn_Again, QPushButton::clicked, [=](){ //重新开始按钮
        emit this->PlayScenePlayAgain();

        if(!winLabel->isHidden())
        {
            winLabel->hide();
        }

        //initialChess(ChessMap);
        //ChessCheck(ChessMap);
        initChssMap(ChessMap);
        this->Player = true; //红色先走
        isWin = 0;
        ChessMap[Checked_Row][Checked_Col].Select = 0;
        Checked_Row = -1;
        Checked_Col = -1;
        Checked = false;
        ChessBack.clear(); //重新开始后清空栈中保存的数据
        update();
    });

    connect(btn_Back, QPushButton::clicked,[=](){  //悔棋按钮

//        if(winLabel->isHidden())
//        {
//        //winLabel->show();
//            winLabel->hide();
//        }

        ChessReturn();
//        if(ChessBack.isEmpty())
//        {
//            qDebug() << "栈为空";
//        }
//        else
//        {
//            qDebug() << ChessBack.size();
//        }
    });

    //connect(btn_Complex, QRadioButton::isChecked(), )

}

void PlayScene::ChessReturn()
{
    if(!ChessBack.isEmpty())
    {
       // ChessHistory chesshistory1; //好像不能直接创建变量
       // chesshistory1 = ChessBack.top();
        ChessTemp = ChessBack.top();
        ChessBack.pop_back();
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                ChessMap[i][j] = ChessTemp.ChessTemp[i][j];
            }
        }
        //ChessBack.pop_back();
//        for(int i = 0; i < ROW; i++)
//        {
//            for(int j = 0; j < COL; j++)
//            {
//                ChessMap[i][j].type = chesshistory1.ChessTemp[i][j].type;
//            }
//        }
//        if(winLabel->isHidden())
//        {
//            //winLabel->show();
//            winLabel->hide();
//        }
        Player = !Player;
        isWin = 0;
        update();
    }
}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor color(252, 215, 162);
    painter.setBrush(color);
    painter.drawRect(0, 0, 800, 800);

    GameDraw(painter);
}

void PlayScene::GameDraw(QPainter& painter)
{
    //winLabel->show();
    QPen pen;
    pen.setColor(QColor(Qt::black));
    pen.setWidth(2);
    painter.setPen(pen);
    //画棋盘
    for (int i = 0; i < ROW; i++)
    {
        //画横线
        painter.drawLine(INTERVAL, i * CHESS_GRID_SIZE + INTERVAL
             , CHESS_GRID_SIZE * (COL - 1) + INTERVAL, i * CHESS_GRID_SIZE + INTERVAL);

        if (i < COL)
        {
            //画竖线
            painter.drawLine(i * CHESS_GRID_SIZE + INTERVAL, INTERVAL
                            , i * CHESS_GRID_SIZE + INTERVAL, CHESS_GRID_SIZE * (ROW - 1) + INTERVAL);
        }
    }

    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawLine(3 * CHESS_GRID_SIZE + INTERVAL, INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL);
    painter.drawLine(5 * CHESS_GRID_SIZE + INTERVAL, INTERVAL, 3 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL);

    painter.drawLine(3 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 7 * CHESS_GRID_SIZE + INTERVAL);
    painter.drawLine(3 * CHESS_GRID_SIZE + INTERVAL, 7 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL);

    pen.setColor(Qt::black);
    painter.setPen(pen);
    //显示楚河, 汉界
    painter.drawRect(INTERVAL, (ROW / 2 - 1) * CHESS_GRID_SIZE + INTERVAL
                     , (COL - 1) * CHESS_GRID_SIZE, CHESS_GRID_SIZE);
    QPen penRiver;
    penRiver.setColor(Qt::black);
    penRiver.setWidth(5);
    painter.setPen(penRiver);
    QFont fontRiver;
    fontRiver.setPointSize(35);
    fontRiver.setFamily("Microsoft YaHei");
    painter.setFont(fontRiver);
    painter.drawText(INTERVAL, (ROW / 2 - 1) * CHESS_GRID_SIZE + INTERVAL - 5, (COL - 1) * CHESS_GRID_SIZE, CHESS_GRID_SIZE, 20,  "楚河   汉界");

    QFont fontPlayerTip;
    fontPlayerTip.setPointSize(23);
    painter.setFont(fontPlayerTip);

    if(Player == true)
    {
        painter.setPen(Qt::red);
        painter.drawText(630, 200, "红方走棋");
    }
    else
    {
        painter.setPen(Qt::black);
        painter.drawText(630, 550, "黑方走棋");
    }

    //QLabel* river = new QLabel(this);
    //QIcon RiverImage();

    //river->setFixedSize((COL - 1) * CHESS_GRID_SIZE, CHESS_GRID_SIZE);
    //river->move(INTERVAL, (ROW / 2 - 1) * CHESS_GRID_SIZE + INTERVAL);

    ChessCheck(this->ChessMap);

    //ChessCheck(this->ChessMap);
    //显示汉字
//    settextcolor(BLACK);
//    settextstyle(50, 0, _T("楷体"));
//    TCHAR river[30] = _T("楚河         汉界");

    //让文字居中
//    int twidth = textwidth(river);
//    int theight = textheight(river);
//    twidth = ((COL - 1) * CHESS_GRID_SIZE - twidth) / 2;
//    theight = (CHESS_GRID_SIZE - theight) / 2;
//    outtextxy(INTERVAL + twidth, (ROW / 2 - 1) * CHESS_GRID_SIZE + theight + INTERVAL, river);
}



void PlayScene::ChessCheck(Chess ChessMap[][COL])
{
    QPainter ChessPointer(this);

//    QPen ChessPen;
//    ChessPen.setColor(QColor(Qt::black));
//    ChessPen.setWidth(2);
//    ChessPointer.setPen(ChessPen);
    if(isWin == 0)
    {
        this->isWin = isGameOver(ChessMap);
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                if(ChessMap[i][j].type != 0 && ChessMap[i][j].Select == false)
                {
                    QPen ChessPen;
                    ChessPen.setColor(QColor(Qt::black));
                    ChessPen.setWidth(2);
                    ChessPointer.setPen(ChessPen);
                    ChessPointer.setBrush(QBrush(QColor(Qt::white)));
                    //Chess.setPen(Qt::NoPen);
                    ChessPointer.drawEllipse(QPoint(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE), 25, 25);
                    QFont font;
                    font.setPointSize(23);
                    ChessPointer.setFont(font);
                    QString ChessName = "兵炮车马相士帅卒炮车马象士将";
                    if(ChessMap[i][j].type >= 1 && ChessMap[i][j].type <= 7)
                    {
                        ChessPointer.setPen(Qt::red);
                    }
                    else if(ChessMap[i][j].type >= 8 && ChessMap[i][j].type <= 14)
                    {
                        ChessPointer.setPen(Qt::black);
                    }

                    ChessPointer.drawText(QPoint(INTERVAL + j * CHESS_GRID_SIZE - 18, INTERVAL + i * CHESS_GRID_SIZE + 13), ChessName.mid(ChessMap[i][j].type - 1, 1));
                }
                else if(ChessMap[i][j].type != 0 && ChessMap[i][j].Select == true)
                {
                    QPen ChessPen;
                    ChessPen.setColor(QColor(Qt::black));
                    ChessPen.setWidth(2);
                    ChessPointer.setPen(ChessPen);
                    ChessPointer.setBrush(QBrush(QColor(Qt::white)));
                    //Chess.setPen(Qt::NoPen);
                    ChessPointer.drawEllipse(QPoint(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE), 30, 30);
                    QFont font;
                    font.setPointSize(30);
                    ChessPointer.setFont(font);
                    QString ChessName = "兵炮车马相士帅卒炮车马象士将";
                    if(ChessMap[i][j].type >= 1 && ChessMap[i][j].type <= 7)
                    {
                        ChessPointer.setPen(Qt::red);
                    }
                    else if(ChessMap[i][j].type >= 8 && ChessMap[i][j].type <= 14)
                    {
                        ChessPointer.setPen(Qt::black);
                    }

                    ChessPointer.drawText(QPoint(INTERVAL + j * CHESS_GRID_SIZE - 25, INTERVAL + i * CHESS_GRID_SIZE + 16), ChessName.mid(ChessMap[i][j].type - 1, 1));
                    //ChessMap[i][j].Select = false;

                    //添加提示
                    //ChessPointer.setBrush(Qt::NoBrush);
                    for(int i1 = 0; i1 < ROW; i1++)
                    {
                        for(int j1 = 0; j1 < COL; j1++)
                        {
                            bool Judge = ChessMove(ChessMap, i1, j1);
                            //if(ChessMove(ChessMap, i1, j1) == true)
                            if(Judge)
                            {
                                ChessPointer.setBrush(Qt::white);
                                //QPen TipPen;
                                //TipPen.setBrush(Qt::white);
                                //TipPen.setColor(Qt::white);
                                //TipPen.setWidth(3);
                                //ChessPointer.setPen(Qt::white);
                                //ChessPointer.setPen(TipPen);
                                //                            if(Player)
                                //                            {
                                if(ChessMap[i1][j1].type != 0)
                                {
                                    //                                ChessPointer.setPen(Qt::red);
                                    //TipPen.setColor(Qt::red);

                                    ChessPointer.setBrush(Qt::red);
                                }
                                //                            }
                                //                            else
                                //                            {
                                //                                if(ChessMap[i])
                                //                            }
                                //                            TipPen.setBrush(Qt::NoBrush);
                                //ChessPointer.setPen(TipPen);
                                //                            ChessPointer.drawEllipse(QPoint(INTERVAL + j1 * CHESS_GRID_SIZE, INTERVAL + i1 * CHESS_GRID_SIZE), 3, 3);
                                ChessPointer.drawEllipse(QPoint(INTERVAL + j1 * CHESS_GRID_SIZE, INTERVAL + i1 * CHESS_GRID_SIZE), 5, 5);
                                //ChessPointer.drawEllipse(QPoint(INTERVAL + j1 * CHESS_GRID_SIZE, INTERVAL + i1 * CHESS_GRID_SIZE), 1, 1);
                            }
                        }
                    }
                    //update();
                }
            }
        }
    }
    if(isWin == 1) //红赢了
    {
//        winLabel = new QLabel;
//        //winLabel->show();
//        QPixmap tmpPix;
//        tmpPix.load(":/MainImage/image/RedWin.png");
//        //winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
//        winLabel->setGeometry(600, 100, 100, 100);
//        winLabel->setPixmap(tmpPix);
//        winLabel->setParent(this);
        //winLabel->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());
        //winLabel->move(400, 400);
        winLabel->move(650, 100);
        winLabel->show();
        ChessBack.clear();
        //将胜利图片移动下来
//        QPropertyAnimation * animation = new QPropertyAnimation(winLabel,"geometry");

//        //设置时间间隔
//        animation->setDuration(1000);

//        //起始位置
//        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));

//        //结束位置
//        animation->setEndValue(QRect(winLabel->x(),winLabel->y() + 300,winLabel->width(),winLabel->height()));

//        //设置弹跳曲线
//        animation->setEasingCurve(QEasingCurve::OutBounce);

//        //执行动画
//        winLabel->show();
//        animation->start();

        //_sleep(3000);

        //animation->stop();

        //winLabel->hide();
    }
    if(isWin == 2) //黑赢了
    {
        //qDebug() << "黑胜利";
        //QLabel* hah = new QLabel(this);
        //hah->setGeometry(0, 0, 500, 700);
        //hah->setPixmap(QPixmap(":/MainImage/image/RedWin.png").scaled(500, 700));
        winLabel->move(650, 550);
        winLabel->show();
        ChessBack.clear();
//        while(true)
//        {
//            _sleep(5000);
//        }
    }

}

//void PlayScene::ChessCheck_Big(Chess ChessMap[][COL], int x, int y)
//{
//    QPainter Chess(this);
//    QPen ChessPen;
//    ChessPen.setColor(QColor(Qt::black));
//    ChessPen.setWidth(2);
//    Chess.setPen(ChessPen);

//    for(int i = 0; i < ROW; i++)
//    {
//        for(int j = 0; j < COL; j++)
//        {
//            if(ChessMap[i][j] != 0)
//            {
//                Chess.setBrush(QBrush(QColor(Qt::white)));
//                //Chess.setPen(Qt::NoPen);
//                Chess.drawEllipse(QPoint(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE), 25, 25);
//                QFont font;
//                font.setPointSize(23);
//                if(i == x && j == y)
//                font.setPointSize(30);
//                Chess.setFont(font);
//                QString ChessName = "兵炮车马相士帅卒炮车马象士将";
//                if(ChessMap[i][j] >= 1 && ChessMap[i][j] <= 7)
//                {
//                    Chess.setPen(Qt::red);
//                }
//                else if(ChessMap[i][j] >= 8 && ChessMap[i][j] <= 14)
//                {
//                    Chess.setPen(Qt::black);
//                }

//                Chess.drawText(QPoint(INTERVAL + j * CHESS_GRID_SIZE - 18, INTERVAL + i * CHESS_GRID_SIZE + 13), ChessName.mid(ChessMap[i][j] - 1, 1));
//            }
//        }
//    }
//}

void PlayScene::initialChess(Chess ChessMap[][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            this->ChessMap[i][j].type = ChessMap[i][j].type;
            this->ChessMap[i][j].Select = ChessMap[i][j].Select;
        }
    }

    this->Checked = false;
    this->Checked_Col = -1;
    this->Checked_Row = -1;
    this->isWin = 0;
}

void PlayScene::mousePressEvent(QMouseEvent *e)
{
    if(isWin == 0)
    {
        if(e->button() & Qt::LeftButton && Checked == false)
        {
            for(int i = 0; i < ROW; i++)
            {
                for(int j = 0; j < COL; j++)
                {
                    if(e->pos().x() >= INTERVAL + j * CHESS_GRID_SIZE - 25 && e->pos().x() <= INTERVAL + j * CHESS_GRID_SIZE + 25
                        && e->pos().y() >= INTERVAL + i * CHESS_GRID_SIZE - 25 && e->pos().y() <= INTERVAL + i * CHESS_GRID_SIZE + 25)
                    {
                        if(Player == true && ChessMap[i][j].type >= 1 && ChessMap[i][j].type <= 7)
                        {
                            //this->ChessMap[i][j] = 14;
                            ChessMap[i][j].Select = true;
                            this->Checked = true;
                            this->Checked_Row = i;
                            this->Checked_Col = j;
                            //this->paintEvent(this);
                            //this->ChessCheck(ChessMap);
                            //ChessCheck_Big(ChessMap, i, j);
                        }
                        else if(Player == false && ChessMap[i][j].type >= 8 && ChessMap[i][j].type <= 14)
                        {
                            //this->ChessMap[i][j] = 14;
                            ChessMap[i][j].Select = true;
                            this->Checked = true;
                            this->Checked_Row = i;
                            this->Checked_Col = j;
                            //this->paintEvent(this);
                            //this->ChessCheck(ChessMap);
                            //ChessCheck_Big(ChessMap, i, j);
                        }

                        update();



                    }
                }
            }
        }
        else if(e->button() & Qt::LeftButton && Checked == true)
        {
            if(Checked_Row != -1 && Checked_Col != -1)
            {
                ChessMap[Checked_Row][Checked_Col].Select = false;
                this->Checked = false;
                for(int i = 0; i < ROW; i++)
                {
                    for(int j = 0; j < COL; j++)
                    {
                        if(e->pos().x() >= INTERVAL + j * CHESS_GRID_SIZE - 25 && e->pos().x() <= INTERVAL + j * CHESS_GRID_SIZE + 25
                            && e->pos().y() >= INTERVAL + i * CHESS_GRID_SIZE - 25 && e->pos().y() <= INTERVAL + i * CHESS_GRID_SIZE + 25)
                        {

                            bool Judge = ChessMove(ChessMap, i, j);

                            //this->ChessMap[i][j] = 14;
                            //                    ChessMap[i][j].Select = false;
                            //                    this->Checked = false;
                            //this->paintEvent(this);
                            //this->ChessCheck(ChessMap);
                            //ChessCheck_Big(ChessMap, i, j);
                            //ChessMove(i, j, ChessMap, Checked_Row, Checked_Col);

                            if( Judge == true)
                            {
                                ChessHistory chesshistory;
//                                chesshistory.ChessTemp = ChessMap;
                                for(int i = 0; i < ROW; i++)
                                {
                                    for(int j = 0; j < COL; j++)
                                    {
                                        chesshistory.ChessTemp[i][j].type = ChessMap[i][j].type;
                                    }
                                }
//                                while(!ChessBack.isEmpty())
//                                {
//                                    ChessHistory debugChessMap;
//                                    debugChessMap = ChessBack.top();
//                                    ChessBack.pop_back();
//                                    for(int i = 0; i < ROW; i++)
//                                    {
//                                        for(int j = 0; j < COL; j++)
//                                        {
//                                            qDebug() << debugChessMap.ChessTemp[i][j].type;
//                                        }
//                                    }
//                                }
                                ChessBack.push_back(chesshistory);

                                if(ChessMap[i][j].type != 0)
                                {
                                    eatSound->play();
                                }
                                else
                                {
                                    moveSound->play();
                                }

//                                if(btn_Complex->isChecked()) //执行将军判断与绝杀判断
//                                {
//                                    //qDebug() << "绝杀";
//                                    bool isPlaySound = SpecialSound(ChessMap[Checked_Row][Checked_Col]);
//                                    if(isPlaySound) //播放声音
//                                    {

//                                    }
//                                }

                                ChessMap[i][j].type = ChessMap[Checked_Row][Checked_Col].type;

                                ChessMap[Checked_Row][Checked_Col].type = 0;

                                if(btn_Complex->isChecked()) //执行将军判断与绝杀判断
                                {
                                    Checked_Row = i;
                                    Checked_Col = j;
                                    //qDebug() << "绝杀";
                                    bool isPlaySound = SpecialSound(ChessMap);
                                    if(isPlaySound) //播放声音
                                    {

                                    }
                                }

                                //moveSound->play(); /////////////////////////////////////////
                                this->Player = !this->Player;
                            }

                            update();



                        }
                    }
                }
                Checked_Row = -1;
                Checked_Col = -1;
            }
        }
    }


}

bool PlayScene::ChessMove(Chess ChessMap[][COL], int i, int j)
{
    bool Judge = false;
    if (ChessMap[Checked_Row][Checked_Col].type == 1) //红兵
    {
        Judge = RedBin_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 2) //红炮
    {
        Judge = RedPao_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 3) //红车
    {
        Judge = RedChe_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 4) //红马
    {
        Judge = RedMa_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 5) //红相
    {
        Judge = RedXiang_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 6) //红士
    {
        Judge = RedShi_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 7) //帅
    {
        Judge = Shuai_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 8) //黑卒
    {
        Judge = BlackBin_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 9) //黑炮
    {
        Judge = BlackPao_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 10) //黑车
    {
        Judge = BlackChe_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 11) //黑马
    {
        Judge = BlackMa_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 12) //黑象
    {
        Judge = BlackXiang_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 13) //黑士
    {
        Judge = BlackShi_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    else if (ChessMap[Checked_Row][Checked_Col].type == 14) //将
    {
        Judge = Jiang_Move(j, i, ChessMap, Checked_Row, Checked_Col);
    }
    return Judge;
}

int PlayScene::isGameOver(Chess ChessMap[][COL])
{
    int ret = 2;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 3; j < 6; j++)
        {
            if(ChessMap[i][j].type == 7)
            {
                ret = 1;
                Shuai_Row = i;
                Shuai_Col = j;
                break;
            }
        }
    }
    if(ret == 2)
    {
        return ret;
    }

    for(int i = 7; i < 10; ++i)
    {
        for(int j = 3; j < 6; ++j)
        {
            if(ChessMap[i][j].type == 14)
            {
                ret = 0;
                Jiang_Row = i;
                Jiang_Col = j;
                break;
            }
        }
    }
    return ret;
}

bool PlayScene::SpecialSound(Chess ChessMap[][COL])
{
    if(Player && ChessMove(ChessMap, Jiang_Row, Jiang_Col))
    {
        qDebug() << "将Jiang";
        return true;
    }
    else if(!Player && ChessMove(ChessMap, Shuai_Row, Shuai_Col))
    {
        qDebug() << "将Shuai";
        return true;
    }
    return false;
}
