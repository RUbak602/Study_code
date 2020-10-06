#pragma once
#ifndef 1
#include <iostream>
#include <vector>

class Heap
{
private:
    std::vector<int> arr;
public:
    Heap() {};
    ~Heap() {};
    void Insert(int value);
    void Extract();
    void ShiftUp();
    void ShiftDown();
};

void Heap::Insert(int value) 
{
    this.arr.push_back(value);
}
#endif // !1
