//
// Created by ricky on 9/17/2024.
//
#include "Life.h"
#include <iostream>
#include <cstring> //take a look at this when comming back


int Life::getCol() const {
    return col;
}

int Life::getRow() const {
    return row;
}

int Life::getHeight() const {
    return height;
}

int Life::getWidth() const {
    return width;
}
char Life::getFigure(int r, int c) const {
    return sprite[r][c];
}
void Life::inMatrix(Matrix *m) {
    matrix = m;
}
void Life::inSimulation(Simulation *s) {
    simulation = s;
}
bool Life::areWeInASimulation() {
    return simulation != nullptr;
}

//revise this code