#include <iostream>
#include <vector>

int main()
{
	setlocale(0, "");
	int Num;
	std::cout << "Введите конечное число: ";
	std::cin >> Num;

	std::vector<int> order;

	for (int i = 2; i <= Num; i++) order.push_back(i);
	
	int index = 0;
	while (index!=order.size())
	{
		int reference = order[index];
		int remover = -1;
		for (int i=index+1;i<order.size();i++)
		{
			if (order[i] % reference == 0)
			{
				remover = i;
				break;
			}
		}
		if (remover != -1) 
		{
			order.erase(order.begin()+remover);
		}
		else
		{
			index++;
		}
	}

	for (int c : order) std::cout << c<<" ";
}
