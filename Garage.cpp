#include "Garage.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;



void Garage::display()
{
	/*
	The different color codes are

	0   BLACK
	1   BLUE
	2   GREEN
	3   CYAN
	4   RED
	5   MAGENTA
	6   BROWN
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW
	15  WHITE
	*/

	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPosition;
	dwPosition.X = 0;
	dwPosition.Y = 0;
	spaces();
	for (int i = 0; i < garageSpaces.size(); i++)
	{
		if (garageSpaces[i] % 9 == 0)
		{
			dwPosition.X = 0;
			dwPosition.Y += 8;
		}
			if (fillup() == true)
			{
				SetConsoleTextAttribute(H, FOREGROUND_RED | FOREGROUND_INTENSITY);// if space is taken then space turns red
				SetConsoleCursorPosition(H, dwPosition);
				for (int i = 0; i < 5; i++)
				{
					SetConsoleCursorPosition(H, dwPosition);
					cout << "|";
					dwPosition.Y += 1;
				}

				cout << " Space: " << garageSpaces[i];
				dwPosition.X = dwPosition.X + 11;
				dwPosition.Y -= 5;
				SetConsoleCursorPosition(H, dwPosition);
				for (int i = 0; i < 5; i++)
				{
					SetConsoleCursorPosition(H, dwPosition);
					cout << "|";
					dwPosition.Y += 1;
				}

				dwPosition.Y -= 5;
				Sleep(200);

			}
			else
			{
				SetConsoleTextAttribute(H, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// if space is open then space turns green
				SetConsoleCursorPosition(H, dwPosition);
				for (int i = 0; i < 5; i++)
				{
					SetConsoleCursorPosition(H, dwPosition);
					cout << "|";
					dwPosition.Y += 1;
				}

				cout << " Space: " << garageSpaces[i];
				dwPosition.X = dwPosition.X + 11;
				dwPosition.Y -= 5;
				SetConsoleCursorPosition(H, dwPosition);
				for (int i = 0; i < 5; i++)
				{
					SetConsoleCursorPosition(H, dwPosition);
					cout << "|";
					dwPosition.Y += 1;
				}
				dwPosition.Y -= 5;
				Sleep(200);
			}
			dwPosition.X += 2;
		}
	
		cout << "\n\n\n";
		SetConsoleTextAttribute(H, 15 | FOREGROUND_INTENSITY);// set the color back to normal white
		cout << "\n\nNumber of open spaces : ";
		SetConsoleTextAttribute(H, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << numofOpenSpaces() << "\n";
		SetConsoleTextAttribute(H, 15 | FOREGROUND_INTENSITY);// set the color back to normal white
		cout << "Number of taken spaces: ";
		SetConsoleTextAttribute(H, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << numofTakenSpaces() << "\n";
		SetConsoleTextAttribute(H, 15 | FOREGROUND_INTENSITY);// set the color back to normal white
	
}

void Garage::display2()// testing purposes
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPosition;
	dwPosition.X = 0;
	dwPosition.Y = 0;
	int x = 0;

	for (int i = 0; i < 50; i++)
	{
		SetConsoleCursorPosition(h, dwPosition);
		cout << x;
		x += 1;
		dwPosition.X += 5;
		dwPosition.Y += 5;
	}
}

void Garage::spaces()
{
	for (int i = 1; i < 100; i++)
	{
		garageSpaces.push_back(i);
	}
}

bool Garage::fillup()
{
	
	int randNumber = rand() % 3;

		for (int i = 0; i < garageSpaces.size(); i++)
		{
			if ( garageSpaces[i] == randNumber)
			{
				bs.push_back(true);
				return true;
			}
			else
			{
				bs.push_back(false);
				return false;
			}
		}
	
}
int Garage::numofOpenSpaces()
{
	open = 0;
	for (int i = 0; i < bs.size(); i++)
	{
		if (bs[i] == false)
		{
			open += 1;
		}
	}
	return open;
}

int Garage::numofTakenSpaces()
{
	taken = 0;
	for (int i = 0; i < bs.size(); i++)
	{
		if (bs[i] == true)
		{
			taken += 1;
		}
	}
	return taken;
}

