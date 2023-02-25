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
    Cell(const Cell &cell) = default;

    void draw(int row, int col) const;

    void bring_me_to_life() {
        alive = true;
    }

    bool isAlive() const {
        return alive;
    }

    bool isDead() const {
        return !alive;
    }

    void setAlive(bool new_alive) {
        this->alive = new_alive;
    }


};


#endif //CONWAYS_GAME_CELL_H
