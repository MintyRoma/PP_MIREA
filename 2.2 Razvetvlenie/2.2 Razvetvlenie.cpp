#include <iostream>
#include <cmath>

int main()
{
	setlocale(0, "");
	double x, a;

	std::cout << "Введите X: ";
	std::cin >> x;
	std::cout << "Введите A: ";
	std::cin >> a;

	double absX = std::abs(x);
	if (absX < 1)
	{
		double res = a * std::log(absX);
		std::cout << "Результат: " << res;
	}
	else
	{
		if (std::pow(x, 2) <= a)
		{
			double res = std::sqrt(a - std::pow(x, 2));
			std::cout << "Результат: " << res;
		}
		else
		{
			std::cout << "Невозможное выражение";
		}
	}
}