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
		if(_frames[index].IsSpare())
		{
			score += GetBonusForSpare(index);
		}

	}
	return score;
}

void Game::AddFrame(unsigned char firstRoll, unsigned char secondRoll)
{
	_frames.push_back(Frame(firstRoll, secondRoll));
}

unsigned char Game::GetBonusForSpare(std::size_t index) const
{
	bool nextFrameAvailable = index < _frames.size();

	return nextFrameAvailable ? _frames[index + 1].FirstRoll() : 0;
}

}




