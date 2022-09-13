#include <iostream>
#include <cmath>

int main()
{
	setlocale(0, "");

	for (double x = -4; x <= 4; x += 0.5)
	{
		if (x == 1)
		{
			std::cout << "--- |";
			continue;
		}
		std::cout << (std::pow(x, 2) - 2 * x + 2) / (x - 1)<<" | ";
	}
}