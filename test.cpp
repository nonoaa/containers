#include <stack>
#include "stack.hpp"
#include <vector>
#include <iterator>
#include <iostream>
#include "vector.hpp"
#include <string>
#include "map.hpp"
#include <map>
#include <memory>
#include <queue>
#include "utilities.hpp"

using namespace std;
int _ratio = 100;

#define _is_integral ft::is_integral
#define _vector ft::vector

bool iterator_traits_test() {
	std::vector<string> res;
	std::vector<string> res2;

	res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::iterator::reference).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());

	res2.push_back(typeid(_vector<int>::iterator::iterator_category).name());
	res2.push_back(typeid(_vector<int>::iterator::value_type).name());
	res2.push_back(typeid(_vector<int>::iterator::difference_type).name());
	res2.push_back(typeid(_vector<int>::iterator::iterator_type).name());
	res2.push_back(typeid(_vector<int>::iterator::pointer).name());
	res2.push_back(typeid(_vector<int>::iterator::reference).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::iterator_category).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::value_type).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::difference_type).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::pointer).name());
	res2.push_back(typeid(_vector<int>::reverse_iterator::reference).name());

    for (int i = 0; i < res.size(); i++)
    {
        cout << (res[i]==res2[i]);
    }
	return res == res2;
}

bool is_integral_test_() {
	std::vector<int> v;
	bool res = 1;
	(_is_integral<float>() == std::is_integral<float>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<int>() == std::is_integral<int>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<bool>() == std::is_integral<bool>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<char>() == std::is_integral<char>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<signed char>() == std::is_integral<signed char>()) ? 0 : res = 0;
	(_is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? 0 : res = 0;
	(_is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? 0 : res = 0;
	(_is_integral<char16_t>() == std::is_integral<char16_t>()) ? 0 : res = 0;
	(_is_integral<short>() == std::is_integral<short>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? 0 : res = 0;
	(_is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<long>() == std::is_integral<long>()) ? 0 : res = 0;
	(_is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<long long>() == std::is_integral<long long>()) ? 0 : res = 0;
    cout <<res;
	(_is_integral<unsigned long long>() == std::is_integral<unsigned long long>()) ? 0 : res = 0;
	return res;
}

typedef ft::map<char, float> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;

void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}


int main()
{
	_map	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;

	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
			ft_comp(mp, it1, it2);

	return (0);
	// std::map<int, int> m;
	// ft::map<int, int> fm;
	// std::vector<int> a = erase_test_3(m);
	// std::vector<int> b = erase_test_3(fm);

	// for (int i = 0 ; i < a.size(); i++)
	// {
	// 	cout << a[i] << endl;
	// 	cout << b[i] << endl;
	// 	cout << endl;
	// }

	return 0;
}