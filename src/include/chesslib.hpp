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
};

Step interpret_notation(string notation);

void init_desk(char desk[8][8]);

void do_step(char desk[8][8], Step step);

void print_desk(char desk[8][8]);

int check_step(char desk[8][8], Step step);

bool is_existing_range(char desk[8][8], Step step);

string err_massage(int cod_err);