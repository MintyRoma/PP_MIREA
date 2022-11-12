#include <iostream>

int main()
{
	setlocale(0, "");
	std::cout << "Введите стоимость основы спинера: ";
	int baseCost;
	std::cin >> baseCost;
	std::cout << "Введите стоимость одной лопасти: ";
	int wingCost;
	std::cin >> wingCost;
	std::cout << "Введите предполагаемую стоимость спинера: ";
	int totalCost;
	std::cin >> totalCost;
	std::cout << "Максимальное количество лопастей: " << (totalCost - baseCost) / wingCost;
}