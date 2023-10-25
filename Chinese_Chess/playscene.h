#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QLabel>
#include <QMouseEvent>
#include <QStack>
#include <QPropertyAnimation>
#include <QMediaPlayer>

#include "chess.h"
#include "Move.h"

#ifndef PLAYSCENE_SIZE
#define PLAYSCENE_SIZE

#define INTERVAL 50 //间隔
#define CHESS_GRID_SIZE 70  //格子宽度
#define ROW 10
#define COL 9
#define SIZE 60
#define BUTTON_SIZE 20
#define PLAYSCENEBUTTON_LEFT_EXIT 650
#define PLAYSCENEBUTTON_RIGHT_EXIT 750
#define PLAYSCENEBUTTON_TOP_EXIT 300
#define PLAYSCENEBUTTON_BOTTOM_EXIT 360

#endif

class ChessHistory
{
public:

    ChessHistory()
    {
        for(int i = 0; i <= ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                ChessTemp[i][j].Select = 0;
                ChessTemp[i][j].type = 0;
            }
        }
    }

    Chess ChessTemp[ROW][COL];
};



class PlayScene : public QWidget
{
    Q_OBJECT
public:
    explicit PlayScene(Chess ChessMap[][COL], QWidget *parent = nullptr);

    //PlayScene(int ChessMap[][COL]);

    void iniUI(); //界面初始化

    void paintEvent(QPaintEvent *); //绘图函数

    void GameDraw(QPainter& painter); //初始化棋盘和绘制ChessMap中的棋子

    void ChessCheck(Chess ChessMap[][COL]); //遍历并有QPainter画出象棋样子

    void ChessCheck_Big(Chess ChessMap[][COL], int x, int y);

    void initialChess(Chess ChessMap[][COL]); //把MainWidget中的ChessMap数据复制到类成员this->ChessMap中

    void mousePressEvent(QMouseEvent *e);

    bool ChessMove(Chess ChessMap[][COL], int i, int j);

    int isGameOver(Chess ChessMap[][COL]); // 返回0则没有结束  其余参照成员isWin

    void ChessReturn(); //悔棋

    ChessHistory ChessTemp;//[ROW][COL]; //暂时记录悔棋数据    注意: 在connect中好像不能直接创建变量

    QStack<ChessHistory> ChessBack;

    Chess ChessMap[ROW][COL]; //维护象棋数据

    QLabel* winLabel; //胜利图片

    QMediaPlayer* moveSound; //移动声音

    QMediaPlayer* eatSound; //吃子声音

    int Checked_Row;
    int Checked_Col;

    int isWin; //0 继续  1 红赢   2 黑赢

    bool Player;

    bool Checked;

signals:

    void PlaySceneBack(); //发送返回信号给MainWidget中的MainScene_Exit

    void PlayScenePlayAgain(); //把重新开始了的信号发给MainWidget
};

#endif // PLAYSCENE_H
