#include "5.3.17 Word Sorting.h"



int main()
{
	setlocale(0, "");
	std::chrono::system_clock::time_point FileReadingStarted = std::chrono::system_clock::now();
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
	std::chrono::duration<double> ReadingElapsed = std::chrono::system_clock::now() - FileReadingStarted;
	
	std::chrono::system_clock::time_point SortingStarted = std::chrono::system_clock::now();
	Lib = QuickSort(Lib);
	std::chrono::duration<double> SortingElapsed = std::chrono::system_clock::now() - SortingStarted;
	
	for (std::string s : Lib) std::cout << s << std::endl;
	
	std::cout << "File Reading time: " << ReadingElapsed.count()<<" secs."<<std::endl;
	std::cout << "Sorting time elapsed: " << SortingElapsed.count()<<" secs.";
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
		CheckResult status = CheckWords(data[i], reference);
		if (status== CheckResult::BisEarlier)
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
/// AisEarlier = слово A раньше
/// Same = слова одинаковы
/// BisEarlier = слово B раньше
/// </summary>
/// <param name="A">Строка A</param>
/// <param name="B">Строка B</param>
/// <returns>Значение проверки</returns>
CheckResult CheckWords(std::string A, std::string B)
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
		if (A[i] < B[i]) return CheckResult::AisEarlier;
		if (A[i] > B[i]) return CheckResult::BisEarlier;
	}
	
	if (firstIsMin)
	{
		if (A.length() == B.length()) return CheckResult::Same;
		return CheckResult::AisEarlier;
	}
	else return CheckResult::BisEarlier;
}