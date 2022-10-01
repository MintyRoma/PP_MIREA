#include <iostream>
#include <fstream>
#include <string>

int DefineSymbol(int num);

int main()
{
	while (true)
	{
		int num;
		std::cin >> num;
		std::cout << DefineSymbol(num) << std::endl;
	}
}

int DefineSymbol(int num)
{
	if (num > 0) return 1;
	if (num < 0)return -1;
	else return 0;
}