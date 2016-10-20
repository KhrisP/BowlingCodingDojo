#include "game.h"

#ifndef GAMETESTS
#define GAMETESTS

class GameTests : public CxxTest::TestSuite
{
public:

	void setUp()
	{
		_uut = new BowlingGame::Game();
	}
	void tearDown()
	{
		delete _uut;
	}

    void testScoreIs0WithOnlyGutters(void)
    {
    	AddGutters(10);

    	TS_ASSERT_EQUALS(_uut->Score(), 0);
    }

    void testScoreIsTheTotalOfFrameScores()
    {
		_uut->AddFrame(1, 1);
		_uut->AddFrame(2, 2);
		_uut->AddFrame(3, 3);
		AddGutters(7);

    	TS_ASSERT_EQUALS(_uut->Score(), 12);

    }

private:

    void AddGutters(unsigned char number)
    {
    	for(auto roll=0; roll<number; roll++)
    		_uut->AddFrame(0,0);
    }

    BowlingGame::Game *_uut;
};




#endif 
