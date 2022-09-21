#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	setlocale(0, "");

	for (double x = -4; x <= 4; x += 0.5)
	{
		char sym=' ';
		if (x < 0)sym = '-';
		if (x > 0)sym = ' ';
		if (x == 1)
		{
			std::cout << "x= " << std::setprecision(2)<<sym<< x << "   |   " << "---------" << std::endl;
			continue;
		}
		double y = (std::pow(x, 2) - 2 * x + 2) / (x - 1);
		std::cout << "x= " << std::setprecision(2) <<std::fixed<<sym<< std::fabs(x) << "   |   " << "y="  << std::setprecision(4)<< y << std::endl;

	}
}