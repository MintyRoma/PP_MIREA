#include <iostream>
#include <vector>
int balls;

void NextItteration(int stop);
bool Check();
std::vector<int> available;
std::vector<int> constructed;
int combos = 0;
int main()
{
	setlocale(0, "");
	std::cout << "Введите число шариков: ";
	std::cin >> balls;
	
	for (int i = 1; i <= balls; i++)available.push_back(i);

	NextItteration(balls);
	std::cout << "Комбинаций: " <<combos;
}

void NextItteration(int stop)
{
	if (stop==0)
	{
		bool status = Check();
		if (status) std::cout << "\u001b[33m";
		for (int c : constructed) std::cout << c;
		if (status) std::cout << "\u001b[0m";
		std::cout<<std::endl;
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