#pragma once
#include <iostream>
#include <string>

using namespace std;

//Псевдоним для пары двух целых чисел
typedef pair<int, int> DeskCoord;

//Структура для сохранения информации о ходе
struct Step {
    char piece;
    DeskCoord first_node;
    DeskCoord second_node;
};

//Заполняет Step по нотации
Step interpret_notation(string notation);

//Первоначально заполняет доску
void init_desk(char desk[8][8]);

//Выполняет шаг
void do_step(char desk[8][8], Step step);

//Выводит доску в консоль
void print_desk(char desk[8][8]);

//Возвращает код ошибки, если она есть в нотации
int check_step(char desk[8][8], Step step);

//Возвращает 1 если шаг выходит за границы доски
bool is_existing_range(Step step);

//Возвращает сообщение соответствующее коду ошибки
string err_massage(int cod_err);