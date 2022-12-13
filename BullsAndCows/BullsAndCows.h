#pragma once
#include<fstream>

std::vector<int> PrepareGame();

std::vector<int> ReadInput(int step);

bool Check(std::vector<int> board, std::vector<int> userInput);
