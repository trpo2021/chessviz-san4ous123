#include <iostream>
#include <libchessviz/checkstroka.h>
#include <libchessviz/checktab.h>
#include <libchessviz/mistake.h>
#include <libchessviz/output.h>
#include <stdio.h>
using namespace std;

char locate(char chessdesk[11][11])
{
    char sline1, sline2, temp;
    int column1, column2, rline1, rline2, flag1, flag2, flag3;

    cin >> sline1;
    cin >> column1;
    cin >> sline2;
    cin >> column2;

    flag1 = 0;
    flag2 = 0;
    flag3 = 0;

    rline1 = checkstroka(sline1);
    if (rline1 == -1)
        flag1 = 1;

    rline2 = checkstroka(sline2);
    if (rline2 == -1)
        flag1 = 1;

    flag2 = checktab(column1);
    flag3 = checktab(column2);

    if (flag1 == 0 && flag2 == 0 && flag3 == 0) {
        temp = chessdesk[column1 - 1][rline1];
        chessdesk[column1 - 1][rline1] = ' ';
        chessdesk[column2 - 1][rline2] = temp;
        output(chessdesk);
    } else {
        mistake(1);
    }

    return chessdesk[9][10];
}
