//
// Created by beloin on 22/02/23.
//

#ifndef CONWAYS_GAME_CONF_H
#define CONWAYS_GAME_CONF_H

const char live_cell{'X'};
const char dead_cell{' '};

// The “normal” size for a terminal is 80 columns by 24 rows.
// An ANSI terminal starts with 1, and not 0;
// Escape char = \x1b
const int row_max = 23;
const int col_max = 79;


const int min_neighbours = 2;
const int max_neighbours = 3;

const int min_parents = 3;
const int max_parents = 3;

#endif //CONWAYS_GAME_CONF_H
