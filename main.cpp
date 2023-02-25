//
// Created by beloin on 22/02/23.
//

#include "iostream"
#include "grid/Grid.h"
#include <unistd.h>

int main(int n, char **args) {
    std::cout << "Welcome to Conway's game of Life" << std::endl;
    // TODO: Add configurations
//    std::cout << "Please, next we have configurations:" << std::endl;
    std::cout
            << "Remember, press \"Enter\" each time to go through generations. You can keep enter pressed to go faster."
            << std::endl;
    std::cout << "Please, press enter to start." << std::endl;
    std::cin.get();

    Grid current;
    char key;

    current.randomize();

    while (true) {
        Grid next;

        current.draw();

        // If we want to keep step by step
        std::cin.get(key);
        if (key == 'q' || key == 81) {
            break;
        }
//        usleep(500000); // 1 -> 1_000_000
        next.calculate(current);

        current.copy(next);
    }

    std::cout << "\x1b[" << ";" << row_max - 1 << "H";

    return 0;
}