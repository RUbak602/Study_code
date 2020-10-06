// StackWithMax.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <deque>
#include<string>

class MaxStack
{
private:
	std::deque<int> current;
	std::deque<int> addetive;
public:
	void push(int value);
	void pop();
	int max();

};
void MaxStack::push(int value)
{
	current.push_back(value);
	if (addetive.empty())
		addetive.push_back(value);
	else
		addetive.push_back((value > addetive.back())? value: addetive.back());
}
void MaxStack::pop()
{
	current.pop_back();
	addetive.pop_back();
}
int MaxStack::max()
{
	return addetive.back();
}
int main()
{
	int _size;
	std::string command;
	MaxStack maxStack;
	std::cin >> _size;
	for (int i = 0; i < _size; ++i)
	{
		int value;
		std::cin >> command;
		if (command == "push")
		{
			std::cin >> value;
			maxStack.push(value);
		}
		else if (command == "pop")
		{
			maxStack.pop();
		}
		else if (command == "max")
		{
			std::cout << maxStack.max();
		}
	}
}