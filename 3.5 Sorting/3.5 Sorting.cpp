#include <iostream>
#include <string>
#include <random>
#include <array>

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	std::cout << "Генерация случайных букв...\n";
	std::string base = "";

	for (int i = 0; i < 30; i++)
	{
		int charnum = std::rand() % 26;
		char c = 'a'+charnum;
		base += c;
	}
	std::cout << "Результат: \n" << base;
	std::cout << "\nСортировка..." << std::endl;

	std::string res;
	for(int i=0;i<30;i++)
	{
		for (int j = i+1;j<30;j++)

	}

}