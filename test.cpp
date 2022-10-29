#include "stack.hpp"
#include <stack>
#include <vector>
#include <iostream>


int main()
{
	// std::stack<int> s;
	// s.push(5);

	// std::stack<int> a(s);
	// std::cout << a.top();

	// ft::stack<int> s;
	// s.push(5);

	// ft::stack<int> a(s);
	// // std::cout << a.top();

	// std::cout << (s == a) << (s > a);

	std::vector<int> a;
	std::vector<int> b;

	std::vector<int>::iterator iter1;
	std::vector<int>::iterator iter2;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	iter1 = a.begin();
	iter2 = a.end();

	std::cout << (iter2 - iter1);

	return 0;
}