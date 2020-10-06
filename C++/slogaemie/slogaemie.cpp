// Программа находит максимальное число k, для которого n можно представить как сумму k различных натуральных слагаемых.
#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> result;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if ((n - 1) > (i + 1))
            result.push_back(i);
        else
            result.push_back(n);
        n -= i;
    }
    std::cout << result.size() << std::endl;
    for (auto x : result)
    {
        std::cout << x << " ";
    }
    return 0;
}