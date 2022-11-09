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

	double calculatedPay = 0;
	double percent = 50;
	double previous_percent = 100;

	while (std::abs(calculatedPay - monthpay) > 0.0001)
	{
		double SomeR = percent / 100;
		calculatedPay = (sum * SomeR * std::pow(1 + SomeR, years)) / (12 * (std::pow(1 + SomeR, years) - 1));
		
		double buf = percent;
		if (calculatedPay > monthpay)
		{
			percent -= std::abs(previous_percent - percent) / 2;
		}
		else if (calculatedPay < monthpay)
		{
			percent += std::abs(previous_percent - percent) / 2;
		}
		else break;
		previous_percent = buf;
		std::cout << "Percent: " << percent<<std::endl;
		std::cout << "Calculated pay: " << calculatedPay << "\tReference: " << monthpay<<"\n\n";
	}
	std::cout << "Процентная ставка: " <<std::fixed << std::setprecision(precision) << percent;

}
