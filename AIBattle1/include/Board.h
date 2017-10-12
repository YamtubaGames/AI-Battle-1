#ifndef BOARD_H
#define BOARD_H

#include <Coord.h>
//#include <BlankUnit.h>
#include <UnitMovement.h>

class Board
{
    public:
        Board(int height, int width);
        virtual ~Board();

        char* UnitMap;
        bool* WallMap;

        bool Move(Coord From, Coord To, bool isShooting);

        int height, width;

        int getIndex(Coord Coordinate);
        int getIndex(int x, int y);

    private:
        bool InBounds(Coord Target);
};

#endif // BOARD_H
