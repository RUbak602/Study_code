// Программа реализует проверку на закрытые скобки используя стек
//

#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::cin;
using std::string;

void bracetCompiler(string str)
{
	std::string::iterator iterStr = str.begin();
	std::stack<char> BraStack;
	std::stack<std::string::iterator> iterStack;
	int counter = 0;
	char top;
	bool wrongBra = false;

	for (char x : str)
	{
		++iterStr;
		if ((x == '(') || (x == '[') || (x == '{'))
		{
			BraStack.push(x);
			iterStack.push(iterStr);
		}
		if ((x == ')') || (x == ']') || (x == '}'))
		{
			if (BraStack.empty())
			{
				
				cout << iterStr - str.begin();
				return;
			}
			top = BraStack.top();

			if (((top == '(') && (x != ')')) || ((top == '[') && (x != ']')) || ((top == '{') && (x != '}')))
			{
				cout << iterStr - str.begin();
				return;
			}
			BraStack.pop();
			iterStack.pop();
		}


	}
	if (BraStack.empty())
		cout << "Success";
	else
		cout << iterStack.top() - str.begin();
	return;
}
int main()
{
	string str;
	std::getline(cin, str);
	bracetCompiler(str);
}

