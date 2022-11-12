#include <iostream>
#include <vector>
#include <chrono>
int balls;

void NextItteration(int stop);
bool Check();
bool debug = true;
std::vector<int> available;
std::vector<int> constructed;
int combos = 0;
int main()
{
	setlocale(0, "");
	std::cout << "Введите число шариков: ";
	std::cin >> balls;
	
	for (int i = 1; i <= balls; i++)available.push_back(i);
	if (balls > 7)
	{
		int ask = -1;
		while (ask != 0 && ask != 1)
		{
			std::cout << "\u001b[31mКоличество шариков очень большое, рекомендуется отключить дебаг вывод.\u001b[0m\n" <<
				"\u001b[31mРассчет последовательности может занять до нескольких минут!\u001b[0m\n"<<
				"Для отключения вывода напишите 0\n"<<
				"Чтобы оставить вывод комбинаций напишите 1\n"<<
				"Ваш выбор: ";
			std::cin >> ask;
		}
		if (ask == 1)debug = true;
		else debug = false;
	}
	std::chrono::system_clock::time_point AlgoStart = std::chrono::system_clock::now();
	NextItteration(balls);
	std::chrono::duration<double> AlgoTime = std::chrono::system_clock::now() - AlgoStart;
	std::cout << "Комбинаций: " <<combos<<std::endl;
	std::cout<<"Затрачено времени: "<< AlgoTime.count() << " secs." << std::endl;
}

void NextItteration(int stop)
{
	if (stop==0)
	{
		bool status = Check();
		if (debug) {
			if (status) std::cout << "\u001b[33m";
			for (int c : constructed) std::cout << c<<" ";
			if (status) std::cout << "\u001b[0m";
			std::cout<<std::endl;
		}
		return;
	}
	for (int i = 0; i < stop; i++)
	{
		int data = available[i];
		available.erase(available.begin()+i);
		constructed.push_back(data);
		NextItteration(stop-1);
		available.insert(available.begin() + i, data);
		constructed.erase(constructed.begin() + constructed.size() - 1);
	}
}

bool Check()
{
	for (int i = 0; i < constructed.size(); i++)
	{
		if (i + 1 == constructed[i])
		{
			combos++;
			return true;
		}
	}
	return false;
}