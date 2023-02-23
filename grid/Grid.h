//
// Created by beloin on 22/02/23.
//

#ifndef CONWAYS_GAME_GRID_H
#define CONWAYS_GAME_GRID_H


class Grid {
private:
    char *grid;

public:
    Grid();

    void randomize();
    void draw();

    void copy(const Grid &other);
    void calculate(const Grid &other);
};


#endif //CONWAYS_GAME_GRID_H
