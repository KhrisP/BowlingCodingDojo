#ifndef STANDARDFRAMETEST
#define STANDARDFRAMETEST

#include <cxxtest/TestSuite.h>

#include "../../Library/Include/Frame.h"

class StandardFrameTests : public CxxTest::TestSuite
{
public:
    void testRollsAreOrdered(void)
    {
    	BowlingGame::Frame Frame(4,3);

        TS_ASSERT_EQUALS(Frame.FirstRoll(), 4);
        TS_ASSERT_EQUALS(Frame.SecondRoll(), 3);
    }

    void testScoreIsTheRollAddition(void)
    {
    	BowlingGame::Frame Frame(1,5);

        TS_ASSERT_EQUALS(Frame.Score(), 6);
    }

    void testSpareIs10PinsDownIn2Rolls()
    {
    	BowlingGame::Frame Frame(6,4);

        TS_ASSERT_EQUALS(Frame.IsSpare(), true);
    }
    void testFrameWithLessThan10PinsDownIsNotSpare()
    {
    	BowlingGame::Frame Frame(5,4);

        TS_ASSERT_EQUALS(Frame.IsSpare(), false);

    }
    void testStrikeIs10PinsDownAtTheFirstRoll()
    {
    	BowlingGame::Frame Frame(10,0);

        TS_ASSERT_EQUALS(Frame.IsStrike(), true);
        TS_ASSERT_EQUALS(Frame.IsSpare(), false);
    }
    void testFrameWithout10PinsDownAtFirstRollIsNotStrike()
    {
    	BowlingGame::Frame Frame(5,5);

        TS_ASSERT_EQUALS(Frame.IsStrike(), false);

    }
};




#endif 
