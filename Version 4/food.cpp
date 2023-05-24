#include "Food.h"
#include <random>

Food::Food()
{
	pos.first = 0;
	pos.second = 0;
}

void Food::setup()
{
	// Random starting position 
	pos.first = rand() % 20;
	pos.second = rand() % 20;
}

void Food::update(std::pair<int, int> snake)
{
	// If position is randomly selected where snake is.
	// Select another random positon
	if ((snake.first == this->pos.first) && (snake.second == this->pos.second))
	{
		pos.first = rand() % 20;
		pos.second = rand() % 20;
	}
}
