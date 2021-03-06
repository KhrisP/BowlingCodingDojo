#include "game.h"

#include "frame.h"

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
    	AddGutters(BowlingGame::Game::MAX_FRAMES);

    	TS_ASSERT_EQUALS(_uut->Score(), 0);
    }

    void testScoreIsTheTotalOfFrameScores()
    {
		_uut->AddFrame(1, 1);
		_uut->AddFrame(2, 2);
		_uut->AddFrame(3, 3);
		AddGutters(BowlingGame::Game::MAX_FRAMES - 3);

    	TS_ASSERT_EQUALS(_uut->Score(), 12);

    }

    void testBonusForSpareIsTheNextRoll()
    {
    	AddSpare(4);
    	AddFrame(2, 4);
    	AddGutters(BowlingGame::Game::MAX_FRAMES - 2);

    	TS_ASSERT_EQUALS(_uut->Score(), 18);

    }

    void testBonusForStrikeIsTheNext2Rolls()
    {
    	AddStrikes(1);
    	AddFrame(2, 4);
    	AddGutters(BowlingGame::Game::MAX_FRAMES - 2);

    	TS_ASSERT_EQUALS(_uut->Score(), 22);

    }

    void testSpareAsLastFrame()
    {
    	AddGutters(BowlingGame::Game::MAX_FRAMES - 1);
    	AddSpareAsLastFrame(4,8);

    	TS_ASSERT_EQUALS(_uut->Score(), 26);

    }

    void testStrikeAsLastFrame()
    {
    	AddGutters(BowlingGame::Game::MAX_FRAMES - 1);
    	AddStrikeAsLastFrame(8);

    	TS_ASSERT_EQUALS(_uut->Score(), 26);

    }

    void testMaximumScoreIs300()
    {
    	AddStrikes(BowlingGame::Game::MAX_FRAMES - 1);
    	AddStrikeAsLastFrame(10);

    	TS_ASSERT_EQUALS(_uut->Score(), 300);

    }

private:

    void AddGutters(unsigned char number)
    {
    	for(auto roll=0; roll<number; roll++)
    		_uut->AddFrame(0,0);
    }

    void AddStrikes(unsigned char number)
    {
    	for(auto roll=0; roll<number; roll++)
    		_uut->AddFrame(BowlingGame::Frame::MAX_PINS, 0);
    }

    void AddSpare(unsigned char firstRoll)
    {
   		_uut->AddFrame(firstRoll, BowlingGame::Frame::MAX_PINS - firstRoll);
    }
    void AddSpareAsLastFrame(unsigned char firstRoll, unsigned char extraBallScore)
    {
   		_uut->AddSpareAsLastFrame(firstRoll, extraBallScore);
    }

    void AddStrikeAsLastFrame(unsigned char extraBallScore)
    {
   		_uut->AddStrikeAsLastFrame(extraBallScore);
    }


    void AddFrame(unsigned char first, unsigned char second)
    {
 		_uut->AddFrame(first,second);
    }

    BowlingGame::Game *_uut;
};




#endif 
