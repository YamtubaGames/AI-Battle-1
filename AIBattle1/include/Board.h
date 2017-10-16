#ifndef BOARD_H
#define BOARD_H

#include <Coord.h>
//#include <BlankUnit.h>
#include <TurnDecision.h>

class Board
{
    public:
        Board(int height, int width);
        virtual ~Board();

        char* UnitMap;
        bool* WallMap;

        bool Move(Coord From, Coord To, bool isShooting);
        bool BuildWall(Coord Tile); // Trump's favorite function
        bool Exec(TurnDecision InputMove, bool team);

        int height, width;

        int getIndex(Coord Coordinate);
        int getIndex(int x, int y);

    private:
        bool InBounds(Coord Target);

        bool UnitMove(char Index, bool shooting, Coord From, Coord To);

        int getTeam(char Index);
};

#endif // BOARD_H
