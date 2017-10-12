#ifndef UNIT_H
#define UNIT_H

#include <Coord.h>
#include <BoardChecker.h>

class Unit
{
    public:
        Unit() {};
        Unit(Unit* BoardState);

        virtual bool Move(Coord From, Coord To) = 0; //{return false;};
        bool Shoot(Coord From, Coord To) {return false;};

        char displayChar;
};

#endif // UNIT_H
