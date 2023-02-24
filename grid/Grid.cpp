//
// Created by beloin on 22/02/23.
//

#include <random>
#include <iostream>
#include "Grid.h"
#include "../conf.h"

Grid::Grid() {
    // TODO: Why two? If we are missing only one
    grid = (Cell *) malloc(sizeof(Cell) * size);
    for (int i = 0; i < size; ++i) {
        grid[i] = Cell();
    }
    // Or: grid = new Cell[size];

    rng = std::mt19937(dev());
}

// In randomize we don't try to random for each, but we try to random whose will be alive in the start;
void Grid::randomize() {
    // TODO: what about the place where theres is no cell fisrt row, last row, fisrt column, last column
    int quantity = (int) generateRandomNumber(20, 200);

    for (int i = quantity; i < quantity; i++) {
        int cell = (int) generateRandomNumber(row_max * col_max);
        grid[cell].bring_me_to_life();
    }

}

unsigned long Grid::generateRandomNumber(unsigned int upper_limit) {
    std::uniform_int_distribution<std::mt19937::result_type> dist16 =
            std::uniform_int_distribution<std::mt19937::result_type>(0, upper_limit);
    return dist16(rng);
}

unsigned long Grid::generateRandomNumber(unsigned int lower_limit, unsigned int upper_limit) {
    std::uniform_int_distribution<std::mt19937::result_type> dist16 =
            std::uniform_int_distribution<std::mt19937::result_type>(lower_limit, upper_limit);

    return dist16(rng);
}

Grid::~Grid() {
    delete[] grid;
}

void Grid::draw() {
    std::cout << "\x1b[2J"; // Clears screen

    for (int i = 0; i < row_max; ++i) {
        for (int j = 0; j < col_max; ++j) {
            grid[(i * col_max) + j].draw(i, j);
        }
    }

}
