#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

enum CheckResult
{
	AisEarlier,
	BisEarlier,
	Same
};

std::vector<std::string> QuickSort(std::vector<std::string> data);
CheckResult CheckWords(std::string A, std::string B);
