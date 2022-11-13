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

	// std::vector<int> v1;
	// ft::vector<int> v2;
	// for (int i = 0; i < 10; i++)
	// {
	// 	int num = rand() % 10;
	// 	v1.push_back(num);
	// 	v2.push_back(num);
	// }

	// for (int i = 0; i < 10; i++)
	// {
	// 	std::cout << v1[i] << " " << v2[i] << std::endl;
	// }
	// std::cout << std::endl;
	// // std::cout << v2.size();
	// v1.resize(500);
	// v2.resize(500);
	// std::cout << v2.end() - v2.begin();
   const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	int count = 100000;
	srand(time(NULL));
	{
	//output test
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		std::vector<int>::iterator res_std = v1.insert(it, N);
		ft::vector<int>::iterator res_ft = v2.insert(its, N);
		if (*res_std != *res_ft)
		 	++err_count;
		if (res_std - v1.begin() != res_ft - v2.begin())
			++err_count;
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!std::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	}

	//std working
    std::vector<int> v1(N, M);
	for (int i = 0; i < count; ++i){
		v1.insert(v1.begin(), N);
	}
	
	//ft working 
	// ft::vector<int> v2(N, M);
	// for (int i = 0; i < count; ++i){
	// 	v2.insert(v2.begin(), N);
	// }


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