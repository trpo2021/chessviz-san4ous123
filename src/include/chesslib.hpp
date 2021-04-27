#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> DeskCoord;

enum TypeMove { QuietMove, Take };

struct Step {
    char piece;
    DeskCoord first_node;
    DeskCoord second_node;
    TypeMove type_move;
    char transform_piece;
};

Step interpret_notation(string notation);

void init_desk(char desk[8][8]);

void do_step(char desk[8][8], Step step);

void print_desk(char desk[8][8]);
