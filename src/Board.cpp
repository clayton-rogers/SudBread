#include "Board.h"

#include <cstdio>
#include <fstream>

Board::Board() {
    clear_board();
}

Board::Board(const Board & other) {
    for (unsigned int i = 0; i != 81; ++i) {
        squares.at(i) = other.squares.at(i);
    }
}

Board::~Board() {

}

void Board::clear_board() {
    squares.fill(Square(0, false));
    solutions.clear();
}

std::vector<Board> Board::get_solutions() const {

    return solutions;
}


void Board::load_from_file(const char *filename) {
    std::ifstream fin;
    fin.open(filename);

    if (fin.fail()) {

    }
}


void Board::set_square(unsigned int position_x, unsigned int position_y, int value) {
    squares.at(position_x + position_y*9).m_value = value;
}


int Board::get_square(unsigned int position_x, unsigned int position_y) const {
    return squares.at(position_x + position_y*9).m_value;
}

std::string Board::to_string() {
    std::string ret_value;

    char int_string[30];

    for (unsigned int x = 0; x != 9; ++x) {
        for (unsigned int y = 0; y != 9; ++y) {
            sprintf(int_string,"%d",get_square(x, y));
            ret_value += std::string(int_string) + " ";
        }
        ret_value += "\n";
    }

    return ret_value;
}
