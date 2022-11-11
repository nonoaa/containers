#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "type_traits.hpp"
#include "algorithm.hpp"
#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename allocator_type::difference_type		difference_type;
		typedef typename allocator_type::size_type				size_type;

		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _end_capacity(NULL) {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc)
		{
			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _start + n;
			while(n--)
			{
				_alloc.construct(_end++, val);
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			: _alloc(alloc)
		{
			difference_type n = last - first;
			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _start + n;
			while(n--)
			{
				_alloc.construct(_end++ , *first++);
			}
		}

		vector(const vector& src) : _alloc(src._alloc)
		{
			size_type n = src.size();
			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _start + n;
			pointer src_start = src._start;
			while (n--)
			{
				_alloc.construct(_end++, *src_start++);
			}
		}

		vector& operator=(const vector& src)
		{
			if (*this != src)
			{
				clear();
				_alloc.deallocate(_start, capacity());
				size_type n = src.size();
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
				pointer src_start = src._start;
				while (n--)
				{
					_alloc.construct(_end++, *src_start++);
				}
			}
			return *this;
		}

		~vector()
		{
			clear();
			_alloc.deallocate(_start, capacity());
		}

		/* ============================================================ */
		/*                       Iterators                              */
		/* ============================================================ */

		iterator begin()
		{
			return iterator(_start);
		}

		const_iterator begin() const
		{
			return const_iterator(_start);
		}

		iterator end()
		{
			return iterator(_end);
		}

		const_iterator end() const
		{
			return const_iterator(_end);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		} 

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		/* ============================================================ */
		/*                       Capacity                               */
		/* ============================================================ */

		size_type size() const
		{
			return size_type(end() - begin());
		}

		size_type max_size() const
		{
			return _alloc.max_size();
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n > max_size())
			{
				throw std::out_of_range("ft::vector");
			}
			if (n < size())
			{
				erase(begin() + n, end());
			}
			else
			{
				insert(end(), n - size(), val);
			}
		}

		size_type capacity() const
		{
			return size_type(_end_capacity - _start);
		}

		bool empty() const
		{
			return begin() == end();
		}

		void reserve(size_type n)
		{
			if (n > max_size())
			{
				throw std::out_of_range("ft::vector");
			}
			if (capacity() >= n)
			{
				return ;
			}

			pointer prev_start = _start;
			pointer prev_end = _end;
			size_type prev_capacity = capacity();

			_start = _alloc.allocate(n);
			_end = _start;
			_end_capacity = _start + n;

			for(pointer it = prev_start; it != prev_end; it++)
			{
				_alloc.construct(_end++, *it);
				_alloc.destroy(it);
			}
			_alloc.deallocate(prev_start, prev_capacity);
		}


		/* ============================================================ */
		/*                       Element access                         */
		/* ============================================================ */

		reference operator[](size_type n)
		{
			return *(begin() + n);
		}

		const_reference operator[](size_type n) const
		{
			return *(begin() + n);
		}

		reference at(size_type n)
		{
			if (n >= size())
			{
				throw std::out_of_range("ft::vector");
			}
			return (*this)[n];
		}

		const reference at(size_type n) const
		{
			if (n >= size())
			{
				throw std::out_of_range("ft::vector");
			}
			return (*this)[n];
		}

		reference front()
		{
			return *begin();
		}

		const_reference front() const
		{
			return *begin();
		}

		reference back()
		{
			return *(end() - 1);
		}

		const_reference back() const
		{
			return *(end() - 1);
		}

		/* ============================================================ */
		/*                       Modifiers                              */
		/* ============================================================ */

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			clear();
			size_type n = last - first;
			if (capacity() < n)
			{
				_alloc.deallocate(_start, capacity());
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
			}
			while (n--)
			{
				_alloc.construct(_end++, *first++);
			}
		}

		void assign(size_type n, const value_type& val)
		{
			clear();
			if (capacity() < n)
			{
				_alloc.deallocate(_start, capacity());
				_start = _alloc.allocate(n);
				_end = _start;
				_end_capacity = _start + n;
			}
			while (n--)
			{
				_alloc.construct(_end++, val);
			}
		}

		void push_back(const value_type& val)
		{
			if (_end == _end_capacity)
			{
				empty() ? reserve(1) : reserve(capacity() * 2);
			}
			_alloc.construct(_end++, val);
		}

		void pop_back()
		{
			_alloc.destroy(--_end);
		}

		iterator insert(iterator position, const value_type& val)
		{
			size_type n = position - begin();
			if (_end != _end_capacity && position == end())
			{
				_alloc.construct(_end++, val);
			}
			else
			{
				insert(position, 1, val);
			}
			return begin() + n;
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			reserve(size() + n);
			size_type pos = position - begin();

			for (size_type i = 1; i <= size() - pos; i++)
			{
				_alloc.construct(_end + n - i,  *(_end - i));
				_alloc.destroy(_end - i);
			}
			_end += n;
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_start + pos + i, val);
			}
			return ;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			size_type n = last - first;
			reserve(size() + n);
			size_type pos = position - begin();

			for (size_type i = 1; i <= size() - pos; i++)
			{
				_alloc.construct(_end + n - i,  *(_end - i));
				_alloc.destroy(_end - i);
			}
			_end += n;
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_start + pos + i, *(first + i));
			}
			return ;
		}

		iterator erase(iterator position)
		{
			iterator it = position;
			while (it + 1 != end())
			{
				_alloc.destroy(&(*it));
				_alloc.construct(&(*it), *(it + 1));
				it++;
			}
			_alloc.destroy(&(*it));
			--_end;
			return position;
		}

		iterator erase(iterator first, iterator last)
		{
			size_type n = last - first;
			iterator it = first;
			while (it + n != end())
			{
				_alloc.destroy(&(*it));
				_alloc.construct(&(*it), *(it + n));
				++it;
			}
			while (it != end())
			{
				_alloc.destroy(&(*it));
				++it;
			}
			_end -= n;
			return first;
		}

		void swap(vector<T, Allocator>& x)
		{
			ft::swap(_alloc, x._alloc);
			ft::swap(_start, x._start);
			ft::swap(_end, x._end);
			ft::swap(_end_capacity, x._end_capacity);
		}

		void clear()
		{
			while (_start != _end)
			{
				_alloc.destroy(--_end);
			}
		}

		allocator_type get_allocator() const
		{
			return _alloc;
		}

	private:
		allocator_type		_alloc;
		pointer				_start;
		pointer				_end;
		pointer				_end_capacity;
	};

	template <typename T, typename Alloc>
	inline bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename T, typename Alloc>
	inline bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Alloc>
	inline bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Alloc>
	inline bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T, typename Alloc>
	inline bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <typename T, typename Alloc>
	inline bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T, typename Alloc>
	void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif