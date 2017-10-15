#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <iostream>
#include <sstream>

#include <Board.h>

void Draw(Board &DrawBoard);
char getUnitDisplay(char Index, bool walled);

const char UnitCharacters[] = {'x', 'a', 'b', 'c', 'e', 'd', 'f'};

#endif // DISPLAY_H
