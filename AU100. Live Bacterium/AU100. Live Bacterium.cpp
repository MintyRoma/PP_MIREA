#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <filesystem>
#include <array>

void PrepareFileStorage();
void ConstructNewConfigs();

int main()
{
	setlocale(0, "");

	//Config check
	while (true)
	{
		try
		{
			PrepareFileStorage();
		}
		catch (std::exception ex)
		{
			std::cout << ex.what();
			std::string ak = ex.what();
			ak = ak.substr(0, 3);
			if (ak == "FIB")
			{
				return -1;
			}
			else if (ak == "LLE" || ak == "UCE" || ak=="WLL")
			{
				ConstructNewConfigs();
			}
		}
	}
	
	//Arrays with info
	std::array<std::array<int,21>,21> now;
	int future[21][21];

	now = CopyWorldConfig(); //Copying world

	//User input
	int maxgen = -1;
	while (maxgen < 1 && maxgen>10000)
	{
		std::cout << "Введите количество поколений: ";
		std::cin >> maxgen;
	}

	for (int runtimeGen = 0; runtimeGen < maxgen; runtimeGen++)
	{

	}

}

void PrepareFileStorage()
{
		std::ifstream checkDAT("./work.dat");
		if (!checkDAT.is_open()) throw std::exception("FIB: Файл work.dat открыт в режиме монопольного доступа другой программой!");
		checkDAT.close();
		bool worldsize = true;
		std::string buf;
		int lines = 0;
		while (getline(checkDAT, buf))
		{
			if (lines > 21) throw std::exception("LLE: Ошибка заполнения файла work.dat! В файле более 21 строки!");
			lines++;
			if (buf.length() != 21)
			{
				throw std::exception("UCE: Ошибка заполнения файла work.dat! Одна и более строк содержит более 21 символа!");
			}
		}
		if (lines != 21) throw std::exception("WLL: Ошибка заполнения файла work.dat! Количество строк меньше чем надо");
}

void ConstructNewConfigs()
{
	std::ofstream dat("./work.dat",std::ios::out);
	if (!dat.is_open()) throw std::exception("FIB: Не удается создать файл work.dat!");
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			dat << '0';
		}
		dat << '\n';
	}
	dat.close();
	return;
}

std::array<std::array<int,21>,21> CopyWorldConfig()
{
	std::array<std::array<int, 21>, 21> archive;

	std::ifstream configreader("./work.dat");
	std::string buf;
	int x = 0;
	int y = 0;
	while (getline(configreader, buf))
	{
		for (char c : buf)
		{
			if (c == '0') archive[x][y] = 0;
			else archive[x][y] = 1;
			x++;
		}
		y++;
		x = 0;
	}
	return archive;
}