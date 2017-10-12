#ifndef TURNDECISION_H
#define TURNDECISION_H

#include <Coord.h>

struct TurnDecision
{
    public:
        bool buildWall, shoot;
        Coord From, To;

};

#endif // TURNDECISION_H
