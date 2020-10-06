// Программа реализует построение двоичной мин-кучи
//
#include <iostream>
#include <vector>
#include <utility>


class MinHeap
{
private:
    int _size = 0;
    std::vector<int> arr{ -1 };
    std::vector<std::pair<int, int>> swapArr;

public:
    MinHeap() {};
    ~MinHeap() {};
    int getParent(int i);
    int getChildLeft(int i);
    int getChildRight(int i);
    void Insert(int value);
    int ExtractMax();
    void SiftUp(int i);
    void SiftDown(int i);
    void ShowHeap();
    void BuildHeap(std::vector<int> inArr);
    void ShowPairs();
};
int MinHeap::getParent(int i)
{
    return i / 2;
}
int MinHeap::getChildLeft(int i)
{
    return 2 * i;
}
int MinHeap::getChildRight(int i)
{
    return 2 * i + 1;
}
void MinHeap::Insert(int value)
{
    if (_size + 1 >= arr.size())
        arr.push_back(0);
    arr[++_size] = value;
    SiftUp(_size);
}
//Просеивание вверх
void MinHeap::SiftUp(int i)
{
    if (i > _size)
        return;
    if (i == 1)
        return;
    if (arr[i] < arr[getParent(i)])
    {
        std::swap(arr[getParent(i)], arr[i]);
    }
    SiftUp(getParent(i)); // можно заменить рекурсию циклом while

}
// Просеивание вниз
void MinHeap::SiftDown(int i)
{
    if (i > _size)
        return;
    int swapId = i;
    if (getChildLeft(i) <= _size && arr[i] > arr[getChildLeft(i)])
        swapId = getChildLeft(i);
    if (getChildRight(i) <= _size && arr[swapId] > arr[getChildRight(i)])
        swapId = getChildRight(i);
    if (swapId != i)
    {
        swapArr.emplace_back(i,swapId);
        std::swap(arr[i], arr[swapId]);
        SiftDown(swapId); // можно заменить рекурсию циклом while
    }
    return;
}
int MinHeap::ExtractMax()
{
    int MaxValue = arr[1];
    std::swap(arr[1], arr[_size--]);
    SiftDown(1);
    return MaxValue;
}
void MinHeap::ShowHeap()
{
    std::cout << "Heap: " << std::endl;
    for (int i = 1; i < _size + 1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}
void MinHeap::BuildHeap(std::vector<int> inArr)
{
    _size = inArr.size();
    for (auto x : inArr)
        arr.push_back(x);
    for (int i = (_size ) / 2; i > 0; --i)
        SiftDown(i);
}
void MinHeap::ShowPairs()
{
    std::cout << swapArr.size() << std::endl;
    if (swapArr.size())
    {
        for (auto x : swapArr)
        {
            std::cout << x.first -1 << " " << x.second -1 << std::endl;
        }
    }
    
}


int main()
{
    MinHeap* MyHeap = new MinHeap();
    int size;
    std::cin >> size;
    std::vector<int> inArr(size);
    for (int i = 0; i < size; i++)
        std::cin >> inArr[i];
    MyHeap->BuildHeap(inArr);
    MyHeap->ShowPairs();
    //MyHeap->ShowHeap();
    
    return 0;
}