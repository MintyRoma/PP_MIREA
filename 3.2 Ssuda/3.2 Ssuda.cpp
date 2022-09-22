#include <iostream>
#include <iomanip>
#define precision 15

int main()
{
	setlocale(0, "");

	double sum, years, monthpay;
	
	std::cout << "Введите сумму заема: ";
	std::cin >> sum;

	std::cout << "Введите срок заема в годах: ";
	std::cin >> years;

	std::cout << "Введите месяную выплату: ";
	std::cin >> monthpay;

	int counted_precision = 0;

	double percent = 0;
	double scale = 10;

	while (counted_precision < precision)
	{
		percent += scale;
		double r = percent / 100;
		double calculated_pay = (sum*r*std::pow(1+r,years)) / (12*(std::pow(1+r,years)-1));
		
		std::cout << "Percent="<<percent <<"  MonthPay="<<calculated_pay << std::endl;
		
		if (monthpay < calculated_pay)
		{
			counted_precision++;
			percent -= scale;
			scale /= 10;
		}
		if (monthpay == calculated_pay) break;
	}
	std::cout << "Процентная ставка: " <<std::setprecision(precision) << percent;

}
