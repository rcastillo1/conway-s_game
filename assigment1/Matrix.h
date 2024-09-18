#include "const.h"
#include "Life.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <chrono>


#ifndef MATRIX_H
#define MATRIX_H


class Matrix {
public:
	Matrix();

	~Matrix();

	void render() const;

	void computeNextState();

	bool initState(Life *life);

private:

	void clearScreen() const {
#ifdef _MSC_VER  // DO NOT BREAK APART THE PREPROCESSOR DIRECTIVES
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
		COORD upperLeft = { 0, 0 };
		DWORD dwCharsWritten;
		FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
			&dwCharsWritten);
		SetConsoleCursorPosition(hConsole, upperLeft);
#else
		static const char* term = getenv("TERM");// will just write a newline in an Xcode output window
		if (term == nullptr || strcmp(term, "dumb") == 0)
			std::cout << std::endl;
		else {
			static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
			std::cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << std::flush;
		}
#endif
	}
	char nextState(char state, char row, char col, bool toggle) const {
		int yCoord = row;
		int xCoord = col;
		char neighbors = 0;
		if (toggle) {
			for (char i = yCoord - 1; i <= yCoord + 1; i++) {
				for (char j = xCoord - 1; j <= xCoord + 1; j++) {
					if (i == yCoord && j == xCoord) {
						continue;
					}
					if (i > -1 && i < CANVAS_ROW && j > -1 && j < CANVAS_COL) {
						if (grid_1[i][j] == ALIVE) {
							neighbors++;
						}
					}
				}
			}
		}
		else {
			for (char i = yCoord - 1; i <= yCoord + 1; i++) {
				for (char j = xCoord - 1; j <= xCoord + 1; j++) {
					if (i == yCoord && j == xCoord) {
						continue;
					}
					if (i > -1 && i < CANVAS_ROW && j > -1 && j < CANVAS_COL) {
						if (grid_2[i][j] == ALIVE) {
							neighbors++;
						}
					}
				}
			}
		}
		if (state == ALIVE) {
			return (neighbors > 1 && neighbors < 4) ? ALIVE : DEAD;
		}
		else {
			return (neighbors == 3) ? ALIVE : DEAD;
		}
	}

	// The rules of Conway's Simulation of Life requires each cell to
	// examine it's neighbors.  So, we have to check the entire matrix
	// first before we change it.  We can use two copies of the matrix,
	// one to check the current state (current day) then another to generate
	// the next state(for the next day). We can toggle between them each
	// step, to avoid having to copy between matrix each step (day) of the game.
	char **	grid_1;
	char **	grid_2;
	bool	toggle;
};



#endif //MATRIX_H
