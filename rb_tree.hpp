#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>

namespace ft
{
	typedef bool Rb_tree_Color_type;
	const Rb_tree_Color_type rb_tree_red = false;
	const Rb_tree_Color_type rb_tree_black = true;

	template <typename T>
	struct Rb_tree_node
	{
		typedef Rb_tree_Color_type			color_type;
		typedef T							value_type;
		typedef Rb_tree_node<value_type>*	pointer;
		typedef const pointer				const_pointer;

		color_type color;
		pointer parent;
		pointer left;
		pointer right;
		value_type data;
	};

	template <typename T>
	bool
	tree_is_left_child(typename Rb_tree_node<T>::pointer node)
	{
		if (node && node->parent && node->parent->left)
			return node == node->parent->left;
		else
			return false;
	}

	template <typename T>
	bool
	tree_is_left_child(typename Rb_tree_node<T>::const_pointer node)
	{
		if (node && node->parent && node->parent->left)
			return node == node->parent->left;
		else
			return false;
	}

	template <typename T>
	typename Rb_tree_node<T>::pointer tree_min(typename Rb_tree_node<T>::pointer root)
	{
		while (root->left != NULL)
			root = root->left;
		return root;
	}

	template <typename T>
	typename Rb_tree_node<T>::const_pointer tree_min(typename Rb_tree_node<T>::const_pointer root)
	{
		while (root->left != NULL)
			root = root->left;
		return root;
	}

	template <typename T>
	typename Rb_tree_node<T>::pointer tree_max(typename Rb_tree_node<T>::pointer root)
	{
		while (root->right != NULL)
			root = root->right;
		return root;
	}

	template <typename T>
	typename Rb_tree_node<T>::const_pointer tree_max(typename Rb_tree_node<T>::const_pointer root)
	{
		while (root->right != NULL)
			root = root->right;
		return root;
	}

	template <typename Node_ptr, typename Value>
	class Rb_tree_iterator
	{
	public:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
		typedef Value								value_type;
		typedef Value*								pointer;
		typedef Value&								reference;

	private:
		Node_ptr									_node;

	public:
		Rb_tree_iterator() : _node() {}
		Rb_tree_iterator(const Rb_tree_iterator& src) : _node(src._node) {}
		Rb_tree_iterator(const Node_ptr& val) : _node(val) {}
		Rb_tree_iterator& operator=(const Rb_tree_iterator& src)
		{
			if (*this != src)
			{
				_node = src._node;
			}
			return *this;
		}

		reference operator*() const
		{
			return _node->data;
		}

		pointer operator->() const
		{
			return &_node->data;
		}

		Rb_tree_iterator& operator++()
		{
			if (_node->right != NULL)
			{
				_node = tree_min<value_type>(_node->right);
			}
			else
			{
				while (!tree_is_left_child<value_type>(_node))
				{
					_node = _node->parent;
				}
				_node = _node->parent;
			}
			return *this;
		}

		Rb_tree_iterator operator++(int)
		{
			Rb_tree_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		Rb_tree_iterator& operator--()
		{
			if (_node->left != NULL)
			{
				_node = tree_max<value_type>(_node->left);
			}
			else
			{
				while (tree_is_left_child<value_type>(_node))
				{
					_node = _node->parent;
				}
				_node = _node->parent;
			}
			return *this;
		}

		Rb_tree_iterator operator--(int)
		{
			Rb_tree_iterator tmp(*this);
			--(*this);
			return tmp;
		}

		Node_ptr base() const
		{
			return _node;
		}
	};

	template<typename Node_ptr, typename Value>
	inline bool
		operator==(const Rb_tree_iterator<Node_ptr, Value>& lhs, const Rb_tree_iterator<Node_ptr, Value>& rhs)
	{
		return rhs.base() == lhs.base();
	}

	template<typename Node_ptr, typename Value>
	inline bool
		operator!=(const Rb_tree_iterator<Node_ptr, Value>& lhs, const Rb_tree_iterator<Node_ptr, Value>& rhs)
	{
		return rhs.base() != lhs.base();
	}

	template <typename Value, typename Compare, typename Allocator = std::allocator<Value> >
	class Rb_tree
	{
	public:
		// typedef Key										key_type;
		typedef Value									value_type;
		typedef Compare									compare_type;

		typedef Rb_tree_node<value_type>				node_type;
		typedef Allocator								allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef size_t									size_type;
		typedef ptrdiff_t								difference_type;

		typedef typename node_type::pointer				node_ptr;
		typedef Rb_tree_iterator<node_ptr, value_type>	iterator;
		typedef reverse_iterator<iterator>				reverse_iterator;

	private:
		size_type										_size;
		node_type										_parent;
		node_ptr										_begin;
		Compare											_compare;
		allocator_type									_alloc;
		node_allocator_type								_node_alloc;

	public:

		Rb_tree(const compare_type& comp, const allocator_type& alloc)
			: _size(), _parent(), _begin(&_parent), _compare(comp), _alloc(alloc), _node_alloc(alloc) {}

	};
}

#endif