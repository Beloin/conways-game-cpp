//
// Created by beloin on 22/02/23.
//

#ifndef CONWAYS_GAME_CELL_H
#define CONWAYS_GAME_CELL_H


class Cell {

private:
    bool alive;

public:
    Cell() : alive(false) {}

    void draw(int row, int col);

    void bring_me_to_life() {
        alive = true;
    }

    void die() {
        alive = false;
    }

    bool is_alive() const {
        return alive;
    }
};


#endif //CONWAYS_GAME_CELL_H
