#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<int> SelectionSort(std::vector<int> data);

int main()
{
	setlocale(0, "");
	std::ifstream Areader("A.txt");
	std::vector<int> AData;
	if (Areader.is_open())
	{
		std::string buf;
		while (std::getline(Areader, buf))
		{
			AData.push_back(std::stoi(buf));
		}
	}
	else
	{
		std::cout << "Исключение: файл A.txt занят";
		exit(0);
	}
	Areader.close();


	std::ifstream Breader("B.txt");
	std::vector<int> BData;
	if (Breader.is_open())
	{
		std::string buf;
		while (std::getline(Breader, buf))
		{
			BData.push_back(std::stoi(buf));
		}
	}
	else
	{
		std::cout << "Исключение: файл B.txt занят";
		exit(0);
	}
	Breader.close();

	AData = SelectionSort(AData);
	BData = SelectionSort(BData);

	std::ofstream Cwriter;
	Cwriter.open("C.txt",std::ios::in);

	if (Cwriter.is_open())
	{
		Cwriter << "Отсортированный A:" << std::endl;
		std::cout << "Запись в файл данных A:\n";
		for (int c : AData)
		{
			Cwriter << c << std::endl;
			std::cout << c << std::endl;
		}
		
		Cwriter << "Отсортированный B:" << std::endl;
		std::cout << "Запись в файл данных B:\n";
		for (int c : BData)
		{
			Cwriter << c << std::endl;
			std::cout << c << std::endl;
		}
	}
	else
	{
		std::cout << "Исключение: файл C.txt занят";
		exit(0);
	}
	Cwriter.close();
}

std::vector<int> SelectionSort(std::vector<int> data)
{
	for (int i = 0; i < data.size()-1; i++)
	{
		int swapIndex=i;
		int value = data[i];
		int min = data[i];
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data[j] <= min)
			{
				min = data[j];
				swapIndex = j;
			}
		}
		std::swap(data[i], data[swapIndex]);
	}
	return data;
}