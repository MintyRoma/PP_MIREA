#include <iostream>
#include <vector>

int main()
{
	setlocale(0, "");
	std::vector<int> heights;
	std::cout << "***Анализ роста учеников***"<<std::endl;
	std::cout << "Введите рост (см) и нажмите <Enter>."\
		"\nДля завершения введите 0 и нажмите <Enter>"<<std::endl;
	double buf;
	std::cin >> buf;
	while (buf != 0)
	{
		heights.push_back(buf);
		std::cin >> buf;
	}
	
	int anomaly = 0;
	double Avg=0;
	for (int j : heights)
	{
		Avg += j;
	}
	Avg /= heights.size();

	for (int j : heights)
	{
		if (j > Avg) anomaly++;
	}

	std::cout << "Средний рост: " << Avg << "см."<<std::endl;
	std::cout << "У " << anomaly << " человек рост превышает средний.";
		
}