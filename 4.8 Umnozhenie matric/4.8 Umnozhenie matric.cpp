#include <iostream>
#include <iomanip>

#define price 0
#define tax 1

int main()
{
	setlocale(0, "");
	int SellersInfo[3][4] = {
		{5,2,0,10},
		{3,5,2,5},
		{20,0,0,0}
	};

	double ItemsInfo[4][2] =
	{
		{1.20,0.50},
		{2.80,0.40},
		{5.0,1.0},
		{2.0,1.5}
	};

	double TotalInfo[3][2];

	for (int seller = 0; seller < 3; seller++)
	{
		double sellerstotal = 0;
		double taxtotal = 0;
		for (int product = 0; product < 4; product++)
		{
			sellerstotal += SellersInfo[seller][product] * ItemsInfo[product][price];
			taxtotal += SellersInfo[seller][product] * ItemsInfo[product][tax];
		}
		TotalInfo[seller][price]=sellerstotal;
		TotalInfo[seller][tax] = taxtotal;
	}

	std::cout << "Результат перемножения матриц:\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::setw(8) << TotalInfo[i][price] << std::setw(8) << TotalInfo[i][tax]<<std::endl;
	}

	int maxsum = 0;
	int minsum = 0;
	int maxtax = 0;
	int mintax = 0;
	double summarynotax = 0;
	double sumarytax = 0;

	for (int i = 0; i < 3; i++)
	{
		if (TotalInfo[maxsum][price] < TotalInfo[i][price]) maxsum = i;
		if (TotalInfo[minsum][price] > TotalInfo[i][price])minsum = i;
		if (TotalInfo[maxtax][tax] < TotalInfo[i][tax]) maxtax = i;
		if (TotalInfo[mintax][tax] > TotalInfo[i][tax])mintax = i;
		summarynotax += TotalInfo[i][price];
		sumarytax += TotalInfo[i][tax];
	}

	std::cout << "Максимальная прибыль у продавца " << maxsum+1 << std::endl <<
		"Минимальная прибыль у продавца " << minsum+1 << std::endl <<
		"Максимальные комиссионные у продавца " << maxtax+1 << std::endl <<
		"Минимальные комиссионные у продавца " << mintax+1 << std::endl <<
		"Суммарная выручка:" << summarynotax << std::endl <<
		"Суммарные комиссионные:" << sumarytax << std::endl <<
		"Общая прибыль:" << summarynotax - sumarytax;
}