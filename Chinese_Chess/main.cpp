#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}


/*

1、主界面的窗建和主界面按钮图片以及信号和槽的连接
2、GameDraw(棋盘的绘制)的实现
3、主要函数ChessCheck和ChessMove的实现
    ChessCheck实现遍历ChessMap函数来画出棋子以及一些走棋时的提示(有bug未修复 10_20 :  一些棋子的在可以吃子的地方没有红色圆圈的提示)
    ChessMove函数主要负责判断棋子要走的地方是否合理，合理则返回true从而操作棋子走到要走的地方(由三个人共同完成)  也用于在提示时找到可以行走的位置

*/
