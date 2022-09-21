#include <iostream>
#include <cmath>

int main()
{
	setlocale(0, "");

	double x, y, b;

	std::cout << "Введите X:";
	std::cin >> x;
	std::cout << "Введите Y:";
	std::cin >> y;
	std::cout << "Введите B:";
	std::cin >> b;

	if (b - y <= 0)
	{
		std::cout << "Отрицательный логарифм или равный 0!";
		return 0;
	}
	else if (b - x < 0)
	{
		std::cout << "Отрицательный корень!";
		return 0;
	}

	double tmp1 = std::log(b - y);
	double tmp2 = std::sqrt(b - x);
	double z = tmp1*tmp2;
	std::cout << "Z = " << z;

}
