#include "Frame.h"

namespace BowlingGame
{

Frame::Frame(unsigned char firstRoll, unsigned char secondRoll):
		_firstRoll(firstRoll),
		_secondRoll(secondRoll)
{

}

Frame::~Frame()
{
	// TODO Auto-generated destructor stub
}


unsigned char Frame::FirstRoll() const
{
	return _firstRoll;
}
unsigned char Frame::SecondRoll() const
{
	return _secondRoll;
}

unsigned char Frame::Score() const
{
	return _firstRoll + _secondRoll;
}

bool Frame::IsSpare() const
{
	return Score() == 10 && !IsStrike();
}

bool Frame::IsStrike() const
{
	return _firstRoll == 10;
}

}
