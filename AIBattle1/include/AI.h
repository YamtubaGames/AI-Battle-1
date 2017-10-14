#ifndef AI_H
#define AI_H

#include <TurnDecision.h>
#include <BoardInfo.h>

class AI
{
    public:
        AI();
        virtual ~AI();

        virtual TurnDecision MakeDecision(BoardInfo BoardState) = 0;

    protected:

    private:
};

#endif // AI_H
