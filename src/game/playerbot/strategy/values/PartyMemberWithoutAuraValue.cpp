#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PartyMemberWithoutAuraValue.h"

using namespace ai;

class PlayerWithoutAuraPredicate : public FindPlayerPredicate, public PlayerbotAIAware
{
public:
    PlayerWithoutAuraPredicate(PlayerbotAI* ai, string aura) : 
        PlayerbotAIAware(ai), FindPlayerPredicate(), aura(aura) {}

public:
    virtual bool Check(Unit* unit)
    {
        return unit->isAlive() && !ai->HasAura(aura, unit);
    }

private:
    string aura;
};

Unit* PartyMemberWithoutAuraValue::Calculate()
{
	PlayerWithoutAuraPredicate predicate(ai, qualifier);
    return FindPartyMember(predicate);
}