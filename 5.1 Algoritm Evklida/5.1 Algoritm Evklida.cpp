#include <iostream>
#include <cmath>

int EvklidMinus(int A, int B);
int EvklidMod(int A, int B);

int main()
{
	setlocale(0, "");
	int numA, numB;
	std::cout << "Введите первое число: ";
	std::cin >> numA;
	std::cout << "Введите второе число: ";
	std::cin >> numB;
	
	
	std::cout << EvklidMinus(numA, numB)<<std::endl;
	std::cout << EvklidMod(numA, numB);
}

int EvklidMinus(int A, int B)
{
	while (A != B && A != 0)
	{
		if (A > B) A -= B;
		else B -= A;
	}
	return A;
}

int EvklidMod(int A, int B)
{
	bool parity = true;
	while (A != B && A != 0)
	{
		if (parity)
		{
			if (A % B == 0) return B;
			else A%=B;
			parity = !parity;
			continue;
		}
		else
		{
			if (A % B == 0) return A;
			else B %= A;
			parity = !parity;
			continue;
		}
		
	}
}