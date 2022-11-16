#include <iostream>

int main()
{
	setlocale(0, "");
	std::cout << "Введите ширину прямоугольника: ";
	int X;
	std::cin >> X;
	std::cout << "Введите высоту прямоугольника: ";
	int Y;
	std::cin >> Y;

	int checkX = 1;
	int checkY = 1;
	bool FirstIncremetation = false;
	int res = 0;
	while (checkX <= X && checkY <= Y)
	{
		int S = (Y - (checkY - 1))*(X - (checkX - 1));
		
		//DEBUG
		std::cout << "X: " << checkX << "\tY: " << checkY<<std::endl;
		std::cout << "Square: " << S << std::endl;
		std::cout<<"FI: "<<FirstIncremetation<<"\n==============================\n";
		
		//Binary Enumertaion Method
		if (checkY <= Y)
		{
			if (checkY == Y)
			{
				checkX++;
				checkY = 1;
			}
			else
			{
				checkY++;
			}
		}
		
		res += S;
	}
	std::cout << res;
}