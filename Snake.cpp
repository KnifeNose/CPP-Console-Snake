#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>

bool gameOver;
int boardWidth = 20;
int boardHeight = 20;
std::vector<int> snakeX, snakeY;
int fruitX, fruitY;
int snakeL;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup()
{
	gameOver = false;
	snakeX.push_back(10);
	snakeY.push_back(10);
	dir = STOP;
	snakeL = 1;
	fruitX = rand() % boardWidth;
	fruitY = rand() % boardHeight;
}

void draw()
{
	system("cls");

	for (int i = 0; i < boardWidth + 2; i++)
	{
		std::cout << '#';
	}
	std::cout << std::endl;

	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j <= boardWidth + 1; j++)
		{
			if (j == 0 || j == boardWidth + 1)
			{
				std::cout << '#';
			}

			
			else if (snakeX[0] == j && snakeY[0] == i)
			{
				std::cout << 'Q';
			}
			else if (fruitX == j && fruitY == i)
			{
				std::cout << 'F';
			}
			else
			{
				bool print = false;

				for (int k = 1; k < snakeL; k++)
				{
					if (snakeX[k] == j && snakeY[k] == i)
					{
						std::cout << 'o';
						print = true;
					}
				}

				if (!print)
				{
					std::cout << ' ';
				}
			}
			

		}
		std::cout << std::endl;
	}

	for (int i = 0; i < boardWidth + 2; i++)
	{
		std::cout << '#';
	}
	Sleep(100);
}

void input()
{
	if (_kbhit())
	{
		char key = _getch();

		if (key == 'w' && dir != DOWN)
		{
			dir = UP;
		}
		if (key == 'd' && dir != LEFT)
		{
			dir = RIGHT;
		}
		if (key == 'a' && dir != RIGHT)
		{
			dir = LEFT;
		}
		if (key == 's' && dir != UP)
		{
			dir = DOWN;
		}
	}
}

void update()
{
	int prevX = snakeX[0];
	int prevY = snakeY[0];
	int prevX2, prevY2;

	if (dir == UP)
	{
		snakeY[0]--;
	}
	else if (dir == DOWN)
	{
		snakeY[0]++;
	}
	else if (dir == RIGHT)
	{
		snakeX[0]++;
	}
	else if (dir == LEFT)
	{
		snakeX[0]--;
	}

	for (int i = 0; i < snakeL; i++)
	{
		if (snakeX[i] == fruitX && snakeY[i] == fruitY)
		{
			fruitX = rand() % boardWidth;
			fruitY = rand() % boardHeight;
			snakeL++;
			snakeX.push_back(snakeX[i]);
			snakeY.push_back(snakeY[i]);
		}
	}
		
	for (int i = 1; i < snakeL; i++)
	{
		prevX2 = snakeX[i];
		prevY2 = snakeY[i];
		snakeX[i] = prevX;
		snakeY[i] = prevY;
		prevX = prevX2;
		prevY = prevY2;

		if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
		{
			gameOver = true;
		}
	}

	if (snakeX[0] == 0 || snakeX[0] == boardWidth + 1 || snakeY[0] == -1 || snakeY[0] == boardHeight)
	{
		gameOver = true;
	}
}

int main()
{
	setup();

	while (!gameOver)
	{
		draw();
		input();
		update();
	}

	Sleep(2000);
	return 0;
}
