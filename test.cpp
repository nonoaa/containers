#include "stack.hpp"
#include <stack>
#include <vector>
#include <iostream>

#include <memory>

using namespace std;

int main()
{
	// stack

	// std::stack<int> s;
	// s.push(5);

	// std::stack<int> a(s);
	// std::cout << a.top();

	// ft::stack<int> s;
	// s.push(5);

	// ft::stack<int> a(s);
	// // std::cout << a.top();

	// std::cout << (s == a) << (s > a);


	// vector
	vector<int> a;
	a.reserve(10);
	a.reserve(20);
	a.reserve(15);

	cout << a.capacity() << endl;

	// a[2] = 5;
	// cout << a[2]<<" " <<a.capacity();

	// std::vector<int>::iterator iter1;
	// std::vector<int>::iterator iter2;

	// a.push_back(1);
	// a.push_back(2);
	// a.push_back(3);

	// iter1 = a.begin();
	// iter2 = a.end();

	// std::cout << (iter2 - iter1);

	

	return 0;
}