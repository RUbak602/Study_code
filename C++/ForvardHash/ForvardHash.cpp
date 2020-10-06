// ForvardHash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> dictinary(10000000);
    int iterations;
    int index;
    std::cin >> iterations;
    for (size_t i = 0; i < iterations; i++)
    {
        std::string command;
        std::cin >> command;
        if (command == "add")
        {
            std::cin >> index;
            std::cin >> dictinary[index];
            continue;
        }
        if (command == "find")
        {
            std::cin >> index;
            if (!dictinary[index].empty())
            {
                std::cout << dictinary[index] << std::endl;
            }
            else
                std::cout << "not found" << std::endl;
        }
        if (command == "del")
        {
            std::cin >> index;
            dictinary[index].clear();
        }
    }
}

