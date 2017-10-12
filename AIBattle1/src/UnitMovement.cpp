#include "UnitMovement.h"

bool UnitMove(char Index, bool shooting, Coord From, Coord To, bool FromWalled, bool ToWalled)
{
    switch(Index)
    {
        default:
            return false;
    }
}

char getUnitDisplay(char Index, bool Walled)
{
    //if(Index >= UnitCharacters)
    if(!Walled)
    {
        return UnitCharacters[(int)Index];
    } else
    {
        return toupper(UnitCharacters[(int)Index]);
    }
}
