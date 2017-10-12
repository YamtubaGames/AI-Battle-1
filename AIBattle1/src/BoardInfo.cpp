#include "BoardInfo.h"

BoardInfo::BoardInfo(Board &InputBoard) :
UnitMap(InputBoard.UnitMap),
WallMap(InputBoard.WallMap),
height(InputBoard.height),
width(InputBoard.width)
{

}

int BoardInfo::getIndex(int x, int y)
{
    return y + (x * width);
}

int BoardInfo::getIndex(Coord Coordinate)
{
    return getIndex(Coordinate.x, Coordinate.y);
}
