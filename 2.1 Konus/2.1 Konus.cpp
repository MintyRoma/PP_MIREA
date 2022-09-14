#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

int main()
{
	setlocale(0,"");
	int R = 0;
	int r = 0;
	int h = 0;
	
	std::cout << "Введите радиус: ";
	std::cin >> R;

	std::cout << "Введите радиус верхнего огрызка: ";
	std::cin >> r;

	std::cout << "Введите высоту: ";
	std::cin >> h;

	if (r > R)
	{
		std::cout << "Радиус верха не может быть больше чем низа";
		return 0;
	}

	double l = std::sqrt((r*r)+(h*h));

	double Objem = (double)1/3 * M_PI * h * (std::pow(R, 2) + R * r + std::pow(r, 2));
	double FullPoverhnost = M_PI * (std::pow(R, 2) + ((R + r) * l) + std::pow(r, 2));

	std::cout << "Образующая l: " << l << std::endl;
	std::cout << "Объем конуса: " << Objem<<std::endl;
	std::cout << "Полная площадь поверхности: " << FullPoverhnost;
}