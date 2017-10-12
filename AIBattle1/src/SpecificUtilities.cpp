#include "SpecificUtilities.h"

void Fill5x5Map(Board &MapBoard)
{
    char* UnitMap = MapBoard.UnitMap;

    for(int x = 0; x < 5; ++x)
        UnitMap[MapBoard.getIndex(x, 0)] = 3;
    UnitMap[MapBoard.getIndex(2, 0)] = 1;
    for(int x = 0; x < 5; ++x)
        UnitMap[MapBoard.getIndex(x, 1)] = 2;

    for(int x = 0; x < 5; ++x)
        UnitMap[MapBoard.getIndex(x, 4)] = 3;
    UnitMap[MapBoard.getIndex(2, 4)] = 1;
    for(int x = 0; x < 5; ++x)
        UnitMap[MapBoard.getIndex(x, 3)] = 2;
}
