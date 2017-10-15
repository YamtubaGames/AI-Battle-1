#include "BoardInfo.h"

BoardInfo::BoardInfo(Board &InputBoard) :
//UnitMap(InputBoard.UnitMap),
//WallMap(InputBoard.WallMap),
height(InputBoard.height),
width(InputBoard.width)
{
    int mapSize = height*width;

    // Deep copy, prevents easy cheating

    UnitMap = new char[mapSize];
    std::memcpy(UnitMap, InputBoard.UnitMap, mapSize * sizeof(char));

    WallMap = new bool[mapSize];
    std::memcpy(WallMap, InputBoard.WallMap, mapSize * sizeof(bool));
}

int BoardInfo::getIndex(int x, int y)
{
    return y + (x * width);
}

int BoardInfo::getIndex(Coord Coordinate)
{
    return getIndex(Coordinate.x, Coordinate.y);
}
