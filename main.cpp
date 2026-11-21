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
    State state;
    bool lock;
    int number;
};

void generate_mines(vector<Cell> board) {

}

int main() {
    constexpr int rows = 10;
    constexpr int cols = 10;

    vector<Cell> board {rows * cols};

    return 0;
}