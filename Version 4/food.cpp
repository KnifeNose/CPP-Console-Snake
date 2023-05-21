#include "Food.h"
#include <random>

Food::Food()

{
	pos.first = 0;
	pos.second = 0;
}

void Food::setup()
{
	pos.first = rand() % 20;
	pos.second = rand() % 20;
}

void Food::update(std::pair<int, int> snake)
{
	if ((snake.first == this->pos.first) && (snake.second == this->pos.second))
	{
		pos.first = rand() % 20;
		pos.second = rand() % 20;
	}
}
