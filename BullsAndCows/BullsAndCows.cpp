#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "BullsAndCows.h"

int main()
{
	setlocale(0, "");
	srand(time(0));
	std::vector<int> board =  PrepareGame();
	int step = 0;
	bool endGame = false;
	while (!endGame)
	{
		step++;
		std::vector<int> input = ReadInput(step);
		endGame = Check(board, input);
	}
	std::cout << "\nВы победили за " << step << " шагов!";
}

std::vector<int> PrepareGame()
{
	std::vector<int> bard;
	for (int i = 0; i < 4; i++)
	{
		int value = rand() % 10;
		bool accepted = true;
		for (int k : bard) if (k == value) accepted = false;
		if (accepted) bard.push_back(value);
		else i--;
	}
	return bard;
}

std::vector<int> ReadInput(int step)
{
	bool correct = false;
	std::vector<int> out = {-1,-1,-1,-1};
	while (!correct)
	{
		correct = true;
		std::cout << step << ": Введите значение:\n";
		std::string buf;
		std::cin >> buf;
		if (buf.length() != 4) break;
		for (int i = 0;i<4;i++)
		{
			if (isdigit(buf[i]))
			{
				int val = buf[i]-'0';
				for (int a : out) if (a == val)
				{
					correct = false;
					break;
				}
				out[i] = val;
			}
			else
			{
				correct = false;
				break;
			}
		}
		if (correct) return out;
	}
}

bool Check(std::vector<int> board, std::vector<int> userInput)
{
	int cows = 0;
	bool bulls[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j=0; j < 4; j++)
		{
			if (userInput[i] == board[j])
			{
				if (i == j) bulls[i] = true;
				else cows++;
			}
		}
	}
	int bullAmount = 0;
	for (bool a : bulls)
	{
		char output = '-';
		if (a)
		{
			output = '+';
			bullAmount++;
		}
		std::cout << output;
	}
	if (bullAmount == 4)return true;
	std::cout << "\nБыки: " << bullAmount << "\tКоровы: " << cows<<std::endl;
	return false;
}