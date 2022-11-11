#include <stack>
#include "stack.hpp"
#include <vector>
#include <iterator>
#include <iostream>
#include "vector.hpp"
#include <string>

#include <memory>

// using namespace std;

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
	// std::vector<int> a(5, 5);
	// std::vector<int> c(3);
	// std::vector<char> b(3, 'a');

	// a.swap(c);

	// std::vector<int> a;
	// a.push_back(1);
	// a.push_back(2);

	// a.erase(a.end());

	ft::vector<std::string> b(10);
	for (unsigned long int i = 0; i < b.size(); ++i)
		b[i] = std::string((b.size() - i), i + 65);

	for (int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << std::endl;
	}

	std::cout << std::endl;
	b.erase(b.end() - 1);
	for (int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << std::endl;
	}


	// ft::random_access_iterator<T> == ft::vector<T>::iterator



	// std::iterator_traits<ft::random_access_iterator<int> >::value_type;
	// std::iterator_traits<std::vector<int>::iterator>::value_type;

	// std::iterator_traits<ft::vector<int>::iterator>::value_type;
	// ft::iterator_traits<ft::vector<int>::iterator>::value_type;

	// ft::iterator_traits<std::vector<int>::iterator>::value_type;


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