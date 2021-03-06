#include "pch.h"

#include "aitest.h"
#include "../game/playerbot/strategy/priest/PriestAiObjectContext.h"

using namespace ai;


class HolyPriestTestCase : public EngineTestBase
{
    CPPUNIT_TEST_SUITE( HolyPriestTestCase );
    CPPUNIT_TEST( combat );
	CPPUNIT_TEST( incompatibles );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
		EngineTestBase::setUp();
		setupEngine(new PriestAiObjectContext(ai), "holy", NULL);

        addAura("power word: fortitude");
        addAura("divine spirit");
        addAura("inner fire");
        addPartyAura("power word: fortitude");
        addPartyAura("divine spirit");
    }

protected:
    void combat()
    {
		tick();
		tick();
		tick();

		assertActions(">T:holy fire>T:smite>T:shoot");
    }

    void incompatibles()
    {
        engine->addStrategies("shadow", "holy", NULL);

        CPPUNIT_ASSERT_EQUAL(engine->ListStrategies(), string("Strategies: holy"));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( HolyPriestTestCase );
