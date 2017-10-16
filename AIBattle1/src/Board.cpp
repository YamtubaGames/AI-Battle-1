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
    if(!InBounds(To))
        return false;

    bool valid = UnitMove(UnitMap[getIndex(From)], isShooting, From, To);

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
    if(!InBounds(InputMove.To))
        return false;

    int unitTeam = getTeam(UnitMap[getIndex(InputMove.From)]);

    if(unitTeam < 0)
        return false;
    if(unitTeam != team)
        return false;

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

bool Board::UnitMove(char Index, bool shooting, Coord From, Coord To)
{
    char middle = UnitMap[getIndex((From.x + To.x) /2, (From.y + To.y) / 2)];
    char theEnd = UnitMap[getIndex(To)];
    bool onWall = WallMap[getIndex(From)];
    bool endWall = WallMap[getIndex(To)];
    switch(Index)
    {
        case 1:
			if(shooting)
				return false;
            else if(From - To > 2)
                return false;
            else if((middle == 6) || (middle == 4) || (middle == 5))
                return false;
            else if((theEnd == 3) || (theEnd == 2))
                return false;
            /*
            else if(attacking a wall){
            }
            */
            else
                return true;
            break;
        case 2:
            if(shooting)
                return false;
            else if(From - To > 1)
                return false;
            else if((theEnd == 3) || (theEnd == 1) || (theEnd == 2))
                return false;
            /*
            else if(attacking a wall){
            }
            */
            else
                return true;
            break;
        case 3:
            if(shooting)
            {
                if(UnitMap[getIndex(To)] == 0)
                    return false;
                if(onWall)
                {
                    if((From - To) > 2)
                        return false;
                    else if(endWall && ((From - To) == 2))
                        return false;
                    else if((theEnd == 3) || (theEnd == 1) || (theEnd == 2))
                        return false;
                    else
                        return true;
                } else
                {
                    if((From - To) > 1)
                        return false;
                    else if((theEnd == 3) || (theEnd == 1) || (theEnd == 2))
                        return false;
                    else
                        return true;
                }
            } else
            {
                if(From - To > 1)
                    return false;
                else if(theEnd != 0)
                    return false;
                else
                    return true;
            }
            break;
        case 4:
            if(shooting)
				return false;
            else if(From - To > 2)
                return false;
            else if((middle == 1) || (middle == 2) || (middle == 3))
                return false;
            else if((theEnd == 5) || (theEnd == 6))
                return false;
            /*
            else if(attacking a wall){
            }
            */
            else
                return true;
            break;
        case 5:
           if(shooting)
                return false;
            else if(From - To > 1)
                return false;
            else if((theEnd == 4) || (theEnd == 5) || (theEnd == 6))
                return false;
            /*
            else if(attacking a wall){
            }
            */
            else
                return true;
            break;
        case 6:
            if(shooting)
            {
                if(UnitMap[getIndex(To)] == 0)
                    return false;
                if(onWall)
                {
                    if((From - To) > 2)
                        return false;
                    else if(endWall && ((From - To) == 2))
                        return false;
                    else if((theEnd == 4) || (theEnd == 5) || (theEnd == 6))
                        return false;
                    else
                        return true;
                } else
                {
                    if((From - To) > 1)
                        return false;
                    else if((theEnd == 4) || (theEnd == 5) || (theEnd == 6))
                        return false;
                    else
                        return true;
                }
            } else
            {
                if(From - To > 1)
                    return false;
                else if(theEnd != 0)
                    return false;
                else
                    return true;
            }
            break;
        default:
            return false;
    }
}

int Board::getTeam(char Index)
{
    if(Index == 0)
        return -1;
    if(Index <= 3)
        return 0;
    if(Index <= 6)
        return 1;
    return -2;
}
