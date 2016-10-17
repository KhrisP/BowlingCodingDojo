#ifndef STANDARDFRAMETEST
#define STANDARDFRAMETEST

#include <cxxtest/TestSuite.h>
#include "..\..\library\src\StandardFrame.h"

class StandardFrameTests : public CxxTest::TestSuite
{
public:
    void testRollAreOrdered(void)
    {
    	BowlingGame::StandardFrame Frame(4,8);
        TS_ASSERT_EQUALS(Frame.GetFirstRoll(), 4);
        TS_ASSERT_EQUALS(Frame.GetSecondRoll(), 8);
    }
};




#endif 
