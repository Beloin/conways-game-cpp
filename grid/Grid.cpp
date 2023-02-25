//
// Created by beloin on 22/02/23.
//

#include <random>
#include <iostream>
#include <functional>
#include "Grid.h"

std::random_device random_dev;
//std::mt19937 rng = std::mt19937(565);
std::mt19937 rng = std::mt19937(random_dev());

Grid::Grid() {
    // TODO: Why two? If we are missing only one
    grid = (Cell *) malloc(sizeof(Cell) * size);
    for (int i = 0; i < size; ++i) {
        grid[i] = Cell();
    }
    // Or: grid = new Cell[size];

}

// In randomize we don't try to random for each, but we try to random whose will be alive in the start;
void Grid::randomize() {
    int quantity = (int) generateRandomNumber(20, row_max * col_max / 5);

    for (int i = 0; i < quantity; i++) {
        int cell = (int) generateRandomNumber(row_max * col_max);
        grid[cell].bring_me_to_life();
    }

}

unsigned long Grid::generateRandomNumber(unsigned int upper_limit) {
    std::uniform_int_distribution<std::mt19937::result_type> dist =
            std::uniform_int_distribution<std::mt19937::result_type>(0, upper_limit);
    return dist(rng);
}

unsigned long Grid::generateRandomNumber(unsigned int lower_limit, unsigned int upper_limit) {
    std::uniform_int_distribution<std::mt19937::result_type> dist =
            std::uniform_int_distribution<std::mt19937::result_type>(lower_limit, upper_limit);
    return dist(rng);
}

Grid::~Grid() {
    delete[] grid;
}

void Grid::draw() {
    std::cout << "\x1b[2J"; // Clears screen

    for (int i = 0; i < row_max + 2; ++i) {
        for (int j = 0; j < col_max + 2; ++j) {
            grid[(i * col_max) + j].draw(i, j);
        }
    }

}

void Grid::copy(const Grid &other) {
    for (int i = 0; i < row_max; ++i) {
        for (int j = 0; j < col_max; ++j) {
            int index = (i * col_max) + j;
            // This copy the other_cell into current_cell location
            Cell *current_cell = &grid[index];
            Cell other_cell = other.grid[index];
            *current_cell = other_cell;
        }
    }
}

void Grid::calculate(const Grid &other) {
    for (int row = 0; row < row_max; ++row) {
        for (int col = 0; col < col_max; ++col) {
            if (other.will_survive(row, col)) {
                this->create(row, col);
            } else if (other.will_create(row, col)) {
                this->create(row, col);
            }
        }
    }
}

bool Grid::will_survive(int row, int col) const {
    if (grid[getIndex(row, col)].isDead()) {
        return false;
    }

    // All calculations are based in the number of living neighbours of the cell;
    // *  *  *
    // * [X] *
    // *  *  *

    int col_t, row_t;
    int living_neighbours = 0;

    // (*)  *   *
    //  *  [X]  *
    //  *   *   *
    row_t = row - 1;
    col_t = col - 1;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();
    //  *  (*)  *
    //  *  [X]  *
    //  *   *   *
    row_t = row - 1;
    col_t = col;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();
    //  *   *  (*)
    //  *  [X]  *
    //  *   *   *
    row_t = row - 1;
    col_t = col + 1;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();

    //  *   *  *
    // (*) [X] *
    //  *   *  *
    row_t = row;
    col_t = col - 1;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();
    // *   *   *
    // *  [X] (*)
    // *   *   *
    row_t = row;
    col_t = col + 1;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();

    //  *   *   *
    //  *  [X]  *
    // (*)  *   *
    row_t = row + 1;
    col_t = col - 1;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();
    // *   *   *
    // *  [X]  *
    // *  (*)  *
    row_t = row + 1;
    col_t = col;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();
    // *   *   *
    // *  [X]  *
    // *   *  (*)
    row_t = row + 1;
    col_t = col + 1;
    living_neighbours += grid[getIndex(row_t, col_t)].isAlive();


    if (living_neighbours < min_neighbours || living_neighbours > max_neighbours) {
        return false;
    }

    return true;
}

bool Grid::will_create(int row, int col) const {
    if (grid[getIndex(row, col)].isAlive()) {
        return false;
    }

    // All calculations are based in the number of living neighbours of the cell;
    // *  *  *
    // * [X] *
    // *  *  *

    int col_t, row_t;
    int parents = 0;

    // (*)  *   *
    //  *  [X]  *
    //  *   *   *
    row_t = row - 1;
    col_t = col - 1;
    parents += grid[getIndex(row_t, col_t)].isAlive();
    //  *  (*)  *
    //  *  [X]  *
    //  *   *   *
    row_t = row - 1;
    col_t = col;
    parents += grid[getIndex(row_t, col_t)].isAlive();
    //  *   *  (*)
    //  *  [X]  *
    //  *   *   *
    row_t = row - 1;
    col_t = col + 1;
    parents += grid[getIndex(row_t, col_t)].isAlive();

    //  *   *  *
    // (*) [X] *
    //  *   *  *
    row_t = row;
    col_t = col - 1;
    parents += grid[getIndex(row_t, col_t)].isAlive();
    // *   *   *
    // *  [X] (*)
    // *   *   *
    row_t = row;
    col_t = col + 1;
    parents += grid[getIndex(row_t, col_t)].isAlive();

    //  *   *   *
    //  *  [X]  *
    // (*)  *   *
    row_t = row + 1;
    col_t = col - 1;
    parents += grid[getIndex(row_t, col_t)].isAlive();
    // *   *   *
    // *  [X]  *
    // *  (*)  *
    row_t = row + 1;
    col_t = col;
    parents += grid[getIndex(row_t, col_t)].isAlive();
    // *   *   *
    // *  [X]  *
    // *   *  (*)
    row_t = row + 1;
    col_t = col + 1;
    parents += grid[getIndex(row_t, col_t)].isAlive();


    if (parents < min_parents || parents > max_parents) {
        return false;
    }

    return true;
}

void Grid::create(int row, int col) {
    grid[getIndex(row, col)].bring_me_to_life();
}

int Grid::getIndex(int row, int column) {
    return (row * col_max) + column;
}
