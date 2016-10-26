#include "Frame.h"

#include<cassert>

namespace BowlingGame
{

const unsigned char Frame::MAX_PINS = 10;

Frame::Frame(unsigned char firstRoll, unsigned char secondRoll):
		_firstRoll(firstRoll),
		_secondRoll(secondRoll)
{
	assert(_firstRoll + _secondRoll <= MAX_PINS);
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
	return Score() == MAX_PINS && !IsStrike();
}

bool Frame::IsStrike() const
{
	return _firstRoll == MAX_PINS;
}

}
