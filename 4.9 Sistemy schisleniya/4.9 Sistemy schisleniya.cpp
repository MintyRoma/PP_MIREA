#include "4.9 Sistemy schisleniya.h"


int main()
{
	setlocale(0, "");
	int startNS,endNS;
	std::string value;
	std::cout << "Введите стартовую систему счисления: ";
	std::cin >> startNS;
	std::cout << "Введите число в данной системе: ";
	std::cin >> value;
	std::cout << "Введите конечную систему счисления: ";
	std::cin >> endNS;
	try
	{
		if (startNS > 36 || endNS > 36) throw std::exception("Начальная или конечная система счисления слишком велика!");
		if (startNS < 2 || endNS < 2) throw std::exception("Начальная или конечная система счисления слишком маленькая!");
	}
	catch (std::exception Ex)
	{
		std::cout << "\nException: " << Ex.what();
		exit(0);
	}
	int DecNumber = 0;
	int powers = value.length() - 1;
	for (char c: value)
	{
		int val;
		try {
			val = ConvertToDec(c, startNS);
			
		}
		catch (std::exception e)
		{
			std::cout <<"\nException:"<< e.what();
			exit(0);
		}
		DecNumber += val * std::pow(startNS, powers);
		powers--;
	}
	std::cout << "Число в 10 системе: " << DecNumber;
	std::string resultNumber;
	while (DecNumber != 0)
	{
		int stack = DecNumber % endNS;
		if (stack > 9)
		{
			resultNumber += char(stack - 10) + 'A';
		}
		else
		{
			resultNumber += (char)'0' + stack;
		}
		DecNumber /= endNS;
	}
	std::reverse(resultNumber.begin(), resultNumber.end());
	std::cout <<"\nРезультат: " << resultNumber;
}

int ConvertToDec(char c, int NS)
{
	if (isdigit(c))
	{
		int code = c - '0';
		if (code >= NS) throw std::exception("Символ выходит за рамки системы счисления");
		return code;
	}
	else if (isalpha(c))
	{
		c = toupper(c);
		int code = c - 'A' + 10;
		if (code >= NS) throw std::exception("Символ выходит за рамки системы счисления!");
		return code;
	}
	else
	{
		throw std::exception("Присутствует неподдерживаемый символ!");
	}
}