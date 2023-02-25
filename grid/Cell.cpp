//
// Created by beloin on 22/02/23.
//

#include "Cell.h"
#include "iostream"
#include "../conf.h"

void Cell::draw(int row, int col) const {
    // TODO: Could put this platform specific code elsewhere.
    // Commands in ANSI terminal starts with 1.
    std::cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
    std::cout << (alive ? live_cell : dead_cell);
}
