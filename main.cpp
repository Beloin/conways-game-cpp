//
// Created by beloin on 22/02/23.
//

#include "iostream"
#include "grid/Grid.h"

int main(int n, char **args) {
    std::cout << "Welcome to Conway's game of Life" << std::endl;
    // TODO: Add configurations
    std::cout << "Please, press enter to start." << std::endl;
    std::cin.get();

    Grid current;
    Grid next;
    char key;

    current.randomize();

    while (true) {
        current.draw();

        // If we want to keep step by step
        std::cin.get(key);
        if (key == 'q' || key == 81) {
            return 0;
        }

        next.calculate(current);

        current.copy(next);
    }
}