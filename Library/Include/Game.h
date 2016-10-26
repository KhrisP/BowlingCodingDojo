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
	Game();
	~Game();

	unsigned char Score() const;
	void AddFrame(unsigned char firstRoll, unsigned char secondRoll);

private:

	unsigned char GetBonusForSpare(std::size_t index) const;
	unsigned char GetBonusForStrike(std::size_t index) const;

	std::vector<Frame> _frames;


};

}




#endif 
