#include "playscene.h"
#include <QDebug>

PlayScene::PlayScene(Chess ChessMap[][COL], QWidget *parent)
    : QWidget{parent}
{
    this->Player = true; //红色先走
    initialChess(ChessMap);
    iniUI();
}

void PlayScene::iniUI()
{
    this->setFixedSize(800, 800);

    QPushButton* btn_Exit = new QPushButton(this);
    btn_Exit->resize(100, 60);
    btn_Exit->move(650, 300);

    connect(btn_Exit, QPushButton::clicked, [=](){
        emit this->PlaySceneBack();
    });
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
    QPen ChessPen;
    ChessPen.setColor(QColor(Qt::black));
    ChessPen.setWidth(2);
    ChessPointer.setPen(ChessPen);

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(ChessMap[i][j].type != 0 && ChessMap[i][j].Select == false)
            {
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
            }
        }
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
}

void PlayScene::mousePressEvent(QMouseEvent *e)
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
                            ChessMap[i][j].type = ChessMap[Checked_Row][Checked_Col].type;
                            ChessMap[Checked_Row][Checked_Col].type = 0;
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
