#include <iostream>
#include <cmath>

#define point '@'
#define empty ' '
#define XO '-'
#define YO '|'
#define center '+'

void DrawSin(double scale);

int main()
{
	//setlocale(0,"");
	DrawSin(2.5);
}

void DrawSin(double scale)
{
	double startpoint = -2*scale;
	double endpoint = 2*scale;
	for (double Y = 2;Y>-2;Y-=0.25)
	{
		for (double X = startpoint; X < endpoint; X += 0.25)
		{
			double res = sin(X);
			//std::cout << res;
			if (std::sin(Y - 0.25) < res && std::sin(Y + 0.25) > res) std::cout << point;
			else if (X == 0 && Y == 0) std::cout << center;
			else if (X == 0) std::cout << YO;
			else if (Y == 0) std::cout << XO;
			else std::cout << empty;
		}
		std::cout << std::endl;
	}
}