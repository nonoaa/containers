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
#include "set.hpp"
#include <set>

using namespace std;
int _ratio = 100;

#define _is_integral ft::is_integral
#define _vector ft::vector
#define _set ft::set
template <class T, class C>
void fillSet(std::set<T, C> &mp) {
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	// mp.insert(19);
	// mp.insert(29);
	// mp.insert(41);
	// mp.insert(4);
	// mp.insert(11);
}

template <class T, class C>
void fillSet(_set<T, C> &mp) {
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	// mp.insert(19);
	// mp.insert(29);
	// mp.insert(41);
	// mp.insert(4);
	// mp.insert(11);
}
template <class T>
std::vector<int> comparator_test(std::set<T> st) {

	std::vector<int> v;
	fillSet(st);
	for (typename std::set<T>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
	v.push_back(9999);
	// std::set<int, std::greater<int> > st1;
	// fillSet(st1);
	// v.push_back(*(st1.begin()));
	// st1.erase(16);
	// v.push_back(*(st1.begin()));
	// st1.erase(23);
	// v.push_back(*(st1.begin()));
	// std::set<int, std::greater<int> > st2;
	// st2.insert(3);
	// v.push_back(*(st2.begin()));
	// st2.erase(3);
	// if (st2.begin() == st2.end())
	//     v.push_back(1);
	// std::set<int, std::plus<int> > st3;
	// fillSet(st3);
	// for (typename std::set<T>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
	std::set<int, std::minus<int> > st4;
	fillSet(st4);
	for (typename std::set<T>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
	// std::set<int, std::greater_equal<int> > st5;
	// fillSet(st5);
	// for (typename std::set<T>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
	// v.push_back(9999);
	// std::set<int, std::multiplies<int> > st6;
	// fillSet(st6);
	// for (typename std::set<T>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
	// std::set<int, std::bit_xor<int> > st7;
	// fillSet(st7);
	// for (typename std::set<T>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
	// std::set<int, std::logical_and<int> > st8;
	// fillSet(st8);
	// for (typename std::set<T>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }
	// v.push_back(st1.size());
	return v;
}

template <class T>
std::vector<int> comparator_test(_set<T> st) {
	std::vector<int> v;
	fillSet(st);
	for (typename _set<T>::iterator it = st.begin(); it != st.end(); it++) { v.push_back(*it); }
	// for (typename _set<T>::iterator it = --st.end(); it != st.begin(); it--) { v.push_back(*it); }
	v.push_back(9999);
	// _set<int, std::greater<int> > st1;
	// fillSet(st1);
	// v.push_back(*(st1.begin()));
	// st1.erase(16);
	// v.push_back(*(st1.begin()));
	// st1.erase(23);
	// v.push_back(*(st1.begin()));
	// _set<int, std::greater<int> > st2;
	// st2.insert(3);
	// v.push_back(*(st2.begin()));
	// st2.erase(3);
	// if (st2.begin() == st2.end())
	//     v.push_back(1);
	// _set<int, std::plus<int> > st3;
	// fillSet(st3);
	// for (typename _set<T>::iterator it = st3.begin(); it != st3.end(); it++) { v.push_back(*it); }
	// for (typename _set<T>::iterator it = --st3.end(); it != st3.begin(); it--) { v.push_back(*it); }
	_set<int, std::minus<int> > st4;
	fillSet(st4);
	for (typename _set<T>::iterator it = st4.begin(); it != st4.end(); it++) { v.push_back(*it); }
	// for (typename _set<T>::iterator it = --st4.end(); it != st4.begin(); it--) { v.push_back(*it); }
	// _set<int, std::greater_equal<int> > st5;
	// fillSet(st5);
	// for (typename _set<T>::iterator it = st5.begin(); it != st5.end(); it++) { v.push_back(*it); }
	// for (typename _set<T>::iterator it = --st5.end(); it != st5.begin(); it--) { v.push_back(*it); }
	// v.push_back(9999);
	// _set<int, std::multiplies<int> > st6;
	// fillSet(st6);
	// for (typename _set<T>::iterator it = st6.begin(); it != st6.end(); it++) { v.push_back(*it); }
	// for (typename _set<T>::iterator it = --st6.end(); it != st6.begin(); it--) { v.push_back(*it); }
	// _set<int, std::bit_xor<int> > st7;
	// fillSet(st7);
	// for (typename _set<T>::iterator it = st7.begin(); it != st7.end(); it++) { v.push_back(*it); }
	// for (typename _set<T>::iterator it = --st7.end(); it != st7.begin(); it--) { v.push_back(*it); }
	// std::set<int, std::logical_and<int> > st8;
	// fillSet(st8);
	// for (typename std::set<T>::iterator it = st8.begin(); it != st8.end(); it++) { v.push_back(*it); }
	// for (typename std::set<T>::iterator it = --st8.end(); it != st8.begin(); it--) { v.push_back(*it); }
	// v.push_back(st1.size());

	return v;
}


int main()
{
	std::map<int, int> s;

	ft::map<int, int> m;

	std::cout << "=============================";
	m.insert(ft::make_pair(5,4));
	std::cout << "=============================";
	m.insert(ft::make_pair(3,4));
	std::cout << "=============================";
	m.insert(ft::make_pair(2,4));
	std::cout << "=============================";
	m.insert(ft::make_pair(10,4));
	std::cout << "=============================";
	m.insert(ft::make_pair(1,4));
	std::cout << "=============================";
	m.insert(ft::make_pair(6,4));
	std::cout << "=============================";
	m.insert(ft::make_pair(7,4));
	std::cout << "=============================";
	m.insert(ft::make_pair(10,4));


	// std::set<int> m;
	// ft::set<int> fm;
	// std::vector<int> a = comparator_test(m);
	// std::vector<int> b = comparator_test(fm);

	// for (int i = 0 ; i < a.size(); i++)
	// {
	//     cout <<"[" << i  <<"]" << endl;
	// 	cout << a[i] << endl;
	// 	cout << b[i] << endl;
	// 	cout << endl;
	// }

	return 0;
}