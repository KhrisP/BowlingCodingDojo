/*
 * Game.h
 *
 */

#ifndef GAME
#define GAME

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

};

}




#endif 
