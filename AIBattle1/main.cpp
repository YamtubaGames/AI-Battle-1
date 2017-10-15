#include <iostream>

#include <Display.h>
#include <Board.h>
#include <SpecificUtilities.h>
#include <AI.h>
#include <ManualPlayer.h>
#include <TurnDecision.h>
#include <BoardInfo.h>

using namespace std;

int main()
{
    AI* Player1 = new ManualPlayer(0);
    AI* Player2 = new ManualPlayer(1);

    Board GameBoard (5, 5);
    Fill5x5Map(GameBoard);

    bool turn = 0;

    while(true)
    {
        TurnDecision playerMove;
        BoardInfo BoardState (GameBoard);

        Draw(GameBoard);

        while(true)
        {
            if(!turn)
                playerMove = Player1->MakeDecision(BoardState);
            else
                playerMove = Player2->MakeDecision(BoardState);
            if(GameBoard.Exec(playerMove, turn))
                break;
            cout << "Invalid move made!" << endl;
        }
        turn ^= 1;
    }

    return 0;
}
