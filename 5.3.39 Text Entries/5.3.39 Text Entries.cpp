#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>

typedef std::tuple<std::string, int> FoundRecord;

int main()
{
	setlocale(0, "");

	std::vector<std::string> Lib;
	std::ifstream filereader("Task.txt");
	if (filereader.is_open())
	{
		std::string buf;
		while (std::getline(filereader,buf))
		{
			Lib.push_back(buf);
		}
	}
	else
	{
		std::cout << "Exception: Файл занят другим процессом!";
		exit(0);
	}

	std::string entry = "";
	std::cout << "Введите искомое значение: ";
	std::cin >> entry;

	std::vector<FoundRecord> Records;

	int entrySize = entry.length();

	for (std::string c : Lib)
	{
		int amount = 0;
		for (int i = 0; i < c.length()-entrySize; i++)
		{
			std::string subword = c.substr(i, entrySize);
			if (subword == entry)amount++;
		}
		if (amount != 0)
		{
			FoundRecord record(c, amount);
			Records.push_back(record);
		}
	}

	for(FoundRecord rec : Records)
	{
		std::cout << std::get<0>(rec) << " = " << std::get<1>(rec)<<std::endl;
	}
	std::cout << "Всего соответствий: " << Records.size();
}