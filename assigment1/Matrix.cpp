#include "Matrix.h"
#include "const.h"
#include "Life.h"
#include <iostream>
Matrix::Matrix() {
    toggle = true;
    grid_1 = new char*[CANVAS_ROW];
    grid_2 = new char*[CANVAS_ROW];

    for (char i = 0; i < CANVAS_ROW; i++) {
        grid_1[i] = new char[CANVAS_COL];
        grid_2[i] = new char[CANVAS_COL];
    }
    for (char i = 0; i < CANVAS_ROW; i++) {
        for (char j = 0; j < CANVAS_COL; j++) {
            grid_1[i][j] = DEAD;
        }
    }
}

Matrix::~Matrix() {
    for (char i = 0; i < CANVAS_ROW; i++) {
        delete[] grid_1[i];
        delete[] grid_2[i];
    }
    delete[] grid_1;
    delete[] grid_2;

}

void Matrix::render() const {
    clearScreen();
    if (toggle) {
        for (char i = 0; i < CANVAS_ROW; i++) {
            for (char j = 0; j < CANVAS_COL; j++) {
                std::cout << grid_1[i][j];
            }
            std::cout << std::endl;
        }
    }
    else {
        for (char i = 0; i < CANVAS_ROW; i++) {
            for (char j = 0; j < CANVAS_COL; j++) {
                std::cout << grid_2[i][j];
            }
            std::cout << std::endl;
        }
    }
    for (char i = 0; i < CANVAS_COL; i++) {
        std::cout << '=';
    }
    std::cout << std::endl;
}

void Matrix::computeNextState() {
    if (toggle) {
        for (char i = 0; i < CANVAS_ROW; i++) {
            for (char j = 0; j < CANVAS_COL; j++) {
                grid_2[i][j] =
                    nextState(grid_1[i][j], i, j, toggle);
            }
        }
        toggle = !toggle;
    }
    else {
        for (char i = 0; i < CANVAS_ROW; i++) {
            for (char j = 0; j < CANVAS_COL; j++) {
                grid_1[i][j] =
                    nextState(grid_2[i][j], i, j, toggle);
            }
        }
        toggle = !toggle;
    }
}

bool Matrix::initState(Life *life) {
    if (life == nullptr) {
        std::cout << "Cannot add nullptr life" << std::endl;
        return false;
    }
    for (char i = life->getRow(); i - life->getRow() < life->getHeight(); i++) {
        for (char j = life->getCol(); j - life->getCol() < life->getWidth(); j++) {
            if (i < CANVAS_ROW && j < CANVAS_COL) {
                grid_1[i][j] =
                    life->getFigure(i - life->getRow(), j - life->getCol());
            }
        }
    }
    return true;
}