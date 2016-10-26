/*
 * Game.h
 *
 */

#ifndef GAME
#define GAME


#include "frame.h"
#include <cstddef>
#include <vector>

namespace BowlingGame
{

class Game
{
public:

	static const unsigned char MAX_FRAMES;

	Game();
	~Game();

	unsigned char Score() const;
	void AddFrame(unsigned char firstRoll, unsigned char secondRoll);
	void AddSpareAsLastFrame(unsigned char firstRoll, unsigned char extraBallScore);

private:

	unsigned char GetBonusForSpare(std::size_t index) const;
	unsigned char GetBonusForStrike(std::size_t index) const;

	std::vector<Frame> _frames;


};

}




#endif 
