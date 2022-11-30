#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "iterator.hpp"
#include "pair.hpp"

#include <iostream>

namespace ft
{
	typedef bool Rb_tree_Color_type;
	const Rb_tree_Color_type rb_tree_red = false;
	const Rb_tree_Color_type rb_tree_black = true;

	template <typename T>
	struct Rb_tree_node
	{
		typedef Rb_tree_Color_type					color_type;
		typedef T									value_type;
		typedef Rb_tree_node<value_type>*			pointer;
		typedef const Rb_tree_node<value_type>*		const_pointer;

		color_type color;
		pointer parent;
		pointer left;
		pointer right;
		value_type data;

		Rb_tree_node() : data(), color(rb_tree_black), parent(), left(), right() {}

		void flip_color()
		{
			color = ((color == rb_tree_red) ? rb_tree_black : rb_tree_red);
		}
	};

	template <typename T>
	bool tree_is_left_child(typename Rb_tree_node<T>::pointer node)
	{
		if (node && node->parent && node->parent->left)
			return node == node->parent->left;
		else
			return false;
	}

	template <typename T>
	bool tree_is_left_child(typename Rb_tree_node<T>::const_pointer node)
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

	template <typename Value>
	class Rb_tree_iterator
	{
	public:
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
		typedef Value								value_type;
		typedef Value*								pointer;
		typedef Value&								reference;
		typedef typename Rb_tree_node<value_type>::pointer	node_pointer;

	private:
		node_pointer								_node;

	public:
		Rb_tree_iterator() : _node() {}
		Rb_tree_iterator(const Rb_tree_iterator& src) : _node(src._node) {}
		Rb_tree_iterator(const node_pointer& val) : _node(val) {}
		Rb_tree_iterator& operator=(const Rb_tree_iterator& src)
		{
			if (*this != src)
			{
				_node = src._node;
			}
			return *this;
		}

		Rb_tree_iterator& operator=(const node_pointer& n)
		{
			_node = n;
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

		node_pointer base() const
		{
			return _node;
		}
	};

	template<typename Value>
	inline bool	operator==(const Rb_tree_iterator<Value>& lhs, const Rb_tree_iterator<Value>& rhs)
	{
		return rhs.base() == lhs.base();
	}

	template<typename Value>
	inline bool operator!=(const Rb_tree_iterator<Value>& lhs, const Rb_tree_iterator<Value>& rhs)
	{
		return rhs.base() != lhs.base();
	}

	template <typename Value>
	class Rb_tree_const_iterator
	{
	public:
		typedef std::bidirectional_iterator_tag											iterator_category;
		typedef ptrdiff_t																difference_type;
		typedef Value																	value_type;
		typedef const Value*															pointer;
		typedef const Value&															reference;
		typedef Rb_tree_const_iterator<Value>											Rb_tree_normal_iterator;
		typedef typename Rb_tree_node<value_type>::const_pointer						const_node_pointer;

	private:
		const_node_pointer		_node;

	public:
		Rb_tree_const_iterator() : _node() {}
		Rb_tree_const_iterator(const Rb_tree_const_iterator& src) : _node(src._node) {}
		// Rb_tree_const_iterator(const Rb_tree_normal_iterator& src) : _node(src.base()) {}
		Rb_tree_const_iterator(const const_node_pointer& val) : _node(val) {}
		Rb_tree_const_iterator& operator=(const Rb_tree_const_iterator& src)
		{
			if (*this != src)
			{
				_node = src._node;
			}
			return *this;
		}

		Rb_tree_const_iterator& operator=(const const_node_pointer& n)
		{
			_node = n;
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

		Rb_tree_const_iterator& operator++()
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

		Rb_tree_const_iterator operator++(int)
		{
			Rb_tree_const_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		Rb_tree_const_iterator& operator--()
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

		Rb_tree_const_iterator operator--(int)
		{
			Rb_tree_const_iterator tmp(*this);
			--(*this);
			return tmp;
		}

		const_node_pointer base() const
		{
			return _node;
		}
	};

	template <typename Value>
	inline bool	operator==(const Rb_tree_const_iterator<Value> &rhs, const Rb_tree_const_iterator<Value> &lhs)
	{
		return rhs.base() == lhs.base();
	}

	template <typename Value>
	inline bool	operator!=(const Rb_tree_const_iterator<Value> &rhs, const Rb_tree_const_iterator<Value> &lhs)
	{
		return rhs.base() != lhs.base();
	}

	template <typename Value>
	inline bool	operator==(const Rb_tree_const_iterator<Value> &rhs, const Rb_tree_iterator<Value> &lhs)
	{
		return rhs.base() == lhs.base();
	}

	template <typename Value>
	inline bool	operator!=(const Rb_tree_const_iterator<Value> &rhs, const Rb_tree_iterator<Value> &lhs)
	{
		return rhs.base() != lhs.base();
	}

	template <typename Value>
	inline bool	operator==(const Rb_tree_iterator<Value> &rhs, const Rb_tree_const_iterator< Value> &lhs)
	{
		return rhs.base() == lhs.base();
	}

	template <typename Value>
	inline bool	operator!=(const Rb_tree_iterator<Value> &rhs, const Rb_tree_const_iterator<Value> &lhs)
	{
		return rhs.base() != lhs.base();
	}

	template <typename Value, typename Compare, typename Allocator = std::allocator<Value> >
	class Rb_tree
	{
	public:
		// typedef Key										key_type;
		typedef Value														value_type;
		typedef Compare														compare_type;

		typedef Rb_tree_node<value_type>									node_type;
		typedef Allocator													allocator_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
		typedef value_type*													pointer;
		typedef const value_type*											const_pointer;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef size_t														size_type;
		typedef ptrdiff_t													difference_type;

		typedef typename node_type::pointer									node_pointer;
		typedef typename node_type::const_pointer							const_node_pointer;
		typedef Rb_tree_iterator<value_type>								iterator;
		typedef Rb_tree_const_iterator<value_type>							const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

	protected:
		size_type										_size;
		node_type										_header;
		node_pointer									_begin;
		compare_type									_compare;
		allocator_type									_alloc;
		node_allocator_type								_node_alloc;

	public:
		Rb_tree(const compare_type& comp, const allocator_type& alloc)
			: _size(), _header(), _begin(&_header), _compare(comp), _alloc(alloc), _node_alloc(alloc) {}
		// Rb_tree(): m_root(0), m_nil(0), m_val_alloc(allocator_type()), m_node_alloc(node_allocator()), m_compare(value_compare()), m_size(0) {}
		Rb_tree(const Rb_tree& src): _size(), _header(), _begin(&_header), _compare(src._compare), _alloc(src._alloc), _node_alloc(src._node_alloc)
		{
			if (src.root() != NULL)
			{
				root() = copy(src.root());
				root()->parent = &_header;
			}
		}
		// template<class InputIterator>
		// Rb_tree(typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type first, InputIterator last, const value_compare& comp, const allocator_type& alloc = allocator_type()):
		// m_val_alloc(alloc), m_node_alloc(node_allocator()), m_compare(comp)
		// {
		// 	init_nil_head();
		// 	m_root = m_header;
		// 	for (; first != last; ++first)
		// 		insert(*first);
		// }
		Rb_tree& operator=(const Rb_tree & src)
		{
			if (*this != src)
			{
				clear();
				_compare = src._compare;
				if (t.root() != NULL)
				{
					root() = copy(root());
					root()->_parent = &_header;
				}
			}
			return (*this);
		}
	
		~Rb_tree()
		{
			// printBinaryTree(root());
			if (root() != NULL)
			{
				clear();
			}
		}

		/* ============================================================ */
		/*                       Iterators                              */
		/* ============================================================ */

		iterator begin() {return iterator(_begin);}
		const_iterator begin() const { return const_iterator(_begin);}
		iterator end() { return iterator(&_header); }
		const_iterator end() const { return const_iterator(&_header); }
		reverse_iterator rbegin() { return (reverse_iterator(end())); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(end())); }
		reverse_iterator rend() { return (reverse_iterator(begin())); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(begin())); }


		/* ============================================================ */
		/*                       Capacity                               */
		/* ============================================================ */

		bool empty() const
		{
			return (_size == 0);
		}

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (size_type(-1));
		}

		/* ============================================================ */
		/*                       Modifiers                              */
		/* ============================================================ */

		ft::pair<iterator, bool> insert(const value_type& val)
		{
			iterator it = find(val);
			if (it != end())
				return ft::make_pair<iterator, bool>(it, false);

			node_pointer new_node = construct_node(val);
			bool inserted = false;
			iterator pos;
			root() = insert(root(), new_node, inserted, pos);
			root()->parent = &_header;
			if (!inserted)
			{
				destroy_node(new_node);
			}
			else
			{
				rebalance_after_insertion(new_node);
			}
			root()->color = rb_tree_black;
			return ft::make_pair(pos, inserted);
		}

		// iterator insert(iterator position, const value_type& value) {}
		// template<class InputIt>
		// void insert(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last) {}
		// void erase(iterator pos) {}
		// size_type erase(const value_type& value) {}
		// void erase(iterator first, iterator last) {}
		// void swap(Rb_tree &other) {}
		void clear()
		{
			if (root() != NULL)
			{
				destroy_all(root());
				root() = NULL;
				// _begin = end_node();
			}
		}

		iterator find(const value_type& val)
		{
			node_pointer node = root();

			while (node != NULL)
			{
				if (_compare(node->data, val))
					node = node->right;
				else if (_compare(val, node->data))
					node = node->left;
				else
					return iterator(node);
			}
			return end();
		}
		// const_iterator find(const value_type& value) const {}
		// size_type count(const value_type& value) const {}
		// iterator lower_bound(const value_type& value) {}
		// const_iterator lower_bound(const value_type& value) const {}
		// iterator upper_bound(const value_type& value) {}
		// ft::pair<iterator, iterator> equal_range(const value_type &value) {}
		// ft::pair<const iterator, iterator> equal_range(const value_type &value) {}


	private:
		node_pointer& root() { return _header.left; }
		const_node_pointer& root() const { return const_cast<const_node_pointer&>(this->_header.left); }
		node_pointer construct_node(const value_type& data)
		{
			node_pointer new_node = _node_alloc.allocate(1);
			_alloc.construct(&new_node->data, data);
			new_node->color = rb_tree_red;
			new_node->parent = NULL;
			new_node->left = NULL;
			new_node->right = NULL;
			if (empty() || _compare(data, _begin->data))
				_begin = new_node;
			++_size;
			return new_node;
		}

		void destroy_node(node_pointer node)
		{
			_alloc.destroy(&node->data);
			_node_alloc.deallocate(node, 1);
			--_size;
		}

		void destroy_all(node_pointer node)
		{
			if (node == NULL)
				return ;
			destroy_all(node->left);
			destroy_all(node->right);
			destroy_node(node);
		}

		node_pointer insert(node_pointer node, node_pointer new_node, bool& inserted, iterator& pos)
		{
			if (node == NULL)
			{
				pos = new_node;
				inserted = true;
				return new_node;
			}
			if (_compare(node->data, new_node->data) == _compare(new_node->data, node->data))
			{
				node->left = insert(node->left, new_node, inserted, pos);
				node->left->parent = node;
			}
			else if (_compare(node->data, new_node->data))	// greater than
			{
				node->right = insert(node->right, new_node, inserted, pos);
				node->right->parent = node;
			}
			else if (_compare(new_node->data, node->data))	// less than
			{
				node->left = insert(node->left, new_node, inserted, pos);
				node->left->parent = node;
			}
			else	// equal
			{
				pos = node;
				inserted = false;
			}
			return node;
		}

		void rebalance_after_insertion(node_pointer node)
		{
			while (node != root() && get_node_color(node->parent) == rb_tree_red)	// 4번 규칙을 위반하고 있는 동안
			{
				node_pointer uncle = get_sibling(node->parent);
				if (get_node_color(uncle) == rb_tree_red)	// 1. 삼촌이 빨간색인 경우
				{
					uncle->flip_color();
					node = node->parent;
					node->flip_color();
					node = node->parent;
					node->flip_color();
				}
				else if (tree_is_left_child<value_type>(node->parent)) // 부모 노드가 할아버지 노드의 왼쪽 자식인 경우
				{
					if (!tree_is_left_child<value_type>(node))		// 2. 삼촌이 검은색이고 node가 오른쪽 자식일 때
					{
						node = node->parent;
						rotate_left(node);
					}
					node = node->parent; // 3. 삼촌이 검은색이고 node가 왼쪽 자식일 때
					node->flip_color();
					node = node->parent;
					node->flip_color();
					rotate_right(node);
					break ;
				}
				else	// 부모가 할아버지 오른쪽 자식인 경우
				{
					if (tree_is_left_child<value_type>(node))
					{
						node = node->parent;
						rotate_right(node);
					}
					node = node->parent;
					node->flip_color();
					node = node->parent;
					node->flip_color();
					rotate_left(node);
					break ;
				}
			}
		}

		void rotate_left(node_pointer node)
		{
			node_pointer right_node = node->right;
			node->right = right_node->left;
			if (node->right != NULL)
				node->right->parent = node;
			right_node->parent = node->parent;
			if (tree_is_left_child<value_type>(node))
				node->parent->left = right_node;
			else
				node->parent->right = right_node;
			right_node->left = node;
			node->parent = right_node;
		}

		void rotate_right(node_pointer node)
		{
			node_pointer left_node = node->left;
			node->left = left_node->right;
			if (node->left != NULL)
				node->left->parent = node;
			left_node->parent = node->parent;
			if (tree_is_left_child<value_type>(node))
				node->parent->left = left_node;
			else
				node->parent->right = left_node;
			left_node->right = node;
			node->parent = left_node;
		}

		node_pointer get_sibling(node_pointer node) const
		{
			if (tree_is_left_child<value_type>(node))
				return node->parent->right;
			else
				return node->parent->left;
		}

		Rb_tree_Color_type get_node_color(node_pointer node)
		{
			if (node == NULL)
				return rb_tree_black;
			else
				return node->color;
		}

		node_pointer copy(const node_pointer node)
		{
			if (node == NULL)
				return NULL;
			node_pointer new_node = construct_node(node->data);
			new_node->left = copy(node->left);
			if (new_node->left != NULL)
				new_node->left->parent = new_node;
			new_node->right = copy(node->right);
			if (new_node->right != NULL)
				new_node->right->parent = new_node;
			return new_node;
		}

		void printBinaryTree(node_pointer root, int space = 0, int height = 10)
		{
			// 기본 케이스
			if (root == NULL) {
				return;
			}
		
			// 레벨 사이의 거리 증가
			space += height;
		
			// 오른쪽 자식을 먼저 출력
			printBinaryTree(root->right, space);
			std::cout << std::endl;
		
			// 공백으로 채운 후 현재 노드를 인쇄합니다.
			for (int i = height; i < space; i++) {
				std::cout << ' ';
			}
			std::cout << root->data.first<< "," << root->data.second;
		
			// 왼쪽 자식 출력
			std::cout << std::endl;
			printBinaryTree(root->left, space);
		}
	};
}

#endif