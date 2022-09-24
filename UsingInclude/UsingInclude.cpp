#include <iostream>
#include "UselessMathematic.h" //Без этого не пашет, я бы объяснил это на теме функций

int main()
{
	int A, B;
	std::cin >> A >> B;
	std::cout << Sum(B, A);
}