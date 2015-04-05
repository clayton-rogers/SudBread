#ifndef BOARD_H
#define BOARD_H


#include <vector>
#include <string>
#include <array>
#include "Square.h"

class Board {
private:
    std::array<Square, 81> squares;
    std::vector<Board> solutions;

    Board(std::array<Square, 81> other_squares)
            : squares(other_squares) {};

public:
    Board(const Board & other);
    Board();
    ~Board();

    void clear_board();
    void load_from_file (const char * filename);
    std::vector<Board> get_solutions() const;
    std::string to_string();
    void set_square(unsigned int position_x,
                    unsigned int position_y,
                    int value);
    int get_square(unsigned int position_x,
                   unsigned int position_y) const;
};


#endif
