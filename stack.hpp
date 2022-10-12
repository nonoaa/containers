#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace ft
{
	template <class _T, class _Container = std::vector<_T> >
	class stack
	{
	public:
		// Vector<_T>
		typedef _Container									container_type;
		// _T
		typedef typename container_type::value_type			value_type;
		// _T&
		typedef typename container_type::reference			reference;
		// const _T&
		typedef typename container_type::const_reference	const_reference;
		// size_t
		typedef typename container_type::size_type			size_type;

		stack() : c() {}
		explicit stack(const stack& src) : c(src) {}
		stack &operator=(const stack& src) { c = src.c; return *this; }
		~stack() {}

		bool empty() const
		{
			if (c.size() == 0)
				return true;
			return false;
		}

		size_type size() const
		{
			return c.size();
		}

		reference top()
		{
			return c.back();
		}

		const_reference top() const
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

	protected:
		_Container c;
	};
}

#endif