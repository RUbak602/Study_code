// Данная программа прденазаначена для посторения очереди с приоритеотом, на основе двоичной макс-кучи
//

#include <iostream>
#include <vector>


class Heap
{
private:
    int _size = 0;
    std::vector<int> arr{-1};
    
public:
    Heap() {};
    ~Heap() {};
    int getParent(int i);
    int getChildLeft(int i);
    int getChildRight(int i);
    void Insert(int value);
    int ExtractMax();
    void SiftUp(int i);
    void SiftDown(int i);
    void ShowHeap();
};
int Heap:: getParent(int i)
{
    return i / 2;
}
int Heap::getChildLeft(int i)
{
    return 2 * i;
}
int Heap::getChildRight(int i)
{
    return 2 * i + 1;
}
void Heap::Insert(int value)
{
    if (_size + 1 >= arr.size())
        arr.push_back(0);
    arr[++_size] = value;
    SiftUp(_size);
}
//Просеивание вверх
void Heap::SiftUp(int i)
{
    if (i > _size)
        return;
    if (i == 1)
        return;
    if (arr[i] > arr[getParent(i)])
    {
        std::swap( arr[getParent(i)], arr[i]);
    }
    SiftUp(getParent(i)); // можно заменить рекурсию циклом while
    
}
// Просеивание вниз
void Heap::SiftDown(int i)
{
    if (i > _size)
        return;
    int swapId = i;
    if (getChildLeft(i) <= _size && arr[i] < arr[getChildLeft(i)])
        swapId = getChildLeft(i);
    if (getChildRight(i) <= _size && arr[swapId] < arr[getChildRight(i)])
        swapId = getChildRight(i);
    if (swapId != i)
    {
        std::swap(arr[i], arr[swapId]);
        SiftDown(swapId); // можно заменить рекурсию циклом while
    }
    return;
}
int Heap::ExtractMax()
{
    int MaxValue = arr[1];
    std::swap(arr[1], arr[_size--]);
    SiftDown(1);
    return MaxValue;
}
void Heap::ShowHeap()
{
    std::cout << "Heap: " << std::endl;
    for (int i = 1; i < _size+1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    Heap* MyHeap = new Heap();
    MyHeap->Insert(100);
    MyHeap->Insert(12);
    MyHeap->Insert(44);
    MyHeap->Insert(120);
    MyHeap->ShowHeap();
    std::cout << " Extract "<< MyHeap->ExtractMax() << std::endl;
    MyHeap->ShowHeap();
    std::cout << MyHeap->ExtractMax() << std::endl;
    MyHeap->ShowHeap();
    std::cout << MyHeap->ExtractMax() << std::endl;
    MyHeap->ShowHeap();
    return 0;
}