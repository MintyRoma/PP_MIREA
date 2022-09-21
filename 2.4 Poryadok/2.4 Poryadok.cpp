#include <iostream>
#include "cmath"

int main()
{
	setlocale(0, "");

	int start;
	std::cout << "Введите стартовое число";
	std::cin >> start;
	if (start <= 0)
	{
		std::cout << "Начальное число не является натуральным";
		return 0;
	}
	for (int i = start; i < start + 10; i++)
	{
		std::cout << i<<std::endl;
	}
}