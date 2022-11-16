#include <iostream>

int main()
{
	setlocale(0, "");
	std::cout << "Введите количество сидений: ";
	int seats;
	std::cin >> seats;
	std::cout << "Введите количество школьников: ";
	int schoolars;
	std::cin >> schoolars;
	//Seats Gen
	int* places = new int[seats+2];
	places[0] = 1;
	places[seats + 1] = 1;
	for (int i = 1; i <= seats; i++) places[i] = 0;
	for (int i = 0; i <= seats + 1; i++) std::cout;

	int start = 0;
	int stop = 0;
	int addition = 0;
	int range = 0;

	for (int i = 0; i < schoolars; i++)
	{
		start = 0;
		stop = 0;
		int buf_start;
		int buf_stop;
		for (int i = 1; i <= seats + 1; i++)
		{
			if (places[i] == 0 && places[i - 1] == 1)
			{
				buf_start = i;
				buf_stop = i;
			}
			else if (places[i] == 1 && places[i - 1] == 0)
			{
				buf_stop = i;
				std::cout << "Now indexes are - S: " << buf_start << "E: " << buf_stop<<std::endl;
			}
			if (buf_stop - buf_start > stop - start)
			{
				start = buf_start;
				stop = buf_stop;
			}

		}
		//Take Place
		range = stop - start-1;
		addition = range / 2;
		places[start + addition] = 1;
		std::cout << "\nPlace: " << start + addition<<std::endl;
		std::cout << "Indexes \t Start: " << start << "\tEnd: " << stop<<std::endl;
		for (int i = 0; i <= seats + 1; i++) std::cout << places[i];
		std::cout << "\n=========================\n";
		
	}
	
	std::cout << "Слева: " << addition <<std::endl;
	std::cout << "Справа: " << range-addition;
}