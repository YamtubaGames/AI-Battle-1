#ifndef MANUALPLAYER_H
#define MANUALPLAYER_H

#include <AI.h>
#include <iostream>

class ManualPlayer : public AI
{
    public:
        ManualPlayer(bool Affiliation);
        virtual ~ManualPlayer();
        TurnDecision MakeDecision(BoardInfo BoardState);

        bool Affiliation;

    protected:

    private:
};

#endif // MANUALPLAYER_H
