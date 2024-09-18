#include "Simulation.h"
#include "const.h"
#include "Matrix.h"
#include <iostream>
#include "Life.h"
#include <chrono>
#include <thread>
Simulation::Simulation(Life **life, int numLife) {
    watchme = 1;
    steps = 0;
    automate = false;
    matrix = new Matrix();

    if (life != nullptr) {
        for (int i = 0; i < numLife; i++) {
            if (life[i] != nullptr) {
                bool success = matrix->initState(life[i]);
                if (!success) {
                    std::cout << "Failed to add life to the matrix" << std::endl;
                }
            }
        }
    }
}

Simulation::~Simulation() {
    delete matrix;
}

void Simulation::simulate() {
    while (true) {
        matrix->render();

        if (!automate) {
            std::cout << "command (<space> to step, <a> to automate, <q> to quit): ";

            std::string action;
            std::getline(std::cin, action);

            switch (action[0])
            {

                default:
                    std::cout << '\a' << std::endl;  // beep
                continue;
                case 'q':
                    std::cout << "Quitting Game." << std::endl;
                return;
                case 's':

                    continue;
                case ' ':

                    break;
                case 'a':
                    automate = true;
                break;
            }
        }
        else {
            if (steps >= MAX_STEPS) {
                std::cout << "Reached max steps, quitting." << std::endl;
                return;
            }
            delay(300);
        }
        steps++;
        matrix->computeNextState();
    }
}

void Simulation::report() {
    std::string msg = "Hello World!"; // Replace Hello World with your answer.
    std::cout << msg << std::endl;
}
int Simulation::two(int u) {
    return (u << 2) % 10;
}
int Simulation::three(int x) {
    if (x % 2 == 0)
        return 5;
    else
        return 3;
}
void Simulation::one(int t) {
    int i = 0;
    int k = watchme;
    while (++i < t) {
        if (i == 0)
            k = 2;
        else if (i == 1)
            k = 7;
        else if (i == 4)
            k = 8;
        else if (i == 5)
            k = 5;
        else
            k = two(watchme);
        watchme = k;
    }
    k = three(watchme);
    watchme = k;
}