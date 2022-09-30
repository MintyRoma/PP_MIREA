#include <iostream>
#include <iomanip>
#define precision 20

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

	if (sum <= 0 || years <= 0 || monthpay <= 0)
	{
		std::cout << "Error: Wrong input";
		exit(0);
	}

	int counted_precision = 0;

	double percent = 0;
	double scale = 10;

	while (counted_precision < precision)
	{
		percent += scale;
		double r = percent / 100;
		double calculated_pay = (sum * r * std::pow(1 + r, years)) / (12 * (std::pow(1 + r, years) - 1));

		//DEBUG
		std::cout <<std::setprecision(precision) << "Percent=" << percent << "  MonthPay=" << calculated_pay << std::endl;
		std::cout << "Reference:" << monthpay << "   Calculated:" << calculated_pay<<std::endl;
		std::cout << "Precision:" << counted_precision << std::endl<<std::endl;
		if (monthpay < calculated_pay)
		{
			counted_precision++;
			percent -= scale;
			scale /= 10;
		}
		if (monthpay  == calculated_pay) break;
	}
	std::cout << "Процентная ставка: " <<std::fixed << std::setprecision(precision) << percent;

}
