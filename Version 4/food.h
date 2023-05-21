#pragma once
#include <utility>

class Food
{
public:
	Food();
	
	std::pair<int, int> pos;

	void setup();
	void update(std::pair<int, int> snake);
private:


};
