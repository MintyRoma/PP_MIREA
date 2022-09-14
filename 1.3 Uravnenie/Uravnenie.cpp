#include <iostream>

int main()
{
	double b = 1;
	double c = 1;

	std::cin >> b >> c;
	if (b == 0)
	{
		std::cout << "Деление на 0!";
		return 0;
	}
	double x = (c * -1) / b;
	std::cout << x;
}