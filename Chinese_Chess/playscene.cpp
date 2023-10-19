#include "playscene.h"

PlayScene::PlayScene(int ChessMap[][COL], QWidget *parent)
    : QWidget{parent}
{
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

    QLabel* river = new QLabel(this);
    river->setFixedSize((COL - 1) * CHESS_GRID_SIZE, CHESS_GRID_SIZE);
    river->move(INTERVAL, (ROW / 2 - 1) * CHESS_GRID_SIZE + INTERVAL);

    ChessCheck(this->ChessMap);

    ChessCheck(this->ChessMap);
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

void PlayScene::ChessCheck(int ChessMap[][COL])
{
    QPainter Chess(this);
    QPen ChessPen;
    ChessPen.setColor(QColor(Qt::black));
    ChessPen.setWidth(2);
    Chess.setPen(ChessPen);

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(ChessMap[i][j] != 0)
            {
                Chess.drawEllipse(QPoint(INTERVAL + j * CHESS_GRID_SIZE, INTERVAL + i * CHESS_GRID_SIZE), 25, 25);
                if(ChessMap[i][j] == 1)
                {
                    QFont font;
                    font.setPointSize(25);
                    Chess.setFont(font);
                   Chess.drawText(QPoint(INTERVAL + j * CHESS_GRID_SIZE - 17, INTERVAL + i * CHESS_GRID_SIZE + 15), "兵");
                }
                else if(ChessMap[i][j] == 2)
                {
                   QFont font;
                   font.setPointSize(25);
                   Chess.setFont(font);
                   Chess.drawText(QPoint(INTERVAL + j * CHESS_GRID_SIZE - 17, INTERVAL + i * CHESS_GRID_SIZE + 15), "将");
                }

            }
        }
    }
}

void PlayScene::initialChess(int ChessMap[][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            this->ChessMap[i][j] = ChessMap[i][j];
        }
    }
}
