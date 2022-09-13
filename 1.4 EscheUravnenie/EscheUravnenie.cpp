#include <iostream>
#include <cmath>

int main()
{
	double a = 1;
	double b = 1;
	double c = 1;

	std::cin >> a >> b >> c;
	
	if (a == 0)
	{
		if (b==0 && c==0) std::cout << "Any x";
		else if (b == 0) std::cout << "No x";
		else std::cout << (c * -1) / b;
		return 0;
	}
	


	double Dis = std::pow(b, 2) - (4 * a * c);
	
	if (Dis > 0)
	{
		double x1 = (b * -1 - std::sqrt(Dis)) / (2 * a);
		double x2 = (b * -1 + std::sqrt(Dis)) / (2 * a);
		std::cout << "X1 = " << x1 << std::endl << "X2 = " << x2;
	}
	else if (Dis == 0)
	{
		std::cout << "X = "<<(b * -1) / (2 * a);
	}
	else
	{
		std::cout << "No X!";
	}
}