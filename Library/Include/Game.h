/*
 * Game.h
 *
 */

#ifndef GAME
#define GAME


#include "frame.h"
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

	std::vector<Frame> _frames;


};

}




#endif 
