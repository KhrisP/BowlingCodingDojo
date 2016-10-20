#ifndef STANDARDFRAMETEST
#define STANDARDFRAMETEST

#include <cxxtest/TestSuite.h>
#include "..\..\library\src\StandardFrame.h"

class StandardFrameTests : public CxxTest::TestSuite
{
public:
    void testRollsAreOrdered(void)
    {
    	BowlingGame::StandardFrame Frame(4,3);

        TS_ASSERT_EQUALS(Frame.GetFirstRoll(), 4);
        TS_ASSERT_EQUALS(Frame.GetSecondRoll(), 3);
    }

    void testScoreIsTheRollAddition(void)
    {
    	BowlingGame::StandardFrame Frame(1,5);

        TS_ASSERT_EQUALS(Frame.GetScore(), 6);
    }

    void testSpareIs10PinsDownIn2Rolls()
    {
    	BowlingGame::StandardFrame Frame(6,4);

        TS_ASSERT_EQUALS(Frame.IsSpare(), true);
    }
    void testFrameWithLessThan10PinsDownIsNotSpare()
    {
    	BowlingGame::StandardFrame Frame(5,4);

        TS_ASSERT_EQUALS(Frame.IsSpare(), false);

    }
};




#endif 
