#include "ManualPlayer.h"

using namespace std;

ManualPlayer::ManualPlayer(bool Affiliation) :
Affiliation(Affiliation)
{
    //ctor
}

ManualPlayer::~ManualPlayer()
{
    //dtor
}

TurnDecision ManualPlayer::MakeDecision(BoardInfo BoardState)
{
    cout << "Format: wall? shoot? fromX fromY toX toY" << endl;

    if(Affiliation)
        cout << "2";
    else
        cout << "1";
    cout << "> ";

    int fromX, fromY, toX, toY;
    TurnDecision returner;

    cin >> returner.buildWall >> returner.shoot >> fromX >> fromY >> toX >> toY;

    returner.From.x = fromX;
    returner.From.y = fromY;
    returner.To.x = toX;
    returner.To.y = toY;
    return returner;
}
