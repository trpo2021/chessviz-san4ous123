#include <chesslib.hpp>

void init_desk(char* desk[8])
{
    desk[0][0] = 'r';
    desk[0][1] = 'n';
    desk[0][2] = 'b';
    desk[0][3] = 'q';
    desk[0][4] = 'k';
    desk[0][5] = 'b';
    desk[0][6] = 'n';
    desk[0][7] = 'r';

    for (int i = 0; i < 8; i++)
        desk[1][i] = 'p';
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < 8; j++)
            desk[i][j] = ' ';
    for (int i = 0; i < 8; i++)
        desk[6][i] = 'P';

    desk[7][0] = 'R';
    desk[7][1] = 'N';
    desk[7][2] = 'B';
    desk[7][3] = 'Q';
    desk[7][4] = 'K';
    desk[7][5] = 'B';
    desk[7][6] = 'N';
    desk[7][7] = 'R';
}