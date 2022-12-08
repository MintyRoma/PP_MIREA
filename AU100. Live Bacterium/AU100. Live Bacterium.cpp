#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <filesystem>
#include <array>
#include <vector>
#include "AU100. Live Bacterium.h"
#include "Windows.h"

bool spreadMode = false;
bool newUIMode = false;
HWND console = GetConsoleWindow();


int main()
{
	setlocale(0, "");
	std::ios::sync_with_stdio(false);

	std::vector<char> charsetLibrary = GetCharsetLibrary();
	std::array<std::array<int, 21>, 21> now = GetPetriDish(charsetLibrary);
	std::array<std::array<int, 21>, 21> future;
	
	ShowImported(charsetLibrary);
	newUIMode = AskNewUI();
	spreadMode = AskSpreading();
	int generations = GetGenerations();



	for (int runtime = 0; runtime < generations; runtime++)
	{
		future = Simulate(now);
		if (!newUIMode)
		{
			system("CLS");
			std::cout<<PrepareExport(future, runtime);
			CreateStatistics(future);
			Sleep(250);
		}
		else
		{
			Sleep(100);
			system("CLS");
			CreateStatistics(future);
			std::cout << "Текущая иттерация: " << runtime;
			DrawSimulation(future);
		}
		FileExport(future,runtime);
		now = future;
	}
}

std::vector<char> ImportCharsetLibrary()
{
	std::fstream importer("work.dat");
	if (importer.is_open())
	{
		std::string info;
		importer >> info;

		std::vector<char> imported;
		for (char c : info)
		{
			imported.push_back(c);
		}
		importer.close();
		return imported;
	}
	else
	{
		importer.close();
		throw std::exception("CME: Ошибка при попытке открытия файла work.dat!");
	}
}

std::array<std::array<int, 21>, 21> ImportPetriDish(std::vector<char> charsetLibrary)
{
	std::fstream importer("work.out");
	if (importer.is_open())
	{
		std::array<std::array<int, 21>, 21> result;
		for (int line = 0; line<21;line++)
		{
			std::string info;
			std::getline(importer, info);
			if (info.length() != 21)
			{
				importer.close();
				throw std::exception("PWS: Ошибка при попытке импорта информации из work.out");
			}

			for (int column = 0; column<21;column++)
			{
				for (char libChar : charsetLibrary)
				{
					if (info[column] == libChar)
					{
						result[line][column] = 1;
						break;
					}
					result[line][column] = 0;
				}
			}
		}

		importer.close();
		return result;
	}
	else
	{
		importer.close();
		throw std::exception("PME: Ошибка при попытке открытия файла work.out!");
	}
}

void RemakeOutFile()
{
	std::fstream generator("work.out");
	if (generator.is_open())
	{
		for (int x = 0;x< 21;x++)
		{
			for (int y=0;y< 21;y++)
			{
				generator << ".";
			}
			generator << "\n";
		}
		generator.close();

		AskToFill();
	}
	else
	{
		generator.close();
		std::cout << "Не удается пересоздать файл. Завершение работы.";
		exit(0);
	}
}

int GetGenerations()
{
	int generations = -1;
	while (generations <= 0)
	{
		std::cout << "\n\nВведите количество поколений: ";
		std::cin >> generations;
	}
	return generations;
}

std::vector<char> GetCharsetLibrary()
{
	std::vector<char> charsetLibrary;
	std::cout << "Импортирую work.dat\n";
	while (true)
	{
		try
		{
			charsetLibrary = ImportCharsetLibrary();
			std::cout << "Импортировал work.dat\n";
			return charsetLibrary;
		}
		catch (std::exception ex)
		{
			std::cout << ex.what();
			std::string message = ex.what();
			std::string errCode = message.substr(0, 3);

			if (errCode == "CME") //Charset Library Error
			{
				std::cout << "Возможно файл занят. Закройте приложение обладающее монопольным доступом к файлу и повторите попытку.";
				int retry = -1;
				while (retry!=0 && retry!=1)
				{
					std::cout << "Для повтора введите 1\n "\
						"Для завершения работы введите 0\n"\
						"Ваш выбор: ";
					std::cin >> retry;
				}
				continue;
			}
			exit(0);
		}
	}
}

std::array<std::array<int, 21>, 21> GetPetriDish(std::vector<char> charsetLibrary)
{
	std::array<std::array<int, 21>, 21> Dish;
	std::cout << "Импортирую work.out\n";
	while (true)
	{
		try
		{
			Dish = ImportPetriDish(charsetLibrary);
			std::cout << "Импортировал work.out\n";
			return Dish;
		}
		catch (std::exception ex)
		{
			std::cout << ex.what();
			std::string message = ex.what();
			std::string errCode = message.substr(0, 3);

			if (errCode == "PME") //Petri Dish file Monopoly Error
			{
				std::cout << "Возможно файл занят. Закройте приложение обладающее монопольным доступом к файлу и повторите попытку.";
				int retry = 0;
				while (!retry)
				{
					std::cout << "Для повтора введите 1: ";
					std::cin >> retry;
				}
				continue;
			}
			else if (errCode == "PWS") //Petri dish Wrong Strructure
			{
				std::cout << "В файле присутствует неправильная разметка поля.\n";
				int retry = -1;
				while (retry != 0 && retry != 1)
				{
					std::cout << "Очистить файл?\n"\
						"Для очистки введите 1\n"\
						"Для завершения работы программы 0\n"\
						"Ваш выбор: ";
					std::cin >> retry;
				}
				if (retry)
				{
					RemakeOutFile();
					continue;
				}
				exit(0);

			}
			exit(0);
		}
	}
}

std::array<std::array<int, 21>, 21> Simulate(std::array<std::array<int, 21>, 21> now)
{
	std::array<std::array<int, 21>, 21> future;
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 21; y++)
		{
			int neighbours = 0;
			if (x != 0 && now[x - 1][y] != 0) neighbours++;
			if (x != 20 && now[x + 1][y] != 0) neighbours++;
			if (y != 0 && now[x][y-1] != 0) neighbours++;
			if (y != 20 && now[x][y+1] != 0) neighbours++;
			
			if (spreadMode)
			{
				//Found when I fixed bugs.
				//It look pretty pretty interesting!
				if (neighbours >= 2)
				{
					int level = now[x][y];
					if (level == 12) future[x][y] = 0;
					else future[x][y] = level+1;
				}
				else
				{
					future[x][y] = 0;
				}
			}
			else
			{
				int level = now[x][y];
				if (neighbours >= 2 && level>0)
				{
					
					if (level == 12) future[x][y] = 0;
					else future[x][y] = level + 1;
				}
				else
				{
					future[x][y] = 0;
				}
			}
			
		}
	}
	return future;
}

void PrintExport(std::array<std::array<int, 21>, 21> dish, int gen)
{
	std::cout << "Текущее поколение: " << gen<<std::endl;
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 21; y++)
		{
			if (dish[x][y] > 0) std::cout << "\u001b[33m" << dish[x][y] << "\u001b[0m"<<'\t';
			else std::cout << dish[x][y] << '\t';
		}
		std::cout << '\n';
	}
}

std::string PrepareExport(std::array<std::array<int, 21>, 21> dish, int gen)
{
	std::string data;
	data = "Текущее поколение: " + std::to_string(gen) +"\n";
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 21; y++)
		{
			if (dish[x][y] > 0) data+= "\u001b[33m" + std::to_string(dish[x][y])+ "\u001b[0m" + '\t';
			else data+= std::to_string(dish[x][y])+ '\t';
		}
		data+= '\n';
	}
	return data;
}

void FileExport(std::array<std::array<int, 21>, 21> dish, int gen)
{
	std::fstream exporter("work.out", std::ios::app);
	if (exporter.is_open())
	{
		exporter << "Текущее поколение: " << gen << std::endl;
		for (int x = 0; x < 21; x++)
		{
			for (int y = 0; y < 21; y++)
			{
				exporter << dish[x][y] << '\t';
			}
			exporter << '\n';
		}
		exporter.close();
	}
	else
	{
		exporter.close();
		std::cout << "Произошла ошибка при экспорте. Завершение работы!";
		exit(0);
	}
	
}

void AskToFill()
{
	std::cout << "Только что была создана новая конфигурация файла work.out.\n"\
		"Рекомендуется закрыть программу и заполнить входные данные.\n"\
		"Закрыть файл?\n";
	int state = -1;
	while (state != 1 && state != 0)
	{
		std::cout << "Для закрытия программы введите 0.\n"\
			"Для продолжения работы введите 1\n"\
			"Ваш выбор: ";
		std::cin >> state;
	}
	if (!state) exit(0);
}

void ShowImported(std::vector<char> imported)
{
	std::cout << "Импортированные штаммы: ";
	for (char c: imported)
	{
		std::cout << c << " ";
	}
	std::cout << std::endl;
}

void CreateStatistics(std::array<std::array<int, 21>, 21> dish)
{
	int colonies = 0;
	for (std::array<int,21> arr : dish)
	{
		for (int pos : arr)
		{
			if (pos > 0) colonies++;
		}
	}
	std::cout << "В данной иттерации колоний выжило: " << colonies<<std::endl;
	if (colonies == 0)
	{
		std::cout << "Симуляци дальше не имеет смысла, т.к. колоний больше нет";
		exit(0);
	}
}

bool AskSpreading()
{
	std::cout << "\n\nВключить симуляция распространения?\n";
	int answer = -1;
	while (answer != 0 && answer != 1)
	{
		std::cout << "Для включения распространения введите 1.\n"\
			"Для симуляции без распространения введите 0.\n"\
			"Ваш выбор: ";
		std::cin >> answer;
	}
	if (answer) return true;
	return false;
}

bool AskNewUI()
{
	int answer = -1;
	while (answer != 0 && answer != 1)
	{
		std::cout << "Использовать новый UI? [0/1] ";
		std::cin >> answer;
	}
	if (answer) return true;
	return false;
}

void DrawSimulation(std::array<std::array<int, 21>, 21> dish)
{
	HDC device_context = GetDC(console);
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 21; y++)
		{
			HPEN pen = CreatePen(PS_SOLID, 10, RGB(20*dish[x][y], 20 * dish[x][y], 20 * dish[x][y]));
			SelectObject(device_context, pen);
			Rectangle(device_context, y*20, 50 + (x*20), y*20+10, 50+(x*20+10));
			DeleteObject(pen);
			
		}
	}
	ReleaseDC(console, device_context);
}