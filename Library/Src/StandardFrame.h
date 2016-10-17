#ifndef STANDARDFRAME
#define STANDARDFRAME

namespace BowlingGame
{

class StandardFrame
{
public:
	StandardFrame(unsigned char firstRoll, unsigned char secondRoll);
	~StandardFrame();

	unsigned char GetFirstRoll() const;
	unsigned char GetSecondRoll() const;

private:
	unsigned char _firstRoll;
	unsigned char _secondRoll;

};

}

#endif 
