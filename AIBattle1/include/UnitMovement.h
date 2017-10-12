#ifndef UNITMOVEMENT_H
#define UNITMOVEMENT_H

#include <Coord.h>
#include <ctype.h>

bool UnitMove(char Index, bool shooting, Coord From, Coord To, bool FromWalled, bool ToWalled);

char getUnitDisplay(char Index, bool walled);

const char UnitCharacters[] = {'x', 'a', 'b', 'c', 'e', 'd', 'f'};

#endif // UNITMOVEMENT_H
