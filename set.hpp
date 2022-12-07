#ifndef SET_HPP
#define SET_HPP

#include "rb_tree.hpp"

namespace ft
{
	template <typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T> >
	class set
	{
	public:
		typedef Rb_tree<T, Compare, Allocator>							tree_type;
		typedef T														key_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef typename tree_type::value_type							value_type;
		typedef typename tree_type::reference							reference;
		typedef typename tree_type::const_reference						const_reference;
		typedef typename tree_type::pointer								pointer;
		typedef typename tree_type::const_pointer						const_pointer;
		typedef typename tree_type::size_type							size_type;
		typedef typename tree_type::difference_type						difference_type;
		typedef typename tree_type::const_iterator						iterator;
		typedef typename tree_type::const_iterator						const_iterator;
		typedef typename tree_type::const_reverse_iterator				reverse_iterator;
		typedef typename tree_type::const_reverse_iterator				const_reverse_iterator;

	private:
		tree_type	_tree;

	public:
		explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _tree(comp, alloc) {}
		template <typename InputIterator>
		set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) : _tree(comp, alloc)
		{
			insert(first, last);
		}
		set(const set &src) : _tree(src._tree) {}
		~set() {}

		set &operator=(const set &src)
		{
			if (this != &src)
				_tree = src._tree;
			return *this;
		}

		/* ============================================================ */
		/*                       Iterators                              */
		/* ============================================================ */

		iterator begin()
		{
			return _tree.begin();
		}

		const_iterator begin() const
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		const_iterator end() const
		{
			return _tree.end();
		}

		reverse_iterator rbegin()
		{
			return _tree.rbegin();
		}

		const_reverse_iterator rbegin() const
		{
			return _tree.rbegin();
		}

		reverse_iterator rend()
		{
			return _tree.rend();
		}

		const_reverse_iterator rend() const
		{
			return _tree.rend();
		}

		/* ============================================================ */
		/*                       Capacity                               */
		/* ============================================================ */

		bool empty() const
		{
			return _tree.empty();
		}

		size_type size() const
		{
			return _tree.size();
		}

		size_type max_size() const
		{
			return _tree.max_size();
		}


		/* ============================================================ */
		/*                       Modifiers                              */
		/* ============================================================ */
		ft::pair<iterator, bool> insert(const value_type &val)
		{
			return _tree.insert(val);
		}

		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			return _tree.insert(val).first;
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			_tree.insert(first, last);
		}

		void erase(iterator position)
		{
			_tree.erase(*position);
		}

		size_type erase(const value_type &val)
		{
			return _tree.erase(val);
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
				_tree.erase(*(first++));
		}
		
		void swap(set &other) {
			_tree.swap(other._tree);
		}

		void clear() {
			_tree.clear();
		}

		/* ============================================================ */
		/*                       Observers                              */
		/* ============================================================ */
		key_compare key_comp() const
		{
			return key_compare();
		}

		Compare value_comp() const
		{
			return _tree.value_comp();
		}

		/* ============================================================ */
		/*                         Operations                           */
		/* ============================================================ */
		iterator find(const value_type &val) const
		{
			return _tree.find(val);
		}
		size_type count(const value_type &val) const
		{
			return _tree.count(val);
		}

		iterator lower_bound(const value_type &val) const
		{
			return _tree.lower_bound(val);
		}

		iterator upper_bound(const value_type &val) const
		{
			return _tree.upper_bound(val);
		}

		ft::pair<iterator, iterator> equal_range(const value_type &val) const
		{
			return _tree.equal_range(val);
		}

		/* ============================================================ */
		/*                         Allocator                            */
		/* ============================================================ */
		allocator_type get_allocator() const
		{
			return _tree.get_allocator();
		}
	};

	template <typename T, typename Compare, typename Alloc>
	inline bool
	operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool	operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T, typename Compare, typename Alloc>
	inline bool operator>=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T, typename Compare, typename Alloc>
	void swap(set<T, Compare, Alloc> &x, set<T, Compare, Alloc> &y)
	{
		x.swap(y);
	}

}

#endif