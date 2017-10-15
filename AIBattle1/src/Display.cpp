#include "Display.h"

using namespace std;

void Draw(Board &DrawBoard)
{
    // TODO: Switch to printf from cout for extra print speed

    //stringstream buffer;

    for(int y = 0; y < DrawBoard.height; ++y)
    {
        for(int x = 0; x < DrawBoard.width; ++x)
        {
            cout << getUnitDisplay(DrawBoard.UnitMap[DrawBoard.getIndex(x, y)], DrawBoard.WallMap[DrawBoard.getIndex(x, y)]);
        }
        cout << endl;
    }

    //cout << buffer;
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
