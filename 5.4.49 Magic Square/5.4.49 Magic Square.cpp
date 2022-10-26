#include <iostream>

int main()
{
	setlocale(0, "");
	int size;
	std::cout << "Введите размерность матрицы: ";
	std::cin >> size;

	double** MatrixADR = new double* [size];
	for (int i = 0; i < size; i++)
	{
		MatrixADR[i] = new double[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cin >> MatrixADR[i][j];
		}
	}

	bool magic = true;

	double reference = 0;


	//Проверка строк
	for (int row = 0; row < size; row++)
	{
		double now = 0;
		for (int col = 0; col < size; col++)
		{
			now += MatrixADR[row][col];
		}
		if (reference == 0) reference = now;
		if (reference != now)
		{
			magic = false;
		}
	}

	//Проверка столбцов
	if (magic)
	{
		for (int col = 0; col < size; col++)
		{
			double now = 0;
			for (int row = 0; row < size; row++)
			{
				now += MatrixADR[row][col];
			}
			if (reference != now)
			{
				magic = false;
			}
		}
	}

	//Проверка диагонали
	if (magic)
	{
		double nowDiag = 0;
		for (int diag = 0; diag < size; diag++)
		{
			nowDiag += MatrixADR[diag][diag];
			
		}
		if (reference != nowDiag)
		{
			magic = false;
		}
	}

	//Проверка обратной диагонали
	if (magic)
	{
		double nowRDiag = 0;
		for (int diag = 0; diag < size; diag++)
		{
			int x = size - diag-1;
			nowRDiag += MatrixADR[x][diag];

		}
		if (reference != nowRDiag)
		{
			magic = false;
		}
	}

	if (magic) std::cout << "Квадрат магический!!!";
	else std::cout << "Магия не удалась...";

	for (int i = 0; i < size; i++)
	{
		delete[]MatrixADR[i];
	}
}