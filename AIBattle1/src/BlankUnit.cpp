#include "BlankUnit.h"

BlankUnit::BlankUnit(Unit* BoardState)
{
    displayChar = 'x';
}

bool BlankUnit::Move(Coord From, Coord To)
{
    return false;
}
