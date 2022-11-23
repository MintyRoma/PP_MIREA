#include <iostream>
#include <string>
#include <random>
#include <array>
#define amount 100

std::string MergeSort(std::string arr);

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	std::cout << "Генерация случайных букв...\n";
	std::string base = "";

	for (int i = 0; i < amount; i++)
	{
		int charnum = std::rand() % 26;
		char c = 'a'+charnum;
		base += c;
	}
	std::cout << "Результат: \n" << base;
	std::cout << "\nСортировка..." << std::endl;
	std::cout << MergeSort(base);
}

std::string MergeSort(std::string arr)
{
	std::string firstpart;
	std::string secondpart;
	
	if (arr.length() > 2)
	{
		firstpart = MergeSort(arr.substr(0,arr.length()/2));
		secondpart = MergeSort(arr.substr(arr.length()/2, arr.length()));
	}
	else
	{
		if (arr.length() == 2)
		{
			if (arr[0] > arr[1])
			{
				char c = arr[0];
				arr[0] = arr[1];
				arr[1] = c;
			}
		}
		return arr;
	}
	std::string part;
	int cache = firstpart.length() + secondpart.length();
	for (int i=0;i<cache;i++)
	{
		if (firstpart.empty()) 
		{
			part += secondpart[0];
			secondpart.erase(0, 1);
			continue;
		}
		else if (secondpart.empty())
		{
			part += firstpart[0];
			firstpart.erase(0, 1);
			continue;
		}

		if (firstpart[0] < secondpart[0])
		{
			part += firstpart[0];
			firstpart.erase(0, 1);
		}
		else
		{
			part += secondpart[0];
			secondpart.erase(0, 1);
		}
	}
	return part;
}