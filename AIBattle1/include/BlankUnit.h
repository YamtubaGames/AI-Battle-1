#ifndef BLANKUNIT_H
#define BLANKUNIT_H

#include <Unit.h>

class BlankUnit : virtual Unit
{
    public:
        BlankUnit(Unit* BoardState);

        bool Move(Coord From, Coord To);

    protected:

    private:
};

#endif // BLANKUNIT_H
