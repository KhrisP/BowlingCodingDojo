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

    void testBonusForSpareIsTheNextRoll()
    {
    	AddSpare(4);
    	AddFrame(2, 4);
    	AddGutters(8);

    	TS_ASSERT_EQUALS(_uut->Score(), 18);

    }
    void testBonusForStrikeIsTheNext2Rolls()
    {
    	AddStrike();
    	AddFrame(2, 4);
    	AddGutters(8);

    	TS_ASSERT_EQUALS(_uut->Score(), 22);

    }
    void testSpareAsLastFrame()
    {
    	AddGutters(9);
    	AddSpareAsLastFrame(4,8);

    	TS_ASSERT_EQUALS(_uut->Score(), 26);

    }

private:

    void AddGutters(unsigned char number)
    {
    	for(auto roll=0; roll<number; roll++)
    		_uut->AddFrame(0,0);
    }

    void AddSpare(unsigned char firstRoll)
    {
   		_uut->AddFrame(firstRoll, 10 - firstRoll);
    }
    void AddSpareAsLastFrame(unsigned char firstRoll, unsigned char extraBallScore)
    {
   		_uut->AddSpareAsLastFrame(firstRoll, extraBallScore);
    }

    void AddStrike()
    {
   		_uut->AddFrame(10, 0);
    }

    void AddFrame(unsigned char first, unsigned char second)
    {
 		_uut->AddFrame(first,second);
    }

    BowlingGame::Game *_uut;
};




#endif 
