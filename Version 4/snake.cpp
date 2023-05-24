#include "Snake.h"

Snake::Snake()
	:length(1), endGame(false)
{
	std::pair<int, int> speed = { 0 , 0 };
	std::pair<int, int> startpos = { 0 , 0 };
	pos.push_back(startpos);
}

void Snake::setup()
{
	// Starting position
	pos[0].first = 10;
	pos[0].second = 10;
}

void Snake::update()
{
	// Make the tail follow the head of the snake
	int tempX = pos[0].first;
	int tempY = pos[0].second;
	int tempX2, tempY2;
	
	pos[0].first += speed.first;
	pos[0].second += speed.second;

	for (int i = 1; i < this->length; i++)
	{
		tempX2 = pos[i].first;
		tempY2 = pos[i].second;
		pos[i].first = tempX;
		pos[i].second = tempY;
		tempX = tempX2;
		tempY = tempY2;
	}
	
	// End game if the snakes head hits the tail
	for (int i = 1; i < this->length; i++)
	{
		if ((pos[0].first == pos[i].first) && (pos[0].second == pos[i].second))
		{
			endGame = true;
		}
	}
	
	// End game if the snakes head hits the edge of the board 
	if ((this->pos[0].first <= 0) || (this->pos[0].first >= 20))
	{
		this->endGame = true;
	}

	if ((this->pos[0].second < 0) || (this->pos[0].second > 20))
	{
		this->endGame = true;
	}
}
