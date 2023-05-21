#pragma once
#include <vector>

class Snake
{


public:

	bool endGame;
	int length;
	std::pair<int, int> speed;
	std::vector<std::pair<int, int>> pos;
	Snake();
	void update();
	void setup();
};

