#include "move.h"

bool RedBin_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    if (j >= ROW / 2 && j < ROW)
    {
        if (x == i + 1 && y == j && x < COL && (ChessMap[y][x].type == 0 || ChessMap[y][x].type >= 8))
        {
            return true;
        }
        else if (x == i - 1 && y == j && x >= 0 && (ChessMap[y][x].type == 0 || ChessMap[y][x].type >= 8))
        {
            return true;
        }
    }

    if (x == i && y == j + 1 && y < ROW)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BlackBin_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    if (j < ROW / 2 && j >= 0)
    {
        if (x == i + 1 && y == j && x < COL && (ChessMap[y][x].type == 0 || ChessMap[y][x].type <= 7))
        {
            return true;
        }
        else if (x == i - 1 && y == j && x >= 0 && (ChessMap[y][x].type == 0 || ChessMap[y][x].type <= 7))
        {
            return true;
        }
    }

    if (x == i && y == j - 1 && y >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool RedChe_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    for (int tempX = i; tempX < COL; tempX++)
    {
        if (tempX != i && y == j)
        {
            if (ChessMap[y][tempX].type == 0 && tempX == x)
            {
                return true;
            }
            else if (ChessMap[y][tempX].type >= 8 && ChessMap[y][tempX].type <= 14)
            {
                if (tempX == x)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[y][tempX].type >= 1 && ChessMap[y][tempX].type <= 7)
            {
                break;
            }
        }
    }

    for (int tempX = i; tempX >= 0; tempX--)
    {
        if (tempX != i && y == j)
        {
            if (ChessMap[y][tempX].type == 0 && tempX == x)
            {
                return true;
            }
            else if (ChessMap[y][tempX].type >= 8 && ChessMap[y][tempX].type <= 14)
            {
                if (tempX == x)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[y][tempX].type >= 1 && ChessMap[y][tempX].type <= 7)
            {
                break;
            }
        }
    }

    for (int tempY = j; tempY < ROW; tempY++)
    {
        if (tempY != j && x == i)
        {
            if (tempY == y && ChessMap[tempY][i].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
            {
                if (tempY == y)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[tempY][i].type >= 1 && ChessMap[tempY][i].type <= 7)
            {
                break;
            }
        }
    }

    for (int tempY = j; tempY >= 0; tempY--)
    {
        if (tempY != j && x == i)
        {
            if (tempY == y && ChessMap[tempY][i].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
            {
                if (tempY == y)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[tempY][i].type >= 1 && ChessMap[tempY][i].type <= 7)
            {
                break;
            }
        }
    }

    return false;
}

bool BlackChe_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    for (int tempX = i; tempX < COL; tempX++)
    {
        if (tempX != i && y == j)
        {
            if (ChessMap[y][tempX].type == 0 && tempX == x)
            {
                return true;
            }
            else if (ChessMap[y][tempX].type >= 1 && ChessMap[y][tempX].type <= 7)
            {
                if (tempX == x)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[y][tempX].type >= 8 && ChessMap[y][tempX].type <= 14)
            {
                break;
            }
        }
    }

    for (int tempX = i; tempX >= 0; tempX--)
    {
        if (tempX != i && y == j)
        {
            if (ChessMap[y][tempX].type == 0 && tempX == x)
            {
                return true;
            }
            else if (ChessMap[y][tempX].type >= 1 && ChessMap[y][tempX].type <= 7)
            {
                if (tempX == x)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[y][tempX].type >= 8 && ChessMap[y][tempX].type <= 14)
            {
                break;
            }
        }
    }

    for (int tempY = j; tempY < ROW; tempY++)
    {
        if (tempY != j && x == i)
        {
            if (tempY == y && ChessMap[tempY][i].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][i].type >= 1 && ChessMap[tempY][i].type <= 7)
            {
                if (tempY == y)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
            {
                break;
            }
        }
    }

    for (int tempY = j; tempY >= 0; tempY--)
    {
        if (tempY != j && x == i)
        {
            if (tempY == y && ChessMap[tempY][i].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][i].type >= 1 && ChessMap[tempY][i].type <= 7)
            {
                if (tempY == y)
                {
                    return true;
                }
                break;
            }
            else if (ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
            {
                break;
            }
        }
    }

    return false;
}


bool RedMa_Move(int x, int y, const Chess ChessMap[][COL], int j, int i) //x 点击x坐标  y 点击y坐标  j 纵坐标  i 横坐标
{
    int tempX = x, tempY = y;
    if (tempX > i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y - 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    if (tempX < i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y - 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    if (tempX < i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y + 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    if (tempX > i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y + 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    return false;
}

bool BlackMa_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    int tempX = x, tempY = y;
    if (tempX > i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y - 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    if (tempX < i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y - 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    if (tempX < i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y + 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    if (tempX > i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 5 && ChessMap[y + 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    return false;
}

bool RedPao_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    bool isChess = false;
    int objX = 0;
    int objY = 0;

    if (x == i && y != j)
    {
        if (y > j)
        {
            for (int tempY = j; tempY < ROW; tempY++)
            {
                if (tempY != j && ChessMap[tempY][i].type == 0 && tempY == y)
                {
                    return true;
                }
                else if (tempY != j && ChessMap[tempY][i].type != 0)
                {
                    isChess = true;
                    objX = i;
                    objY = tempY;
                    break;
                }
            }
        }
        else if (y < j)
        {
            for (int tempY = j; tempY >= 0; tempY--)
            {
                if (tempY != j && ChessMap[tempY][i].type == 0 && tempY == y)
                {
                    return true;
                }
                else if (ChessMap[tempY][i].type != 0 && tempY != j)
                {
                    isChess = true;
                    objX = i;
                    objY = tempY;
                    break;
                }
            }
        }

    }
    else if (x != i && y == j)
    {
        if (x > i)
        {
            for (int tempX = i; tempX < COL; tempX++)
            {
                if (tempX != i && tempX == x && ChessMap[j][tempX].type == 0)
                {
                    return true;
                }
                else if (tempX != i && ChessMap[j][tempX].type != 0)
                {
                    isChess = true;
                    objX = tempX;
                    objY = j;
                    break;
                }
            }
        }
        else if (x < i)
        {
            for (int tempX = i; tempX >= 0; tempX--)
            {
                if (tempX != i && tempX == x && ChessMap[j][tempX].type == 0)
                {
                    return true;
                }
                else if (tempX != i && ChessMap[j][tempX].type != 0)
                {
                    isChess = true;
                    objX = tempX;
                    objY = j;
                    break;
                }
            }
        }
    }

    if (isChess)
    {
        if (objX > i)
        {
            for (int tempX = objX; tempX < COL; tempX++)
            {
                if (tempX != objX && ChessMap[j][tempX].type >= 8 && ChessMap[j][tempX].type <= 14)
                {
                    if(tempX == x)
                    return true;
                    return false;
                }
                else if (tempX != objX && ChessMap[j][tempX].type <= 7 && ChessMap[j][tempX].type >= 1)
                {
                    return false;
                }
//                if (tempX != objX && tempX == x && ChessMap[j][tempX].type >= 8 && ChessMap[j][tempX].type <= 14)
//                {
//                    return true;
//                }
//                else if (tempX != objX && tempX == x && ChessMap[j][tempX].type <= 7 && ChessMap[j][tempX].type >= 1)
//                {
//                    return false;
//                }
            }
        }
        else if (objX < i)
        {
            for (int tempX = objX; tempX >= 0; tempX--)
            {
                if (tempX != objX && ChessMap[j][tempX].type >= 8 && ChessMap[j][tempX].type <= 14)
                {
                    if(tempX == x)
                    return true;
                    return false;
                }
                else if (tempX != objX && ChessMap[j][tempX].type <= 7 && ChessMap[j][tempX].type >= 1)
                {
                    return false;
                }
            }
        }
        else if (objY > j)
        {
            for (int tempY = objY; tempY < ROW; tempY++)
            {
                if (tempY != objY && ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
                {
                    if(tempY == y)
                    return true;
                    return false;
                }
                else if (tempY != objY && ChessMap[tempY][i].type <= 7 && ChessMap[tempY][i].type >= 1)
                {
                    return false;
                }
            }

//            for (int tempY = objY; tempY < ROW; tempY++)
//            {
//                if (tempY != objY && tempY == y && ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
//                {
//                    return true;
//                }
//                else if (tempY != objY && tempY == y && ChessMap[tempY][i].type <= 7 && ChessMap[tempY][i].type >= 1)
//                {
//                    return false;
//                }
//            }
        }
        else if (objY < j)
        {
            for (int tempY = objY; tempY >= 0; tempY--)
            {
                if (tempY != objY && ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
                {
                    if(tempY == y)
                    return true;
                    return false;
                }
                else if (tempY != objY && ChessMap[tempY][i].type <= 7 && ChessMap[tempY][i].type >= 1)
                {
                    return false;
                }

//                if (tempY != objY && tempY == y && ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
//                {
//                    return true;
//                }
//                else if (tempY != objY && tempY == y && ChessMap[tempY][i].type <= 7 && ChessMap[tempY][i].type >= 1)
//                {
//                    return false;
//                }
            }
        }

    }

    return false;
}

bool BlackPao_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    bool isChess = false;
    int objX = 0;
    int objY = 0;

    if (x == i && y != j)
    {
        if (y > j)
        {
            for (int tempY = j; tempY < ROW; tempY++)
            {
                if (tempY != j && ChessMap[tempY][i].type == 0 && tempY == y)
                {
                    return true;
                }
                else if (tempY != j && ChessMap[tempY][i].type != 0)
                {
                    isChess = true;
                    objX = i;
                    objY = tempY;
                    break;
                }

//                if (tempY != j && ChessMap[tempY][i].type == 0 && tempY == y)
//                {
//                    return true;
//                }
//                else if (tempY != j && ChessMap[tempY][i].type != 0)
//                {
//                    isChess = true;
//                    objX = i;
//                    objY = tempY;
//                    break;
//                }
            }
        }
        else if (y < j)
        {
            for (int tempY = j; tempY >= 0; tempY--)
            {
                if (tempY != j && ChessMap[tempY][i].type == 0 && tempY == y)
                {
                    return true;
                }
                else if (ChessMap[tempY][i].type != 0 && tempY != j)
                {
                    isChess = true;
                    objX = i;
                    objY = tempY;
                    break;
                }
            }
        }

    }
    else if (x != i && y == j)
    {
        if (x > i)
        {
            for (int tempX = i; tempX < COL; tempX++)
            {
                if (tempX != i && tempX == x && ChessMap[j][tempX].type == 0)
                {
                    return true;
                }
                else if (tempX != i && ChessMap[j][tempX].type != 0)
                {
                    isChess = true;
                    objX = tempX;
                    objY = j;
                    break;
                }
            }
        }
        else if (x < i)
        {
            for (int tempX = i; tempX >= 0; tempX--)
            {
                if (tempX != i && tempX == x && ChessMap[j][tempX].type == 0)
                {
                    return true;
                }
                else if (tempX != i && ChessMap[j][tempX].type != 0)
                {
                    isChess = true;
                    objX = tempX;
                    objY = j;
                    break;
                }
            }
        }
    }

    if (isChess)
    {
        if (objX > i)
        {
            for (int tempX = objX; tempX < COL; tempX++)
            {
                if (tempX != objX && ChessMap[j][tempX].type <= 7 && ChessMap[j][tempX].type >= 1)
                {
                    if(tempX == x)
                    return true;
                    return false;
                }
                else if(tempX != objX && ChessMap[j][tempX].type >= 8 && ChessMap[j][tempX].type <= 14)
                {
                    return false;
                }

//                if (tempX != objX && tempX == x && ChessMap[j][tempX].type <= 7 && ChessMap[j][tempX].type >= 1)
//                {
//                    return true;
//                }
            }
        }
        else if (objX < i)
        {
            for (int tempX = objX; tempX >= 0; tempX--)
            {
                if (tempX != objX && ChessMap[j][tempX].type <= 7 && ChessMap[j][tempX].type >= 1)
                {
                    if(tempX == x)
                    return true;
                    return false;
                }
                else if(tempX != objX && ChessMap[j][tempX].type >= 8 && ChessMap[j][tempX].type <= 14)
                {
                    return false;
                }
            }
        }
        else if (objY > j)
        {
            for (int tempY = objY; tempY < ROW; tempY++)
            {
                if (tempY != objY && ChessMap[tempY][i].type <= 7 && ChessMap[tempY][i].type >= 1)
                {
                    if(tempY == y)
                    return true;
                    return false;
                }
                else if(tempY != objY && ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
                {
                    return false;
                }

//                if (tempY != objY && tempY == y && ChessMap[tempY][i].type <= 7 && ChessMap[tempY][i].type >= 1)
//                {
//                    return true;
//                }
            }
        }
        else if (objY < j)
        {
            for (int tempY = objY; tempY >= 0; tempY--)
            {
                if (tempY != objY && ChessMap[tempY][i].type <= 7 && ChessMap[tempY][i].type >= 1)
                {
                    if(tempY == y)
                    return true;
                    return false;
                }
                else if(tempY != objY && ChessMap[tempY][i].type >= 8 && ChessMap[tempY][i].type <= 14)
                {
                    return false;
                }
            }
        }

    }

    return false;
}

bool RedXiang_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    int tempX = x, tempY = y;
    if (tempX > i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y - 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    if (tempX < i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y - 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    if (tempX < i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y + 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    if (tempX > i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y + 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }
            }

        }
    }
    return false;
}

bool BlackXiang_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    int tempX = x, tempY = y;
    if (tempX > i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y - 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    if (tempX < i && tempY > j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y - 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    if (tempX < i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y + 1][x + 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    if (tempX > i && tempY < j)
    {
        if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 8 && ChessMap[y + 1][x - 1].type == 0)
        {
            if (ChessMap[tempY][tempX].type == 0)
            {
                return true;
            }
            else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
            {
                if (tempX == x && tempY == y)
                {
                    return true;
                }

            }
            else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
            {
            }

        }
    }
    return false;
}

bool RedShi_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    if (x >= 3 && x <= 5 && y >= 0 && y <= 2)
    {
        if ((y == j + 1) || (y == j - 1))
        {
            if ((x == i + 1) || (x == i - 1))
            {
                if (ChessMap[y][x].type == 0)
                {
                    return true;
                }
                else if (ChessMap[y][x].type >= 8 && ChessMap[y][x].type <= 11)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}


//尹志豪
//int tempX = x, tempY = y;
//if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 1 && x >= 3 && x <= 5 && y >= 0 && y <= 2)
//{
//	if (ChessMap[tempY][tempX] == 0)
//	{
//		return true;
//	}
//	else if (ChessMap[tempY][tempX] >= 1 && ChessMap[tempY][tempX] <= 7)
//	{
//	}
//	else if (ChessMap[tempY][tempX] >= 8 && ChessMap[tempY][tempX] <= 14)
//	{
//		if (tempX == x && tempY == y)
//		{
//			return true;
//		}
//	}
//}
//return false;

bool BlackShi_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    if (x >= 3 && x <= 5 && y >= 7 && y <= 9)
    {
        if ((y == j + 1) || (y == j - 1))
        {
            if ((x == i + 1) || (x == i - 1))
            {
                if (ChessMap[y][x].type == 0)
                {
                    return true;
                }
                else if (ChessMap[y][x].type >= 1 && ChessMap[y][x].type <= 4)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

//尹志豪
//int tempX = x, tempY = y;
//if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 1 && x >= 3 && x <= 5 && y >= 7 && y <= 9)
//{
//	if (ChessMap[tempY][tempX] == 0)
//	{
//		return true;
//	}
//	else if (ChessMap[tempY][tempX] >= 1 && ChessMap[tempY][tempX] <= 7)
//	{
//		if (tempX == x && tempY == y)
//		{
//			return true;
//		}
//
//	}
//	else if (ChessMap[tempY][tempX] >= 8 && ChessMap[tempY][tempX] <= 14)
//	{
//	}
//}
//return false;

bool Shuai_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    int tempX = x, tempY = y;
    if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 1 && x >= 3 && x <= 5 && y >= 0 && y <= 2)
    {
        if (ChessMap[tempY][tempX].type == 0)
        {
            return true;
        }
        else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
        {
        }
        else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
        {
            if (tempX == x && tempY == y)
            {
                return true;
            }
        }
    }
    return false;
}

bool Jiang_Move(int x, int y, const Chess ChessMap[][COL], int j, int i)
{
    int tempX = x, tempY = y;
    if ((tempX - i) * (tempX - i) + (tempY - j) * (tempY - j) == 1 && x >= 3 && x <= 5 && y >= 7 && y <= 9)
    {
        if (ChessMap[tempY][tempX].type == 0)
        {
            return true;
        }
        else if (ChessMap[tempY][tempX].type >= 1 && ChessMap[tempY][tempX].type <= 7)
        {
            if (tempX == x && tempY == y)
            {
                return true;
            }

        }
        else if (ChessMap[tempY][tempX].type >= 8 && ChessMap[tempY][tempX].type <= 14)
        {
        }
    }
    return false;
}
