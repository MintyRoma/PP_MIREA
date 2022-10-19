#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> QuickSort(std::vector<std::string> data);
int CheckWords(std::string A, std::string B);

int main()
{
	setlocale(0, "");
	std::ifstream reader("Task.txt");
	std::vector<std::string> Lib;
	if (reader.is_open())
	{
		std::string buf;
		while (std::getline(reader, buf)) Lib.push_back(buf);
	}
	else
	{
		std::cout << "Файл занят другим процессом";
		exit(0);
	}

	Lib = QuickSort(Lib);
	for (std::string s : Lib) std::cout << s << std::endl;
}

std::vector<std::string> QuickSort(std::vector<std::string> data)
{
	if (data.size() <= 1) return data;
	int milestone = data.size() / 2;
	std::string reference = data[milestone];

	std::vector<std::string> LowPart;
	std::vector<std::string> HighPart;

	for (int i = 0; i < data.size(); i++)
	{
		if (i == milestone) continue;
		int status = CheckWords(data[i], reference);
		if (status == 1)
		{
			HighPart.push_back(data[i]);
		}
		else
		{
			LowPart.push_back(data[i]);
		}
	}

	std::vector<std::string> SortedLow = QuickSort(LowPart);
	std::vector<std::string> SortedHigh = QuickSort(HighPart);
	std::vector<std::string> Result;
	Result.insert(Result.end(), SortedLow.begin(), SortedLow.end());
	Result.push_back(reference);
	Result.insert(Result.end(), SortedHigh.begin(), SortedHigh.end());
	return Result;
}

/// <summary>
/// Сверяет слова с друг другом и выявляет какое из них по порядку раньше
/// -1 = слово A раньше
///  0 = слова одинаковы
///  1 = слово B раньше
/// </summary>
/// <param name="A">Строка A</param>
/// <param name="B">Строка B</param>
/// <returns>Число обозначающее результат проверка</returns>
int CheckWords(std::string A, std::string B)
{
	int minimalLength;
	bool firstIsMin = false;
	if (A.length() <= B.length())
	{
		firstIsMin = true;
		minimalLength = A.length();
	}
	else minimalLength = B.length();
	
	for (int i = 0; i < minimalLength; i++)
	{
		if (A[i] < B[i]) return -1;
		if (A[i] > B[i]) return 1;
	}
	
	if (firstIsMin)
	{
		if (A.length() == B.length()) return 0;
		return -1;
	}
	else return 1;
}