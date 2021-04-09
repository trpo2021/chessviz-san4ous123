#include <libchessviz/checkstroka.h>
int checkstroka(char stroka)
{
    if (stroka == 'a')
        return 1;
    else if (stroka == 'b')
        return 2;
    else if (stroka == 'c')
        return 3;
    else if (stroka == 'd')
        return 4;
    else if (stroka == 'e')
        return 5;
    else if (stroka == 'f')
        return 6;
    else if (stroka == 'g')
        return 7;
    else if (stroka == 'h')
        return 8;
    else
        return -1;
}
