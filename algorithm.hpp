#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename T>
	void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename InputIterator1, typename InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
			{
				return false;
			}
			++first1;
			++first2;
		}
		return true;
	}

	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate p)
	{
		while (first1 != last1)
		{
			if (!p(*first1 == *first2))
			{
				return false;
			}
			++first1;
			++first2;
		}
		return true;
	}

	template <typename InputIterator1, typename InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
			{
				return false;
			}
			if (*first1 < *first2)
			{
				return true;
			}
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <typename InputIterator1, typename InputIterator2, typename Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2, Compare cmp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || cmp(*first2, *first1))
			{
				return false;
			}
			if (cmp(*first1, *first2))
			{
				return true;
			}
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type difference(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type n;
		n = 0;
		for (; first != last; first++)
			n++;
		return n;
	}
}

#endif