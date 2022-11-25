#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>

namespace ft
{
	typedef bool _Rb_tree_Color_type;
	const _Rb_tree_Color_type _rb_tree_red = false;
	const _Rb_tree_Color_type _rb_tree_black = true;

	template <typename T>
	struct _Rb_tree_node
	{
		typedef _Rb_tree_Color_type color_type;
		typedef _Rb_tree_node* pointer;
		typedef T value_type;

		color_type _color;
		pointer parent;
		pointer left;
		pointer right;
		value_type data;

		static pointer _minimum(pointer __x)
		{
			while (__x->left != 0) __x = __x->left;
			return __x;
		}

		static pointer _maximum(pointer __x)
		{
			while (__x->right != 0) __x = __x->right;
			return __x;
		}
	};

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Allocator = std::allocator<Value> >
	class Rb_tree
	{
	public:
		typedef Key								key_type;
		typedef Value							value_type;
		typedef value_type*						pointer;
		typedef const value_type*				const_pointer;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;

	};
}

#endif