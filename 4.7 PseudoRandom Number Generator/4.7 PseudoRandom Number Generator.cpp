#include <iostream>

int Gen1(int previous);
int Gen2(int previous);

int main()
{
	setlocale(0, "");
	int gen = 0;
	while (gen != 1 && gen != 2)
	{
		std::cout << "Выберите генератор\n"\
			"1. Вариант I\n"\
			"2. Вариант II\n"\
			"Ответ: ";
		std::cin >> gen;
	}
	int amount;
	std::cout << "Введите кол-во генерируемых чисел: ";
	std::cin >> amount;
	int previous=0;
	for (int i = 0; i < amount; i++)
	{
		if (gen == 1)previous = Gen1(previous);
		else previous = Gen2(previous);
		std::cout << i+1<<"."<<previous<<std::endl;
	}
}

int Gen1(int previous)
{
	int m = 37;
	int b = 3;
	int c = 64;
	return (m * previous + b) % c;
}

int Gen2(int previous)
{
	int m = 25713;
	int b = 13849;
	int c = 65537;
	return (m * previous + b) % c;
}