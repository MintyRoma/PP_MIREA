#include <iostream>

int main()
{
	setlocale(0, "");
	std::cout << "Введите количество лопастей: ";
	int wings;
	std::cin >> wings;
	int threeWings = 0;
	int fourWings = 0;
	while (wings != 0)
	{	
		if (wings % 4==0)
		{
			wings -= 4;
			fourWings++;
			continue;
		}
		if (wings>=3)
		{
			wings -= 3;
			threeWings++;
			continue;
		}
		else
		{
			threeWings = 0;
			fourWings = 0;
			wings = 0;
			break;
		}
	}
	std::cout << threeWings<<std::endl;
	std::cout << fourWings;
}