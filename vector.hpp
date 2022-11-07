#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
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

		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _capacity(0), _size(0) {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _ptr(NULL), _capacity(n), _size(n)
		{
			_ptr = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_ptr + i, val);
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc)
		{

		}

	private:
		allocator_type		_alloc;
		pointer				_ptr;
		size_type			_capacity; // 할당된 크기
		size_type			_size; // 실제 들어간 데이터의 개수
	};

}

#endif