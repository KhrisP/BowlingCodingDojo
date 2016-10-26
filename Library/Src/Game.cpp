#include "Game.h"

#include <cassert>

namespace BowlingGame
{

const unsigned char Game::MAX_FRAMES = 10;

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
	assert(_frames.size() < MAX_FRAMES);

	_frames.push_back(Frame(firstRoll, secondRoll));
}

void Game::AddSpareAsLastFrame(unsigned char firstRoll, unsigned char extraBallScore)
{
	assert(_frames.size() == MAX_FRAMES - 1);

	_frames.push_back(Frame(firstRoll, Frame::MAX_PINS - firstRoll));
	_frames.push_back(Frame(extraBallScore, 0));
}

void Game::AddStrikeAsLastFrame(unsigned char extraBallScore)
{
	assert(_frames.size() == MAX_FRAMES - 1);

	_frames.push_back(Frame(Frame::MAX_PINS, 0));
	_frames.push_back(Frame(extraBallScore, 0));
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




