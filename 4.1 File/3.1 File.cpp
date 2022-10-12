#include <iostream>
#include <fstream>
#include <string>

int main()
{
	setlocale(0, "");
	
	srand(time(NULL));
	std::ofstream file;
	file.open("task.txt");
	std::cout << "Запись в файл..."<<std::endl;

	for (int i = 0; i < 10; i++)
	{
		int info = std::rand()%100 - 50;
		file << info << std::endl;
		std::cout << info << std::endl;
	}
	file.close();

	std::ifstream reader("task.txt", std::ios::out);
	std::cout << "\n\nЧтение из файла..." << std::endl;

	double sum = 0;
	if (reader.is_open())
	{
		double data;
		while (reader >> data)
		{
			std::cout << data << std::endl;
			sum += data;
		}
	}
	std::cout << "Результат: " << sum;
}