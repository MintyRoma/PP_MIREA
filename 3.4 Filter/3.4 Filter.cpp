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
            for (char c : buffer)
            {
                if (c == '.' && cont)
                {
                    std::cout << c;
                    continue;
                }
                if (std::isdigit(c))
                {
                    if (cont)
                    {
                        std::cout << c;
                    }
                    if (!cont)
                    {
                        std::cout << std::endl<<c;
                        cont = true;
                    }
                    
                }
                else
                {
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