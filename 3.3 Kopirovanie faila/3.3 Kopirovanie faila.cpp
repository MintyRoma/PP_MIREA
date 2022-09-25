#include <iostream>
#include <fstream>
#include <string>

int main()
{
	setlocale(0, "");
	std::fstream filereader("Task.txt");
	if (filereader.is_open())
	{
		std::string buffer;
		while (std::getline(filereader,buffer))
		{
			std::cout << buffer<<std::endl;
		}
	}
	else
	{
		std::cout << "Ошибка открытия файла";
	}
}