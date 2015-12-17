#ifndef TESTS_DEMOTEST_T_H_
#define TESTS_DEMOTEST_T_H_

#include <cxxtest/TestSuite.h>

class DemoTest : public CxxTest::TestSuite
{
public:
    void testDemo(void)
    {
        TS_ASSERT(1 + 1 > 1);
        TS_ASSERT_EQUALS(1 + 1, 2);
    }
};
#endif
