#include <iostream>
#include <string>

int DefineNumber(char num);

int main()
{
    setlocale(0, "");
    std::string buffer;
    std::cin >> buffer;
    int result = 0;
    for (int i = 0; i < buffer.length(); i++)
    {
        if (i == buffer.length() - 1)
        {
            int stack = DefineNumber(buffer[i]);
            if (stack < result || i == 0)
            {
                result += stack;
                i++;
            }
            else
            {
                std::cout << "Неверная последовательность";
                exit(0);
            }
            continue;
        }
        if (DefineNumber(buffer[i]) < DefineNumber(buffer[i + 1]))
        {
            int stack = (DefineNumber(buffer[i + 1]) - DefineNumber(buffer[i]));
            if (stack < result || i == 0)
            {
                result += stack;
                i++;
            }
            else
            {
                std::cout << "Неверная последовательность";
                exit(0);
            }
        }
        else
        {
            result += DefineNumber(buffer[i]);
        }
    }
    std::cout << result;
}

int DefineNumber(char num)
{
    switch (num)
    {

    case 'M':
        return 1000;
        break;

    case 'D':
        return 500;
        break;

    case 'C':
        return 100;
        break;

    case 'L':
        return 50;
        break;

    case 'X':
        return 10;
        break;

    case 'V':
        return 5;
        break;

    case 'I':
        return 1;
        break;

    default:
        std::cout << "Не верное число";
        exit(0);
        break;
    }
}