#ifndef AI_H
#define AI_H

#include <TurnDecision.h>

class AI
{
    public:
        AI();
        virtual ~AI();

        virtual TurnDecision MakeDecision() = 0;

    protected:

    private:
};

#endif // AI_H
