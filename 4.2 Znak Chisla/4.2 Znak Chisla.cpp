﻿#include <iostream>
#include <fstream>
#include <string>

int DefineSymbol(double num);

int main()
{
	while (true)
	{
		double num;
		std::cin >> num;
		std::cout << DefineSymbol(num) << std::endl;
	}
}

int DefineSymbol(double num)
{
	if (num > 0) return 1;
	if (num < 0)return -1;
	else return 0;
}