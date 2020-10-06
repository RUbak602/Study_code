// Данная программа находит высоту дерева
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>

void HightThree(int root,int & counter, std::map<int, int> & three, const std::vector<int> &arr)
{
	counter += 1;
	int temp = arr[root];
	if (temp == -1)
		return;
	else
		HightThree(temp,counter, three, arr);
}
int main()
{
	int _size;
	std::cin >> _size;
	std::vector<int> arr(_size);
	std::map<int, int> _map;
	std::priority_queue<int> result;
	int counter;
	for (int i = 0; i < _size; ++i)
		std::cin >> arr[i];
	for (int i = 0; i < _size; ++i)
	{
		counter = 1;
		if (arr[i] == -1)
		{
			_map.emplace(i, 1);
			continue;
		}
		
			_map.emplace(i, 0);
			HightThree(arr[i], counter, _map, arr);
			_map[i] = counter;
			if (i == 0)
				result.push(_map[i]);
			else
				result.push( (_map[i] > _map[i- 1]) ? _map[i] : _map[i - 1]);
		

	}
	std::cout << result.top();
}