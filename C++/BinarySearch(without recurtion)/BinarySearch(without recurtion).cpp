//Программа реализует двоичный поиск в массиве чисел
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int>& numbers, int keyValue) {
    int beginSearch = 1;
    int endSearch = numbers.size();
    int currentSearch;
    while (beginSearch <= endSearch)
    {
        currentSearch = (beginSearch + endSearch) / 2;
        if (numbers[currentSearch] == keyValue)
            return currentSearch;
        else if (numbers[currentSearch] > keyValue)
        {
            endSearch = currentSearch - 1;
            continue;
        }
        else
        {
            beginSearch = currentSearch + 1;
            continue;
        }
      
    }
    return -1;
}

int main(void) {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers{-999};
    int number;
    for (int i = 0; i < number_count; ++i) {
        std::cin >> number;
        numbers.push_back(number);
    }
    std::cout << "Vector: ";
    for (int i = 0; i < number_count +1; ++i) {
        std::cout << numbers[i]<<", ";
    }
    std::cout << std::endl;

    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << get_pos(numbers, number) << " ";
    }
    std::cout << std::endl;
}