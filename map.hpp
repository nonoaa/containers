#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
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
		typedef Allocator			allocator_type;
		
		typedef Rb_tree<value_type, key_compare, Allocator>		tree_type;
		typedef typename tree_type::iterator					iterator;
		typedef typename tree_type::const_iterator				const_iterator;
		typedef typename tree_type::reverse_iterator			reverse_iterator;
		typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

	private:
		tree_type												_tree;
	
	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc) {}

	};
}

#endif