#pragma once

std::vector<char> ImportCharsetLibrary();

std::array<std::array<int, 21>, 21> ImportPetriDish(std::vector<char> charsetLibrary);

void RemakeOutFile();

int GetGenerations();

std::vector<char> GetCharsetLibrary();

std::array<std::array<int, 21>, 21> GetPetriDish(std::vector<char> charsetLibrary);

std::array<std::array<int, 21>, 21> Simulate(std::array<std::array<int, 21>, 21> now);

void PrintExport(std::array<std::array<int, 21>, 21> dish, int gen);

void FileExport(std::array<std::array<int, 21>, 21> dish, int gen);

void AskToFill();

void ShowImported(std::vector<char> imported);

void CreateStatistics(std::array<std::array<int, 21>, 21> dish);

bool AskSpreading();
