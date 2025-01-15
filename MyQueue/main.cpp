// MyQueue.cpp: 定义应用程序的入口点。
//

#include "MyQueue.hpp"
#include<iostream>
using namespace ds;

int main()
{
	MyQueue<int> Queue;
	std::cout << Queue.empty() << '\n';
	Queue.push(3);
	Queue.push(6);
	Queue.push(9);
	std::cout << Queue.front() << '\n';
	std::cout << Queue.back() << '\n';
	std::cout << Queue.size() << '\n';
	Queue.pop();
	std::cout << Queue.front() << '\n';
	std::cout << Queue.back() << '\n';
	std::cout << Queue.size() << '\n';
	std::cout << Queue.empty() << '\n';

	return 0;
}
