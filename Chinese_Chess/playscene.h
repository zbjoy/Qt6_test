#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QLabel>

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

class PlayScene : public QWidget
{
    Q_OBJECT
public:
    explicit PlayScene(int ChessMap[][COL], QWidget *parent = nullptr);

    //PlayScene(int ChessMap[][COL]);

    void iniUI();

    void paintEvent(QPaintEvent *);

    void GameDraw(QPainter& painter);

    void ChessCheck(int ChessMap[][COL]);

    void initialChess(int ChessMap[][COL]);

    int ChessMap[ROW][COL];

signals:

    void PlaySceneBack();
};

#endif // PLAYSCENE_H
