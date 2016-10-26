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
		if(_frames[index].IsStrike())
		{
			score += GetBonusForStrike(index);
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

unsigned char Game::GetBonusForStrike(std::size_t index) const
{
	bool isNotTheLastFrame = index < _frames.size();
	bool isBeforeTheSecondToLastFrame = index < _frames.size() - 1;
	unsigned char bonus = 0;

	if(isNotTheLastFrame)
	{
		bonus = _frames[index + 1].Score();
		if(_frames[index + 1].IsStrike() && isBeforeTheSecondToLastFrame)
		{
			bonus += _frames[index + 2].FirstRoll();
		}
	}
	return bonus;
}

}




