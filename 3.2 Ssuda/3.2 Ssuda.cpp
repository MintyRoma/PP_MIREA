#include <iostream>

int main()
{
	setlocale(0, "");

	double percent, sum, years, monthpay;
	
	std::cout << "Введите сумму заема: ";
	std::cin >> sum;

	std::cout << "Введите срок заема в годах: ";
	std::cin >> years;

	std::cout << "Введите месяную выплату: ";
	std::cin >> monthpay;

	//АХТУНГ
	//НИЖЕ ПРЕДСТАВЛЕН САМЫЙ БЛЕВОТНЫЙ МЕТОД РАССЧЕТА!!!
	percent = 0.00001;
	while ((sum * percent / 100 * pow((1 + percent / 100), years)) / (12 * (pow((1 + percent / 100), years) - 1)) < monthpay)
	{
		percent += 0.00001;
	}
	std::cout << "Процентная ставка: " << percent << "%";
}