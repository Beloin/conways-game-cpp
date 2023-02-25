//
// Created by beloin on 22/02/23.
//

#ifndef CONWAYS_GAME_GRID_H
#define CONWAYS_GAME_GRID_H


#include "Cell.h"
#include "random"
#include "../conf.h"

class Grid {
private:
    Cell *grid;
    int size = (row_max + 2) * (col_max + 2);

    static unsigned long generateRandomNumber(unsigned int upper_limit);

    static unsigned long generateRandomNumber(unsigned int lower_limit, unsigned int upper_limit);

    static int getIndex(int row, int column) ;

public:

    Grid();

    ~Grid();

    void randomize();

    void draw();

    void copy(const Grid &other);

    void create(int row, int col);

    void calculate(const Grid &other);

    bool will_survive(int row, int col) const;

    bool will_create(int row, int col) const;
};


#endif //CONWAYS_GAME_GRID_H
