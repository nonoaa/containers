#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef> // ptrdiff_t

namespace ft
{
	// Category tags
	class input_iterator_tag {};
	class output_iterator_tag {};
	class forward_iterator_tag : public input_iterator_tag {};
	class bidirectional_iterator_tag : public forward_iterator_tag {};
	class random_access_iterator_tag : public bidirectional_iterator_tag {};

	// base iterator class
	// Category == iterator_tag
	// ptrdiff_t == 포인터의 크기(현재 : int)
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;
		typedef Category		iterator_category;
	};

	// iterator_traits
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	// Reverse Iterator
	template<class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator														iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type				difference_type;
		typedef typename iterator_traits<Iterator>::value_type					value_type;
		typedef typename iterator_traits<Iterator>::pointer						pointer;
		typedef typename iterator_traits<Iterator>::reference					reference;
		typedef typename iterator_traits<Iterator>::iterator_category			iterator_category;

		reverse_iterator() : _iter(iterator_type()) {};
		explicit reverse_iterator(iterator_type it) : _iter(it) {};
		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter> &src) : _iter(src._iter) {};

		template<class Iter>
		reverse_iterator &operator=(const reverse_iterator<Iter> &src)
		{
			_iter = src._iter;
			return *this;
		}

		~reverse_iterator() {};

		reference operator*() const
		{
			Iterator tmp(_iter);
			return *--tmp;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reverse_iterator& operator++()
		{
			--_iter;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(_iter);
			--_iter;
			return tmp;
		}

		reverse_iterator& operator--()
		{
			++_iter;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(_iter);
			++_iter;
			return tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(_iter - n);
		}

		reverse_iterator& operator+=(difference_type n)
		{
			_iter -= n;
			return *this;
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(_iter + n);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			_iter += n;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

	friend bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs);

	friend bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs);

	protected:
		Iterator	_iter;
	};

	template <typename Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs._iter == rhs._iter;
	}

	template <typename Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs._iter < rhs._iter;
	}

	template <typename Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return rhs < lhs;
	}

	template <typename Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return !(rhs < lhs);
	}

	template <typename Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return !(lhs < rhs);
	}

	// Random Access Iterator
	template<typename T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
	public:
		typedef typename iterator<random_access_iterator_tag, T>::difference_type		difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::value_type			value_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer				pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference				reference;
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;

		random_access_iterator() : _ptr(NULL) {}
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator<T> &ref) : _ptr(ref._ptr) {}
		random_access_iterator &operator=(const random_access_iterator<T> &ref)
		{
			if (this != &ref)
				_ptr = ref._ptr;
			return *this;
		}

		~random_access_iterator() {}

		reference operator*() const
		{
			return *_ptr;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[] (difference_type n) const
		{
			return _ptr[n];
		}

		random_access_iterator& operator++()
		{
			++_ptr;
			return *this;
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			++_ptr;
			return tmp;
		}

		random_access_iterator& operator--()
		{
			--_ptr;
			return *this;
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			--_ptr;
			return tmp;
		}

		random_access_iterator operator+=(difference_type n)
		{
			_ptr += n;
			return *this;
		}

		random_access_iterator operator-=(difference_type n)
		{
			_ptr -= n;
			return *this;
		}
		
		// operator random_access_iterator<const value_type>() const
		// {
		// 	return random_access_iterator<const value_type>(_ptr);
		// }
		random_access_iterator operator+ (difference_type n) const
		{
			return _ptr + n;
		}

		random_access_iterator operator- (difference_type n) const
		{
			return _ptr - n;
		}

		template<typename T1, typename T2>
		friend typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs);

		template <typename T1, typename T2>
		friend bool operator==(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs);

		template <typename T1, typename T2>
		friend bool operator<(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs);

	protected:
		pointer	_ptr;
	};

	template<typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &rait)
	{
		return rait + n;
	}

	template<typename T1, typename T2>
	typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{
		return lhs._ptr - rhs._ptr;
	}

	template <typename T1, typename T2>
	bool operator==(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{
		return lhs._ptr == rhs._ptr;
	}

	template <typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator<(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{
		return lhs._ptr < rhs._ptr;
	}

	template <typename T1, typename T2>
	bool operator>(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif