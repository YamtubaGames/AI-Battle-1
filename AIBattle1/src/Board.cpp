#include "Board.h"

Board::Board(int height, int width)
{
    this->height = height;
    this->width = width;

    UnitMap = new char[height * width];
    WallMap = new bool[height * width];
}

Board::~Board()
{
    delete[] UnitMap;
    delete[] WallMap;
}

bool Board::Move(Coord From, Coord To, bool isShooting)
{
    if(!InBounds(From) || !InBounds(To))
        return false;

    bool valid = UnitMove(UnitMap[getIndex(From)], isShooting, From, To, WallMap[getIndex(From)], WallMap[getIndex(To)]);

    if(valid)
    {
        if(!isShooting)
        {
            UnitMap[getIndex(To)] = UnitMap[getIndex(From)];
            UnitMap[getIndex(From)] = 0;
        }
        else
        {
            UnitMap[getIndex(To)] = 0;
        }
    }

    return valid;
}

bool Board::BuildWall(Coord Tile)
{
    if(!InBounds(Tile))
        return false;
    if(WallMap[getIndex(Tile)])
        return false;
    if(UnitMap[getIndex(Tile)] == 2 || UnitMap[getIndex(Tile)] == 5)
    {
        WallMap[getIndex(Tile)] = true;
        return true;
    }
    else
        return false;
}

bool Board::Exec(TurnDecision InputMove, bool team)
{
    // TODO: Check team's affiliation
    if(InputMove.buildWall)
        return BuildWall(InputMove.From);
    else
        return Move(InputMove.From, InputMove.To, InputMove.shoot);
}

bool Board::InBounds(Coord Target)
{
    if(Target.x >= 0 && Target.y >= 0 && Target.x <= width && Target.y <= height)
        return true;
    return false;
}

int Board::getIndex(int x, int y)
{
    return y + (x * width);
}

int Board::getIndex(Coord Coordinate)
{
    return getIndex(Coordinate.x, Coordinate.y);
}
