#include <chesslib.hpp>

void init_desk(char desk[8][8])
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

void print_desk(char desk[8][8])
{
    const char v_nav[9] = "abcdefgh";

    for (int i = 0; i < 8; i++) {
        std::cout << 8 - i << " ";

        for (int j = 0; j < 8; j++)
            std::cout << desk[i][j] << " ";

        std::cout << std::endl;
    }

    std::cout << "  ";

    for (int i = 0; i < 8; i++) {
        std::cout << v_nav[i] << " ";
    }

    std::cout << std::endl;
}

Step interpret_notation(string notation)
{
    Step step;

    if (notation != "0-0-0" && notation != "0-0") {
        if (string("KQRBN").find(notation[0]) != -1)
            step.piece = notation[0];
        else {
            step.piece = 'P';
            notation.insert(0, "P");
        }
    }
    step.first_node.first = 7 - ((int)notation[2] - 49);
    step.first_node.second = ((int)notation[1] - 97);

    step.second_node.first = 7 - ((int)notation[5] - 49);
    step.second_node.second = (int)notation[4] - 97;

    return step;
}

void do_step(char desk[8][8], Step step)
{
    DeskCoord first = step.first_node;
    DeskCoord second = step.second_node;

    desk[second.first][second.second] = desk[first.first][first.second];
    desk[first.first][first.second] = ' ';
}

int check_step(char desk[8][8], Step step)
{
    if (is_existing_range(desk, step))
        return 1;
    return 0;
}

bool is_existing_range(char desk[8][8], Step step)
{
    bool temp = step.first_node.first >= 0 && step.first_node.first < 8;
    temp = temp && step.first_node.second >= 0 && step.first_node.second < 8;
    temp = temp && step.second_node.first >= 0 && step.second_node.first < 8;
    temp = temp && step.second_node.second >= 0 && step.second_node.second < 8;
    return !temp;
}

string err_massage(int cod_err)
{
    switch (cod_err) {
    case 1:
        return "unexisting range";
    default:
        return "undefined error";
    }
    return "undefined error";
}