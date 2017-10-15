#include "UnitMovement.h"

bool UnitMove(char Index, bool shooting, Coord From, Coord To, bool FromWalled = 0, bool ToWalled = 0)
{
    switch(Index)
    {
        case 0:
            if(shooting)
                return false;
            else if(From - To > 2)
                return false;
            else
            {

            }
            break;
        case 1:
            if(shooting)
                return false;
            else if(From - To > 1)
                return false;
            else
            {

            }
            break;
        case 2:
            if(shooting)
            {

            } else
            {

            }
            break;
        case 3:
            if(shooting)
                return false;
            else if(From - To > 2)
                return false;
            else
            {

            }
            break;
        case 4:
            if(shooting)
                return false;
            else if(From - To > 1)
                return false;
            else
            {

            }
            break;
        case 5:
            if(shooting)
            {

            } else
            {

            }
            break;
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
