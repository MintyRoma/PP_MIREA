#include <iostream>
#include <string>
#include <fstream>

int main()
{
	setlocale(0, "");

	std::string filename="Test.txt";
	std::cout << "Название файла " << filename<<std::endl;
	
	std::ifstream filereader(filename);
	
	if (!filereader.is_open())
	{
		std::string buffer;
		while (filereader >> buffer)
		{
			std::cout << buffer<<std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка: Файл уже занят другим процессом или не найден!";
	}
}