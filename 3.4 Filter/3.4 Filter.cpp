#include <iostream>
#include <fstream>
#include <string>

int main()
{
    setlocale(0, "");
    std::ifstream filereader("Task.txt");
    if (filereader.is_open())
    {
        std::string buffer;
        while (std::getline(filereader, buffer))
        {
            bool cont=false;
            bool dot = false;
            for (char c : buffer)
            {
                if (c == '.' && cont)
                {
                    dot=true;
                    continue;
                }
                if (std::isdigit(c))
                {
                    if (cont)
                    {
                        if (dot) std::cout << ".";
                        std::cout << c;
                    }
                    if (!cont)
                    {
                        std::cout << "  " << c;
                        cont = true;
                    }
                    
                }
                else
                {
                    dot = false;
                    cont = false;
                }
            }
        }
    }
    else
    {
        std::cout << "Ошибка доступа к файлу";
    }
}