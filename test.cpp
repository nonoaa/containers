#include "stack.hpp"
#include <stack>
#include <iostream>

int main()
{
	// std::stack<int> s;
	// s.push(5);

	// std::stack<int> a(s);
	// std::cout << a.top();



	ft::stack<int> s;
	s.push(5);

	ft::stack<int> a(s);
	// std::cout << a.top();

	std::cout << (s == a) << (s > a);

	return 0;
}