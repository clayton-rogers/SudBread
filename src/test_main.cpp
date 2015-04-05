#include <cstdio>
#include "Board.h"

int main () {
    Board board;

    printf("%s", board.to_string().c_str());

    for (unsigned int i = 0; i != 81; ++i) {
        int value = int(i%9);
        board.set_square(i, 0, value);
    }

    for (unsigned int x = 0; x != 9; ++x) {
        for (unsigned int y = 0; y != 9; ++y) {
            board.set_square(x, y, int(y));
        }
    }

    printf("%s", board.to_string().c_str());

    return 0;
}