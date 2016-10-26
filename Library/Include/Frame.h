#ifndef STANDARDFRAME
#define STANDARDFRAME

namespace BowlingGame
{

class Frame
{
public:
	Frame(unsigned char firstRoll, unsigned char secondRoll);
	~Frame();

	unsigned char FirstRoll() const;
	unsigned char SecondRoll() const;
	unsigned char Score() const;

	bool IsSpare() const;
	bool IsStrike() const;

private:
	unsigned char _firstRoll;
	unsigned char _secondRoll;

};

}

#endif 
