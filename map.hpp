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
			if (*this != src)
			{
				this->_tree = src._tree;
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
			return this->_tree.empty();
		}

		size_type size() const
		{
			return this->_tree.size();
		}

		size_type max_size() const
		{
			return this->_tree.max_size();
		}

		/* ============================================================ */
		/*                       Modifiers                              */
		/* ============================================================ */
		ft::pair<iterator, bool> insert(const value_type &val)
		{
			return _tree.insert(val);
		}

		/* ============================================================ */
		/*                         Lookup                               */
		/* ============================================================ */


		/* ============================================================ */
		/*                       Observers                              */
		/* ============================================================ */

	};
}

#endif