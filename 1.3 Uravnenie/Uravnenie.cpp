#include <iostream>

int main()
{
	setlocale(0, "");
	double b = 1;
	double c = 1;

	std::cin >> b >> c;
	if (b == 0)
	{
		if (c == 0) std::cout << "Х = any";
		else std::cout << "Нет корней";
		return 0;
	}
	double x = -c / b;
	std::cout << x;
}