// Данная программа для n отрезков находит множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек
//Stepic Жадные алгоритмы
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

std::vector<int> get_covering_set(std::vector <Segment> segments) {
    std::vector <int> result;
    //bool cdd; // flag common detected in compare vectors
    int indexActualEnd = 0;
    
    // Сортировка по концам отрезков
    std::sort(segments.begin(), segments.end(), [](Segment x, Segment y) {return (x.second < y.second); });
    // Добавление первого надежного шага жадного алгоритма
    result.push_back(segments[0].second);
    for (unsigned int i = 1; i < segments.size(); ++i)
    {
        //cdd = false;

        if (segments[i].first <= result[indexActualEnd])
        {
            continue;
        }
        else
        {
            ++indexActualEnd;
            result.push_back(segments[i].second);
        }
            
    }

    return result;
}

int main(void) {
    int segments_count;
    std::cout << "Enter count of segments: ";
    std::cin >> segments_count;
    std::cout << std::endl;
    std::vector <Segment> segments(segments_count);
    for (auto& s : segments) {
        std::cout << "Enter pair dots (use int and space): ";
        std::cin >> s.first >> s.second;
        std::cout << std::endl;
    }

    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point : points) {
        std::cout << point << " ";
    }
    std::cout << std::endl;
}