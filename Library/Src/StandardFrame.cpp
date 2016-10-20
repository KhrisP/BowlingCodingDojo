#include "StandardFrame.h"

namespace BowlingGame
{

StandardFrame::StandardFrame(unsigned char firstRoll, unsigned char secondRoll):
		_firstRoll(firstRoll),
		_secondRoll(secondRoll)
{

}

StandardFrame::~StandardFrame()
{
	// TODO Auto-generated destructor stub
}


unsigned char StandardFrame::GetFirstRoll() const
{
	return _firstRoll;
}
unsigned char StandardFrame::GetSecondRoll() const
{
	return _secondRoll;
}

unsigned char StandardFrame::GetScore() const
{
	return _firstRoll + _secondRoll;
}

bool StandardFrame::IsSpare() const
{
	return GetScore() == 10;
}

}
