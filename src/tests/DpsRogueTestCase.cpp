#include "pch.h"

#include "aitest.h"
#include "../game/playerbot/strategy/rogue/RogueAiObjectContext.h"

using namespace ai;


class DpsRogueTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( DpsRogueTestCase );
		CPPUNIT_TEST( combatVsMelee );
		CPPUNIT_TEST( healHimself );
		CPPUNIT_TEST( interruptSpells );
    CPPUNIT_TEST_SUITE_END();

public:
    virtual void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new RogueAiObjectContext(ai), "dps", NULL);
        addAura("slice and dice");
        addTargetAura("rupture");
    }

protected:
    void combatVsMelee()
    {
        removeTargetAura("rupture");

		tickOutOfMeleeRange();
		tickInMeleeRange();
		tick();

		tickWithEnergy(70);
        tickWithEnergy(70);

        tickWithComboPoints(5);
        tickWithComboPoints(5);

        tickBehindTarget();

        assertActions(">T:reach melee>T:riposte>T:mutilate>T:sinister strike>T:melee>T:rupture>T:eviscerate>T:backstab");
    }

	void healHimself()
	{
		tickWithLowHealth(39);
		tickWithLowHealth(39);
		tickWithMyAttackerCount(3);

		assertActions(">S:evasion>S:feint>S:vanish");
	}

	void interruptSpells()
	{
        tickInMeleeRange();

		tickWithTargetIsCastingNonMeleeSpell();
		tickWithTargetIsCastingNonMeleeSpell();

		assertActions(">T:riposte>T:kick>T:kidney shot");
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION( DpsRogueTestCase );
