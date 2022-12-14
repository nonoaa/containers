#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		// Vector<T>
		typedef Container									container_type;
		// T
		typedef typename container_type::value_type			value_type;
		// size_t
		typedef typename container_type::size_type			size_type;

		// C++11
		// // T&
		// typedef typename container_type::reference			reference;
		// // const T&
		// typedef typename container_type::const_reference	const_reference;
	protected:
		Container c;

	public:
		explicit stack(const container_type& cont = container_type()) : c(cont) {}
		stack &operator=(const stack& src) { c = src.c; return *this; }
		~stack() {}

		bool empty() const
		{
			return c.empty();
		}

		size_type size() const
		{
			return c.size();
		}

		value_type& top()
		{
			return c.back();
		}

		const value_type& top() const
		{
			return c.back();
		}

		void push(const value_type& value)
		{
			c.push_back(value);
		}

		void pop()
		{
			c.pop_back();
		}

		template <typename Tp, typename C>
		friend bool operator==(const stack<Tp, C>& lhs, const stack<Tp, C>& rhs);
		template <typename Tp, typename C>
		friend bool operator<(const stack<Tp, C>& lhs, const stack<Tp, C>& rhs);
	};

	template <typename T, typename Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template <typename T, typename Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c < rhs.c;
	}

	template <typename T, typename Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T, typename Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return rhs < lhs;
	}

	template <typename T, typename Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif