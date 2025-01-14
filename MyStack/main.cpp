

#include "MyStack.hpp"
#include<iostream>
using namespace ds;

int main()
{
	MyStack<int> stack;
	std::cout << stack.empty() << '\n';
	stack.push(1);
	stack.push(2);
	stack.push(9);
	std::cout << stack.top()<<'\n';
	std::cout << stack.size() << '\n';
	stack.pop();
	std::cout << stack.top() << '\n';
	std::cout << stack.size() << '\n';
	std::cout << stack.empty() << '\n';

	return 0;
}
