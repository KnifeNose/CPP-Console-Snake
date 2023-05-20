#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
//#include <thread> // include the <thread> library

int boardHeigh, boardWidth, fruitX, fruitY;
bool gameOver = false;
std::vector<int> snakeX;
std::vector<int> snakeY;
int snakeL = 1;

enum class direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;


// declare a new function to handle input in a separate thread
//void input_thread()
//{
//	while (true)
//	{
//		char key = _getch(); // read the key without waiting for input
//
//		if (key == 'a' && dir != direction::RIGHT)
//		{
//			dir = direction::LEFT;
//		}
//		if (key == 'd' && dir != direction::LEFT)
//		{
//			dir = direction::RIGHT;
//		}
//		if (key == 'w' && dir != direction::DOWN)
//		{
//			dir = direction::UP;
//		}
//		if (key == 's' && dir != direction::UP)
//		{
//			dir = direction::DOWN;
//		}
//	}
//}

void setup()
{
	dir = direction::STOP;
	boardHeigh = 20;
	boardWidth = 20;
	snakeX.push_back(10);
	snakeY.push_back(10);
	fruitX = rand() % 20;
	fruitY = rand() % 20;
}

void draw()
{
	system("cls");


	for (int i = 0; i < boardWidth + 2; i++)
	{
		std::cout << '#';
	}

	std::cout << std::endl;

	for (int i = 0; i < boardHeigh; i++)
	{
		for (int j = 0; j <= boardWidth; j++)
		{
			if (j == 0 || j == boardWidth)
			{
				std::cout << '#';
			}
			
			if (snakeX[0] == j && snakeY[0] == i)
			{
				std::cout << 'Q';
			}
			else if (fruitX == j && fruitY == i)
			{
				std::cout << 'F';
			}
			else
			{
				bool print = true;

				for (int k = 1; k < snakeL; k++)
				{
					if (snakeX[k] == j && snakeY[k] == i)
					{
						std::cout << 'o';
						print = false;
					}
				}

				if (print) 
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

	Sleep(50);
}

void input()
{
	if (_kbhit())
	{
		char key = _getch();
		if (key == 'a' && dir != direction::RIGHT)
		{
			dir = direction::LEFT;
		}
		if (key == 'd' && dir != direction::LEFT)
		{
			dir = direction::RIGHT;
		}
		if (key == 'w' && dir != direction::DOWN)
		{
			dir = direction::UP;
		}
		if (key == 's' && dir != direction::UP)
		{
			dir = direction::DOWN;
		}
	}
}

void update()
{
	int tempX = snakeX[0];
	int tempY = snakeY[0];
	int tempX2, tempY2;



	switch (dir)
	{
		case direction::UP:
			snakeY[0]--;
			break;
		case direction::DOWN:
			snakeY[0]++;
			break;
		case direction::RIGHT:
			snakeX[0]++;
			break;
		case direction::LEFT:
			snakeX[0]--;
			break;
		default:
			break;
	}

	if (snakeX[0] == fruitX && snakeY[0] == fruitY)
	{
		fruitX = rand() % 20;
		fruitY = rand() % 20;
		snakeX.push_back(1);
		snakeY.push_back(1);
		snakeL++;
	}
	
	for (int i = 1; i < snakeL; i++)
	{
		tempX2 = snakeX[i];
		tempY2 = snakeY[i];
		snakeX[i] = tempX;
		snakeY[i] = tempY;
		tempX = tempX2;
		tempY = tempY2;

		if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
		{
			gameOver = true;
		}
		
	}
	
		if (snakeX[0] > boardWidth - 1 || snakeX[0] < 0 || snakeY[0] < 0 || snakeY[0] > boardWidth - 1)
		{
			gameOver = true;
		}
}

int main()
{
	setup();
	//std::thread inputThread(input_thread);

	while (!gameOver)
	{
		draw();
		input();
		update();
	}
	//inputThread.join();
	Sleep(2000);
	return 0;
}
