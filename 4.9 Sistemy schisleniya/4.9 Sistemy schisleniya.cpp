#include <iostream>
#include <cmath>
#include <string>

int CalculateFraction(std::string value);
int ConvertToDec(char c, int NS);

int main()
{
	setlocale(0, "");
	int startNS,endNS;
	std::string value;
	
	//Сбор данных о числе
	std::cout << "Введите стартовую систему счисления: ";
	std::cin >> startNS;
	std::cout << "Введите число в данной системе: ";
	std::cin >> value;
	std::cout << "Введите конечную систему счисления: ";
	std::cin >> endNS;
	
	double DecNumber = 0; //В будущем сконвертированное в 10с число
	int powers = CalculateFraction(value); //Максимальная степень числа
	bool fractionNumber = false; //Проверка на дробность значения.
	

	for (char c: value)
	{
		int val;
		try {
			//Проверка на наличие точки дробного числа
			//! При наличии 2 и более точек будет выдано исключение !
			if (c == '.')
			{
				if (!fractionNumber)
				{
					fractionNumber = true; //Установка что число дробное
					continue;
				}
				else throw std::exception("Обнаружено более 2 точек в числе");
			}
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
	
	//Контрольный вывод числа в 10 системе
	std::cout << "Число в 10 системе: " << DecNumber;
	
	std::string resultIntegerNumber="";
	std::string resultFraction="";
	
	//Рассчет целой части
	long intPart = (int)DecNumber;
	while (intPart>0)
	{
		int stack = intPart % endNS;
		if (stack > 9)
		{
			resultIntegerNumber += char(stack - 10) + 'A';
		}
		else
		{
			resultIntegerNumber += (char)'0' + stack;
		}
		intPart /= endNS;
	}

	//Рассчет дробной части
	std::string doublePart = std::to_string(DecNumber-(int)DecNumber);
	doublePart = doublePart.substr(2);
	int IVB = std::stoi(doublePart);
	int counter = doublePart.substr(2).length();
	while (IVB != 0 && counter>0)
	{
		int mantis = IVB * endNS;
		std::string strMantis = std::to_string(mantis);
		std::string SIVB = std::to_string(IVB);
		int difference = strMantis.length() - SIVB.length();
		std::string unit = SIVB.substr(0, difference);
		
		int UnitInt = std::stoi(unit);
		if (UnitInt > 9)
		{
			resultFraction+= char(UnitInt - 10) + 'A';
		}
		else
		{
			resultFraction += (char)'0' + UnitInt;
		}

		IVB = std::stoi(strMantis.substr(difference));
		counter--;
	}
	
	std::reverse(resultIntegerNumber.begin(), resultIntegerNumber.end());
	std::cout << "\nРезультат: " << resultIntegerNumber;
	if (resultFraction != "") std::cout << "." + resultFraction;
}

/// <summary>
/// Конвертирует символ в 10 систему счисления.
/// </summary>
/// <param name="c">Символ которое необходимо сконвертировать</param>
/// <param name="NS">Система счисления для символа</param>
/// <returns>int значения c в десятичной системе счисления</returns>
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

/// <summary>
/// Обнаружает позицию точки при ее наличии и считает степени системы счисления
/// </summary>
/// <param name="value">Строка записи числа любой системы с точкой</param>
/// <returns>Количество степеней</returns>
int CalculateFraction(std::string value)
{
	if (value.find('.') != std::string::npos)
	{
		return value.find('.')-1;
	}
	else return value.length() - 1;
}