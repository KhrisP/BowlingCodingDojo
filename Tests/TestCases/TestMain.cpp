#include "gmock\gmock.h"

int pppp( int argc, char *argv[] );

int main( int argc, char *argv[] ) {
	testing::GTEST_FLAG(throw_on_failure) = true;
    testing::InitGoogleMock(&argc, argv);
	return pppp( argc,argv );
}

