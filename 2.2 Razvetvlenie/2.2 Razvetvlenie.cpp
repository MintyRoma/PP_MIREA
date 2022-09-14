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

	double absX = std::fabs(x);
	if (absX < 1)
	{
		if (absX == 0)
		{
			std::cout << "Ошибка: Логарифм 0!";
			return 0;
		}
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
			std::cout << "Ошибка: Корень меньше или равен 0";
		}
	}
}