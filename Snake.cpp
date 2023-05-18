#include <iostream>
#include <conio.h>
#include <Windows.h>

int width = 20;
int height = 20;
int snakeX, snakeY, fruitX, fruitY;

bool gameOver;


enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

int tailX[100], tailY[100];
int tailN;



void setup()
{
	gameOver = false;
	dir = STOP;
	snakeX = 10;
	snakeY = 10;
	fruitX = rand() % width;
	fruitY = rand() % height;
}

void draw()
{
	system("cls");

	for (int i = 0; i < width + 1; i++)
	{
		std::cout << '#';
	}
	std::cout << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				std::cout << '#';
			}
			
			if (snakeX == j && snakeY == i)
			{
				std::cout << 'O';
			}
			else if (fruitX == j && fruitY == i)
			{
				std::cout << 'F';
			}
			else
			{
				bool print = false;
				
				for (int k = 0; k < tailN; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
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

	for (int i = 0; i < width + 1; i++)
	{
		std::cout << '#';
	}
	Sleep(50);
}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void update()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prevX2, prevY2;

	tailX[0] = snakeX;
	tailY[0] = snakeY;

	for (int i = 1; i < tailN; i++)
	{
		prevX2 = tailX[i];
		prevY2 = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prevX2;
		prevY = prevY2;
	}

	switch (dir)
	{
		case LEFT:
			snakeX--;
			break;
		case RIGHT:
			snakeX++;
			break;
		case DOWN:
			snakeY++;
			break;
		case UP:
			snakeY--;
			break;
		default:
			break;
	}

	if (snakeX > width - 2 || snakeX < 0 || snakeY < 0 || snakeY > height - 1)
	{
		gameOver = true;
	}

	for (int i = 0; i < tailN; i++) {
		if (tailX[i] == snakeX && tailY[i] == snakeY)
		{
			gameOver = true;
		}
	}

	if (snakeX == fruitX && snakeY == fruitY)
	{
		fruitX = rand() % width;
		fruitY = rand() % height;
		tailN++;
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
