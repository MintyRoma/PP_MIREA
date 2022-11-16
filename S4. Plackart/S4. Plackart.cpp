#include <iostream>

int coupe_schema[9][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
		{17,18,19,20},
		{21,22,23,24},
		{25,26,27,28},
		{29,30,31,32},
		{33,34,35,36}
	};

int corridor_schema[9][2] =
	{
		{53,54},
		{52,51},
		{50,49},
		{48,47},
		{46,45},
		{44,43},
		{42,41},
		{40,39},
		{38,37}
	};

bool Reserve(int place);
int main()
{
	setlocale(0, "");
	

	int amount;
	std::cout << "Введите число свободных мест: ";
	std::cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		int place;
		std::cin >> place;
		bool status = Reserve(place);
		if (!status)
		{
			std::cout << "Место уже занято или его не существует!";
			i--;
		}
	}

	int res = 0;
	int runt = 0;
	for (int i = 0; i < 9; i++)
	{
		bool empty = true;
		for (int j = 0; j < 4; j++)
		{
			if (coupe_schema[i][j] != 0)
			{
				empty = false;
				break;
			}
		}
		if (empty)
		{
			for (int j = 0; j < 2; j++)
			{
				if (corridor_schema[i][j] != 0)
				{
					empty = false;
					break;
				}
			}
		}
		if (empty)
		{
			runt++;
		}
		else
		{
			if (runt > res) res = runt;
			runt = 0;
		}
	}

	std::cout << "Количество свободных купе подряд: " << res;
}

bool Reserve(int place)
{
	if (place >= 37)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (corridor_schema[i][j] == place)
				{
					corridor_schema[i][j] = 0;
					return true;
				}
			}
		}
	}
	else if (place > 0 && place < 37)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (coupe_schema[i][j] == place)
				{
					coupe_schema[i][j] = 0;
					return true;
				}
			}
		}
	}
	return false;
}