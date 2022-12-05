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

using namespace std;
int _ratio = 100;

template <class T, class V>
std::vector<int> assign_overload_test(std::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 10; i < 20 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    std::map<T, V> mp2;
    for (int i = 20 * _ratio, j = 200010; i < 40 * _ratio; ++i, ++j)
        mp2.insert(std::make_pair(i, j));
    mp2 = mp;
    typename std::map<T, V>::iterator it = mp2.begin();
    for (; it != mp2.end(); it++) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    v.push_back(mp2.size());
    return v;
}

template <class T, class V>
std::vector<int> assign_overload_test(ft::map<T, V> mp) {
    std::vector<int> v;
    for (int i = 0, j = 10; i < 20 * _ratio; ++i, ++j)
        mp.insert(ft::make_pair(i, j));
    ft::map<T, V> mp2;
    for (int i = 20 * _ratio, j = 200010; i < 40 * _ratio; ++i, ++j)
        mp2.insert(ft::make_pair(i, j));
    mp2 = mp;
    typename ft::map<T, V>::iterator it = mp2.begin();
    for (; it != mp2.end(); it++) {
        v.push_back(it->first);
        v.push_back(it->second);
    }
    v.push_back(mp2.size());
    return v;
}


int main()
{
	std::map<int, int> m;
	ft::map<int, int> fm;
	std::vector<int> a = assign_overload_test(m);
	std::vector<int> b = assign_overload_test(fm);

	for (int i = 0 ; i < a.size(); i++)
	{
		cout << a[i] << endl;
		cout << b[i] << endl;
		cout << endl;
	}

	return 0;
}