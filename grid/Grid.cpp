//
// Created by beloin on 22/02/23.
//

#include "Grid.h"
#include "../conf.h"

Grid::Grid() {
    int size = row_count * col_count;
    grid = new char[size];
}
