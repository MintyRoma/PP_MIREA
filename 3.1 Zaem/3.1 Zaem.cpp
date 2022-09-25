/* #include <iostream>
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
} */

#include <iostream>
#include <cmath>


int main()
{
	setlocale(0, "");
	double S, n, P, m;
	
	std::cout << "Введите сумму займа,срок заема и процентную ставку\n";
	std::cin >> S >> n >> P;
	double r = P / 100;
	if (S < 0 || n < 0 || P < 0)
	{
		std::cout << "Введены отрицательные значения\n";
		return 0;
	}
	else
	{
		m = (S * r * std::pow(1 + r, P)) / (12 * (std::pow(1 + r, P) - 1));
		std::cout << "Месячная выплата " << m;
	}
}