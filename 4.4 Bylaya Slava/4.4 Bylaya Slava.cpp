#include <iostream>
#include <string>

#define star 'Ж'
#define empty '.'
#define stripe '#'
#define height 13
#define width (int) height*1.9*2

#define RED "\033[31m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define BLUEBACK "\033[44m"
#define RESETBACK "\033[40m"


void DrawStars(int row);
void DrawPattern(int row);

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