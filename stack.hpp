#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace ft
{
	template <class T, class Container = std::vector<T> >
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

		stack() : c() {}
		explicit stack(const stack& src) : c(src.c) {}
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

		void swap(stack &s)
		{
			c.swap(s.c);
		}

		bool operator==(const stack& s)
		{
			return c == s.c;
		}

		bool operator!=(const stack& s)
		{
			return c != s.c;
		}

		bool operator<(const stack& s)
		{
			return c < s.c;
		}

		bool operator>(const stack& s)
		{
			return c > s.c;
		}

		bool operator<=(const stack& s)
		{
			return c <= s.c;
		}

		bool operator>=(const stack& s)
		{
			return c >= s.c;
		}

	protected:
		Container c;
	};
}

#endif