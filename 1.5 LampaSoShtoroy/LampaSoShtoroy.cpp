#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru-RU");
	int lamp = -1;
	int window = -1;
	int weather = -1;
	do
	{
		std::cout << "Лампа включена? Введите 1 если да и 0 если нет: ";
		std::cin >> lamp;
	} while ((lamp != 0) && ( lamp != 1));

	do
	{
		std::cout << "Шторы открыты? Введите 1 если да и 0 если нет: ";
		std::cin >> window;
	} while (window != 0 && window != 1);

	do
	{
		std::cout << "На улице светло? Введите 1 если да и 0 если нет: ";
		std::cin >> weather;
	} while (weather != 0 && weather != 1);

	if ((weather==1 && window==0) || lamp==1) std::cout << "В комнате светло";
	else std::cout << "В комнате темно :(";
}