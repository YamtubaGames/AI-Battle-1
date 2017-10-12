#include <iostream>

#include <Display.h>
#include <Board.h>
#include <SpecificUtilities.h>

using namespace std;

int main()
{
    Board GameBoard (5, 5);
    Fill5x5Map(GameBoard);

    Draw(GameBoard);

    while(true)
    {

    }

    return 0;
}
