#include <iostream>
#include <vector>
int balls;

void NextItteration(int stop);
bool Check();
void Construct(int leftHand,int rightHand);
void mainConstruct(int size);
void ConstructRight(int size);
void CheckV2();
void PrintVector();

bool debug = true;
int inService = 0;
std::vector<int> available;
std::vector<int> constructed;

std::vector<int> Left;
std::vector<int> Right;
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
	for (int i = 0; i < balls; i++)
	{
		inService = available[i];
		available.erase(available.begin() + i);
		NextItteration(balls - 1);
		available.insert(available.begin() + i, inService);
	}
	std::cout << "Комбинаций: " <<combos;
}

void PrintVector()
{
	std::cout << "[";
	for (int i = 0; i < inService-1;i++) std::cout << constructed[i] << " ";
	std::cout << "] " << inService << "[ ";
	for (int i = inService-1; i <= constructed.size()-1; i++) std::cout << constructed[i] << " ";
	std::cout << "]"<<std::endl;
}
void NextItteration(int stop)
{
	if (stop==0)
	{
		bool status = Check();
		if (debug && status) PrintVector();
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
	for (int i = 0; i < inService-1; i++) if (i + 1 == constructed[i]) return false;
	combos++;
	return true;
}