#pragma once
#include "Action.h"
#include "Multiplier.h"
#include "Trigger.h"
#include "PassTroughStrategy.h"

namespace ai
{
    class DuelStrategy : public PassTroughStrategy
    {
    public:
        DuelStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "duel"; }
    };
}