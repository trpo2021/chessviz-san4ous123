#include <chesslib.hpp>
#include <list>
using namespace std;

int main()
{
    char chess_desk[8][8];
    init_desk(chess_desk);
    Step temp_step;
    string notation;
    list<string> notations;

    cin >> notation;
    while (true) {
        cin >> notation;
        notations.push_back(notation);
        if (notation.find('#') != -1)
            break;

        cin >> notation;
        notations.push_back(notation);
        if (notation.find('#') != -1)
            break;

        cin >> notation;
    }

    cout << endl;

    print_desk(chess_desk);
    int i = 0;
    int cod_err;

    for (auto it = notations.begin(); it != notations.end(); ++it, i++) {
        temp_step = interpret_notation(*it);

        cod_err = check_step(chess_desk, temp_step);
        if (cod_err) {
            cout << endl
                 << "!!!" << err_massage(cod_err) << " in " << (i / 2) + 1
                 << " notation!!!" << endl;
            return cod_err;
        }

        do_step(chess_desk, temp_step);
        cout << endl << (i / 2) + 1 << ". " << *it << endl << endl;
        print_desk(chess_desk);
    }

    return 0;
}