#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>


//Functions
void CircleWizard();
void TriangleWizard();
void RectangleWizard();


int main()
{
	setlocale(0, "");
	while (true)
	{
		std::cout << 
			"Выберите подпрограмму рассчета \n "
			"1. Рассчет площади прямоугольника \n "
			"2. Рассчет площади круга \n "
			"3. Рассчет площади треугольника\n "
			"Ваш выбор: ";
		int input;
		std::cin >> input;
		switch (input)
		{
		case 1:
			RectangleWizard();
			break;
		case 2:
			CircleWizard();
			break;
		case 3:
			TriangleWizard();
			break;
		default:
			std::cout <<
				"\n"
				"=======================================\n"
				"Неверный аргумент. Повторите попытку...\n"
				"=======================================\n"
				"\n";
			break;
		}
	}
}

void RectangleWizard()
{
	std::cout << "Подпрограмма расчета прямоугольника\n";
	std::cout << "Введите длину стороны A:";
	double A;
	std::cin >> A;
	std::cout << "Введите длину стороны B:";
	double B;
	std::cin >> B;
	std::cout << "\nПлощадь прямоугольника: " << A * B<<std::endl;
}
void CircleWizard()
{
	std::cout << "Подпрограмма расчета круга\n";
	std::cout << "Введите радиус круга: ";
	double R;
	std::cin >> R;
	double S = M_PI * std::pow(R,2);
	std::cout << "Площадь круга: " << S << std::endl;
}
void TriangleWizard()
{
	std::cout << "Подпрограмма расчета прямоугольника\n";
	std::cout << "Введите длину стороны треугольника: ";
	double A;
	std::cin >> A;
	double h;
	std::cout << "Введите высоту треугольника: ";
	std::cin >> h;
	std::cout << "Площадь треугольника: " << 0.5 * A * h<<std::endl;
}