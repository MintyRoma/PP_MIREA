#include "4.4 Bylaya Slava.h"


int main()
{
	setlocale(0, "");
	for (int i = 0; height > i; i++)
	{
		DrawStars(i);
		DrawPattern(i);
		std::cout << WHITE<<std::endl;
	}
}

void DrawStars(int row)
{
	if (row < 7)
	{
		std::cout << BLUEBACK;
		for (int sym = 0; sym < 16; sym++)
		{
			if (sym%2==0) std::cout <<WHITE << star;
			else std::cout <<BLUE << empty;
		}
	}
	return;
}

void DrawPattern(int row)
{
	std::cout << RESETBACK;
	int rowsize = (int) width;
	if (row < 7) rowsize -= 16;
	if (row % 2 == 0)
	{
		for (int sym = 0; sym < rowsize; sym++) std::cout <<RED<<stripe;
	}
	else
	{
		for (int sym = 0; sym < rowsize; sym++) std::cout << WHITE << stripe;
	}
}