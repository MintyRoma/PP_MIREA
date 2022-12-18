#pragma once
#include <iostream>
#include <vector>
#include <chrono>
int balls;

void NextItteration(int stop);

bool Check();
bool debug = true;
std::vector<int> available;
std::vector<int> constructed;
int combos = 0;