#include <iostream>
#include <cmath>

int main()
{
	setlocale(0, "");
	double Sum, Period, Percent;
	
	std::cout << "Введите сумму заема: ";
	std::cin >> Sum;

	std::cout << "Введите срок заема: ";
	std::cin >> Period;

	std::cout << "Введите процентную ставку: ";
	std::cin >> Percent;

	if (Sum < 0 || Period < 0 || Percent < 0)
	{
		std::cout << "Введены отрицательные значения";
		return 0;
	}

	double SomeR = Percent / 100;

	double MonthPay = (Sum*SomeR*std::pow(1+SomeR,Period)) / (12*(std::pow(1+SomeR,Period)-1));
	std::cout << "Ежемесячный платеж: " << MonthPay;
}