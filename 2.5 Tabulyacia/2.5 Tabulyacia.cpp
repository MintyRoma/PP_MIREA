
/* #include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(0, "");
	double x = -4;
	while (x <= 4)
	{
		if (x != 1)
		{
			cout << "y= " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
		}
		else
		{
			cout << "Ошибка" << endl;
		}
		x += 0.5;
	}
	return 0;
}*/ 
//Более простой вариант а в твоем не понимаю нефига))//

#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	setlocale(0, "");

	for (double x = -4; x <= 4; x += 0.5)
	{
		char sym = ' ';
		if (x < 0)sym = '-';
		if (x > 0)sym = ' ';
		if (x == 1)
		{
			std::cout << "x= " << std::setprecision(2) << sym << x << "   |   " << "---------" << std::endl;
			continue;
		}
		double y = (std::pow(x, 2) - 2 * x + 2) / (x - 1);
		std::cout << "x= " << std::setprecision(2) << std::fixed << sym << std::fabs(x) << "   |   " << "y=" << std::setprecision(4) << y << std::endl;

	}
}