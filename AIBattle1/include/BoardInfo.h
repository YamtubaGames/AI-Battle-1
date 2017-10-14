#ifndef BOARDINFO_H
#define BOARDINFO_H

#include <Board.h>
#include <cstring>

struct BoardInfo
{
    public:
        BoardInfo(Board &InputBoard);

        char* UnitMap;
        bool* WallMap;

        int height, width;

        int getIndex(Coord Coordinate);
        int getIndex(int x, int y);
};

#endif // BOARDINFO_H
