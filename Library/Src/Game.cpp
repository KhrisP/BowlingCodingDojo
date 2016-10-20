#include "Game.h"

namespace BowlingGame
{

Game::Game()
{

}

Game::~Game()
{
	// TODO Auto-generated destructor stub
}

unsigned char Game::Score() const
{
	unsigned char score = 0;

	for(Frame const &frame : _frames)
	{
		score += frame.Score();
	}
	return score;
}

void Game::AddFrame(unsigned char firstRoll, unsigned char secondRoll)
{
	_frames.push_back(Frame(firstRoll, secondRoll));
}


}




