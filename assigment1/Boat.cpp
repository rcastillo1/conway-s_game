//
// Created by ricky on 9/17/2024.
//
#include "Boat.h"
#include "const.h"
Boat::Boat(int r, int c) {
    col = c;
    row = r;
    height = BOAT_SIZE;
    width = BOAT_SIZE;

    // Allocate space for figure
    sprite = new char*[height];
    for (int i = 0; i < height; i++) {
        sprite[i] = new char[width];
    }

    // Initialize figure
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sprite[i][j] = DEAD;
        }
    }
    sprite[0][1] = ALIVE;
    sprite[1][2] = ALIVE;
    sprite[1][0] = ALIVE;
    sprite[2][1] = ALIVE;
    sprite[2][2] = ALIVE;
}
Boat::~Boat() {
    for (int i = 0; i < height; i++) {
        delete[] sprite[i];
    }
    delete[] sprite;
}