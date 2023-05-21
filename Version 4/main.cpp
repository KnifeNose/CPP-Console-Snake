#include "Snake.h"
#include "food.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

const int width = 20;
const int height = 20;

bool gameOver = false;



Food food;
Snake snake;

void setup()
{
	food.setup();

	snake.setup();
}

void draw()
{
	system("cls");

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << '#';
	}

	std::cout << std::endl;

	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			bool print = true;

			if ((j == 0) || (j == width))
			{
				std::cout << "#";
			}
			else if ((snake.pos[0].first == j) && (snake.pos[0].second == i))
			{
				std::cout << 'Q';
				print = false;
			}
			else if ((food.pos.first == j) && (food.pos.second == i))
			{
				std::cout << 'F';
				print = false;
			}
			else
			{
				for (int k = 1; k < snake.length; k++)
				{
					if ((snake.pos[k].first == j) && (snake.pos[k].second == i))
					{
						std::cout << 'o';
						print = false;
					}
				}
			}

			if (print)
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << '#';
	}

	Sleep(100);
}

void input()
{
	if (_kbhit())
	{
		int key = _getch();

		if ((key == 'w') && (snake.speed.second != 1))
		{
			snake.speed = { 0,-1 };
		}
		if ((key == 's') && (snake.speed.second != -1))
		{
			snake.speed = { 0,1 };
		}
		if ((key == 'd') && (snake.speed.first != -1))
		{
			snake.speed = { 1,0 };
		}
		if ((key == 'a') && (snake.speed.first != 1))
		{
			snake.speed = { -1,0 };
		}
	}
}

void update()
{
	snake.update();

	if ((snake.pos[0].first == food.pos.first) && (snake.pos[0].second == food.pos.second))
	{
		food.setup();
		snake.length++;
		snake.pos.push_back(snake.pos[0]);
	}

	if (snake.endGame == true)
	{
		gameOver = true;
	}
}

int main()
{
	setup();
	while (!gameOver)
	{
		input();
		update();
		draw();
	}
}
