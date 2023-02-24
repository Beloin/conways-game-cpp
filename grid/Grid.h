//
// Created by beloin on 22/02/23.
//

#ifndef CONWAYS_GAME_GRID_H
#define CONWAYS_GAME_GRID_H


#include "Cell.h"
#include "../conf.h"

class Grid {
private:
    Cell *grid;
    int size = (row_max + 2) * (col_max + 2);

    std::random_device dev;
    std::mt19937 rng;

    unsigned long generateRandomNumber(unsigned int upper_limit);

    unsigned long generateRandomNumber(unsigned int lower_limit, unsigned int upper_limit);

    ~Grid();

public:

    Grid();

    void randomize();

    void draw();

    // update
    void copy(const Grid &other);

    void calculate(const Grid &other);

    bool will_survive(int row, int col);

    bool will_create(int row, int col);
};


#endif //CONWAYS_GAME_GRID_H
