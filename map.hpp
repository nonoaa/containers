#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include "rb_tree.hpp"
#include "pair.hpp"


namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key					key_type;
		typedef T					data_type;
		typedef T					mapped_type;
		typedef pair<const Key, T>	value_type;
		typedef Compare				key_compare;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class		map;
		
		protected :
			key_compare			comp;
			value_compare(key_compare c) : comp(c) {}

		public:
			typedef bool		result_type;
			bool operator()(const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

		typedef Rb_tree<value_type, value_compare, Allocator>	tree_type;
		typedef typename tree_type::pointer						pointer;
		typedef typename tree_type::const_pointer				const_pointer;
		typedef typename tree_type::reference					reference;
		typedef typename tree_type::const_reference				const_reference;
		typedef typename tree_type::iterator					iterator;
		typedef typename tree_type::const_iterator				const_iterator;
		typedef typename tree_type::reverse_iterator			reverse_iterator;
		typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;
		typedef typename tree_type::difference_type				difference_type;
		typedef typename tree_type::size_type					size_type;
		typedef typename tree_type::allocator_type				allocator_type;

	private:
		tree_type												_tree;
	
	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc) {}

		template<typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc)
		{
			insert(first, last);
		}

		map(const map& src) : _tree(src._tree) {}

		~map() {}

		map& operator= (const map& src)
		{
			if (this != &src)
			{
				_tree = src._tree;
			}
			return *this;
		}
		/* ============================================================ */
		/*                       Element access                         */
		/* ============================================================ */

		mapped_type& at(const key_type& k)
		{
			return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
		}


		mapped_type& operator[](const key_type& k)
		{
			return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
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
			return _tree.insert(position, val);
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			return _tree.insert(first, last);
		}

		void erase(iterator position)
		{
			_tree.erase(position);
		}

		size_type erase(const key_type &k)
		{
			return _tree.erase(ft::make_pair(k, mapped_type()));
		}

		void erase(iterator first, iterator last)
		{
			_tree.erase(first, last);
		}

		void swap(map &x)
		{
			_tree.swap(x._tree);
		}

		void clear()
		{
			_tree.clear();
		}


		/* ============================================================ */
		/*                       Observers                              */
		/* ============================================================ */
		key_compare key_comp() const
		{
			return key_compare();
		}

		value_compare value_comp() const
		{
			return _tree.value_comp();
		}


		/* ============================================================ */
		/*                         Operations                           */
		/* ============================================================ */

		iterator find(const key_type &k)
		{
			return _tree.find(ft::make_pair(k, mapped_type()));
		}

		const_iterator find(const key_type &k) const
		{
			return _tree.find(ft::make_pair(k, mapped_type()));
		}

		size_type count(const key_type &k) const
		{
			return _tree.count(ft::make_pair(k, mapped_type()));
		}

		iterator lower_bound(const key_type &k)
		{
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator lower_bound(const key_type &k) const
		{
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		iterator upper_bound(const key_type &k)
		{
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator upper_bound(const key_type &k) const
		{
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		ft::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return _tree.equal_range(ft::make_pair(k, mapped_type()));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return _tree.equal_range(ft::make_pair(k, mapped_type()));
		}

		/* ============================================================ */
		/*                         Allocator                            */
		/* ============================================================ */
		allocator_type get_allocator() const
		{
			return _tree.get_allocator();
		}
	};

	template <typename Key, typename T, typename Compare, typename Alloc>
	inline bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

	template <typename Key, typename T, typename Compare, typename Alloc>
	inline bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return !(lhs == rhs); }

	template <typename Key, typename T, typename Compare, typename Alloc>
	inline bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template <typename Key, typename T, typename Compare, typename Alloc>
	inline bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return rhs < lhs; }

	template <typename Key, typename T, typename Compare, typename Alloc>
	inline bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return !(rhs < lhs); }

	template <typename Key, typename T, typename Compare, typename Alloc>
	inline bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{ return !(lhs < rhs); }

	template <typename Key, typename T, typename Compare, typename Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
	{ x.swap(y); }
}

#endif