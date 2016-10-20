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

	for(auto index = 0; index < _frames.size(); index++)
	{
		score += _frames[index].Score();
		if(_frames[index].IsSpare() && index < _frames.size() - 1)
		{
			score += _frames[index + 1].FirstRoll();
		}

	}
	return score;
}

void Game::AddFrame(unsigned char firstRoll, unsigned char secondRoll)
{
	_frames.push_back(Frame(firstRoll, secondRoll));
}


}




