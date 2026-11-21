#include <iostream>
#include <vector>
#include <random>

using namespace std;

enum State {
    MINE,
    EMPTY,
    NUMBER
};

struct Cell {
    State state = EMPTY;
    bool lock = true;
    int number = 0;
};

void generate_mines(vector<Cell>& board, const int& mines_count, const int& rows, const int& cols) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution row_dist(0, rows-1);
    uniform_int_distribution col_dist(0, cols-1);

    int k = 0;
    while (k < mines_count) {
        const int row = row_dist(gen);
        const int col = col_dist(gen);

        if (const int coordinate = cols * row + col;
            board[coordinate].state != MINE) {
            board[coordinate].state = MINE;
            cout << board[coordinate].state << endl;
            k++;
        }
    }
}

// x, y => rows * y + x

int main() {
    constexpr int rows = 10;
    constexpr int cols = 10;
    constexpr int mines_count = 10;

    vector<Cell> board(rows * cols);

    generate_mines(board, mines_count, rows, cols);

    for (int i = 0; i < 100; i++) {
        if (board[i].state == MINE) {
            cout << "ok\n";
        }
    }

    return 0;
}