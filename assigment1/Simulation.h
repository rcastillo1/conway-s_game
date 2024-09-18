#include "Life.h"
#include <chrono>
#include <thread>
#include "Matrix.h"

#ifndef SIMULATION_H
#define SIMULATION_H



class Simulation {
public:
    Simulation(Life **life, int numLife);

    ~Simulation();

    void simulate();

    void report();

    int two(int u);

    int three(int x);

    void one(int t);

private:
    void delay(int ms) const {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    int		watchme;
    Matrix * matrix;
    int		steps;
    bool	automate;
};

#endif //SIMULATION_H
