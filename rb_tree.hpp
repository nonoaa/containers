#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "iterator.hpp"
#include "pair.hpp"
#include "algorithm.hpp"

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

		Rb_tree_node() : color(rb_tree_black), parent(), left(), right(), data() {}

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
			if (this != &src)
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
		typedef Rb_tree_iterator<Value>													Rb_tree_normal_iterator;
		typedef typename Rb_tree_node<value_type>::const_pointer						const_node_pointer;

	private:
		const_node_pointer		_node;

	public:
		Rb_tree_const_iterator() : _node() {}
		Rb_tree_const_iterator(const Rb_tree_const_iterator& src) : _node(src._node) {}
		Rb_tree_const_iterator(const Rb_tree_normal_iterator& src) : _node(src.base()) {}
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
		Rb_tree(const Rb_tree& src): _size(), _header(), _begin(&_header), _compare(src._compare), _alloc(src._alloc), _node_alloc(src._node_alloc)
		{
			if (src.root() != NULL)
			{
				root() = copy(src.root());
				root()->parent = &_header;
			}
		}

		Rb_tree& operator=(const Rb_tree & src)
		{
			if (this != &src)
			{
				clear();
				_compare = src._compare;
				if (src.root() != NULL)
				{
					root() = copy(src.root());
					root()->parent = &_header;
				}
			}
			return (*this);
		}
	
		~Rb_tree()
		{
			if (root() != NULL)
			{
				destroy(root());
				root() = NULL;
				_begin = &_header;
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
			return (_node_alloc.max_size());
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

		iterator insert(iterator position, const value_type& val)
		{
			(void)position;
			return insert(val).first;
		}

		template<typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				insert(*first);
		}

		void erase(iterator position)
		{
			node_pointer pos = position.base();
			if (pos == _begin)
			{
				position++;
				_begin = position.base();
			}
			erase(root(), pos);
			if (root() != NULL)
			{
				root()->parent = &_header;
				root()->color = rb_tree_black;
			}
			destroy_node(pos);
		}

		size_type erase(const value_type& val)
		{
			iterator pos = find(val);
			if (pos == end())
				return 0;
			erase(pos);
			return 1;
		}

		void erase(iterator first, iterator last)
		{
			if (first == begin() && last == end())
			{
				clear();
			}
			else
			{
				while (first != last)
				{
					erase(first++);
				}
			}
		}

		void swap(Rb_tree& x)
		{
			ft::swap(_begin, x._begin);
			ft::swap(_header.left, x._header.left);
			ft::swap(_size, x._size);
			if (_size != 0 && x._size != 0)
				ft::swap(root()->parent, x.root()->parent);
			else if (_size != 0)
				root()->parent = &_header;
			else if (x._size != 0)
				x.root()->parent = &(x._header);
			ft::swap(_compare, x._compare);
		}

		void clear()
		{
			if (root() != NULL)
			{
				destroy(root());
				root() = NULL;
				_begin = &_header;
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

		const_iterator find(const value_type& val) const
		{
			const_node_pointer node = root();

			while (node != NULL)
			{
				if (_compare(node->data, val))
					node = node->right;
				else if (_compare(val, node->data))
					node = node->left;
				else
					return const_iterator(node);
			}
			return end();
		}
		size_type count(const value_type& val) const
		{
			return find(val) == end() ? 0 : 1;
		}

		iterator lower_bound(const value_type& val)
		{
			node_pointer node = root();
			node_pointer pos = &_header;

			while (node != NULL)
			{
				if (!_compare(node->data, val))
				{
					pos = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return iterator(pos);
		}

		const_iterator lower_bound(const value_type& val) const
		{
			const_node_pointer node = root();
			const_node_pointer pos = &_header;

			while (node != NULL)
			{
				if (!_compare(node->data, val))
				{
					pos = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return const_iterator(pos);
		}
		
		iterator upper_bound(const value_type& val)
		{
			node_pointer node = root();
			node_pointer pos = &_header;

			while (node != NULL)
			{
				if (_compare(val, node->data))
				{
					pos = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return iterator(pos);
		}

		const_iterator upper_bound(const value_type& val) const
		{
			const_node_pointer node = root();
			const_node_pointer pos = &_header;

			while (node != NULL)
			{
				if (_compare(val, node->data))
				{
					pos = node;
					node = node->left;
				}
				else
					node = node->right;
			}
			return const_iterator(pos);
		}

		ft::pair<iterator, iterator> equal_range(const value_type& val)
		{
			node_pointer node = root();
			node_pointer pos = &_header;

			while (node != NULL)
			{
				if (_compare(val, node->data))
				{
					pos = node;
					node = node->left;
				}
				else if (_compare(node->data, val))
					node = node->right;
				else
					return ft::make_pair(iterator(node), iterator(node->right == NULL ? pos : tree_min<value_type>(node->right)));
			}
			return ft::make_pair(iterator(pos), iterator(pos));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const value_type& val) const
		{
			const_node_pointer node = root();
			const_node_pointer pos = &_header;

			while (node != NULL)
			{
				if (_compare(val, node->data))
				{
					pos = node;
					node = node->left;
				}
				else if (_compare(node->data, val))
					node = node->right;
				else
					return ft::make_pair(const_iterator(node), const_iterator(node->right == NULL ? pos : tree_min<value_type>(node->right)));
			}
			return ft::make_pair(const_iterator(pos), const_iterator(pos));
		}

		Compare value_comp() const
		{
			return _compare;
		}

	private:
		node_pointer& root()
		{
			return _header.left;
		}

		const_node_pointer& root() const
		{
			return const_cast<const_node_pointer&>(_header.left);
		}

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

		void destroy(node_pointer node)
		{
			if (node == NULL)
				return ;
			destroy(node->left);
			destroy(node->right);
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
			if (_compare(new_node->data, node->data))	// less than
			{
				node->left = insert(node->left, new_node, inserted, pos);
				node->left->parent = node;
			}
			else if (_compare(node->data, new_node->data))	// greater than
			{
				node->right = insert(node->right, new_node, inserted, pos);
				node->right->parent = node;
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
			while (node != root() && get_node_color(node->parent) == rb_tree_red)	// 4??? ????????? ???????????? ?????? ??????
			{
				node_pointer uncle = get_sibling(node->parent);
				if (get_node_color(uncle) == rb_tree_red)	// 1. ????????? ???????????? ??????
				{
					uncle->flip_color();
					node = node->parent;
					node->flip_color();
					node = node->parent;
					node->flip_color();
				}
				else if (tree_is_left_child<value_type>(node->parent)) // ?????? ????????? ???????????? ????????? ?????? ????????? ??????
				{
					if (!tree_is_left_child<value_type>(node))		// 2. ????????? ??????????????? node??? ????????? ????????? ???
					{
						node = node->parent;
						rotate_left(node);
					}
					node = node->parent; // 3. ????????? ??????????????? node??? ?????? ????????? ???
					node->flip_color();
					node = node->parent;
					node->flip_color();
					rotate_right(node);
					break ;
				}
				else	// ????????? ???????????? ????????? ????????? ??????
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

		node_pointer copy(const_node_pointer node)
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

		node_pointer replace_node(node_pointer node) const
		{
			if (node->left == NULL || node->right == NULL)
				return node;
			else
				return tree_min<value_type>(node->right);
		}

		void erase(node_pointer root, node_pointer node)
		{
			node_pointer replmt = replace_node(node);
			node_pointer replmt_child = replmt->left == NULL ? replmt->right : replmt->left;
			node_pointer sibling = NULL;

			if (replmt_child != NULL)
				replmt_child->parent = replmt->parent;
			if (tree_is_left_child<value_type>(replmt))
			{
				replmt->parent->left = replmt_child;
				if (replmt == root)
					root = replmt_child;
				else
					sibling = replmt->parent->right;
			}
			else
			{
				replmt->parent->right = replmt_child;
				sibling = replmt->parent->left;
			}

			Rb_tree_Color_type replmt_color = replmt->color;
			
			if (replmt != node)
			{
				replmt->parent = node->parent;
				if (tree_is_left_child<value_type>(node))
					replmt->parent->left = replmt;
				else
					replmt->parent->right = replmt;
				replmt->left = node->left;
				replmt->left->parent = replmt;
				replmt->right = node->right;
				if (replmt->right != NULL)
					replmt->right->parent = replmt;
				replmt->color = node->color;
				if (node == root)
					root = replmt;
			}

			if (replmt_color == rb_tree_black && root != NULL)
			{
				if (replmt_child != NULL)
					replmt_child->color = rb_tree_black;
				else
					rebalance_after_erasion(root, replmt_child, sibling);
			}
		}
		
		void rebalance_after_erasion(node_pointer root, node_pointer node, node_pointer sibling)
		{
			while (true)
			{
				if (!tree_is_left_child<value_type>(sibling))
				{
					if (get_node_color(sibling) == rb_tree_red)
					{
						sibling->flip_color();
						sibling->parent->flip_color();
						rotate_left(sibling->parent);
						if (root == sibling->left)
							root = sibling;
						sibling = sibling->left->right;
					}
					if (get_node_color(sibling->left) == rb_tree_black && get_node_color(sibling->right) == rb_tree_black)
					{
						sibling->flip_color();
						node = sibling->parent;
						if (node == root || get_node_color(node) == rb_tree_red)
						{
							node->color = rb_tree_black;
							break ;
						}
						sibling = get_sibling(node);
					}
					else
					{
						if (get_node_color(sibling->right) == rb_tree_black)
						{
							sibling->left->flip_color();
							sibling->flip_color();
							rotate_right(sibling);
							sibling = sibling->parent;
						}
						sibling->color = sibling->parent->color;
						sibling->parent->color = rb_tree_black;
						sibling->right->color = rb_tree_black;
						rotate_left(sibling->parent);
						break ;
					}
				}
				else
				{
					if (get_node_color(sibling) == rb_tree_red)
					{
						sibling->flip_color();
						sibling->parent->flip_color();
						rotate_right(sibling->parent);
						if (root == sibling->right)
							root = sibling;
						sibling = sibling->right->left;
					}
					if (get_node_color(sibling->left) == rb_tree_black && get_node_color(sibling->right) == rb_tree_black)
					{
						sibling->flip_color();
						node = sibling->parent;
						if (node == root || get_node_color(node) == rb_tree_red)
						{
							node->color = rb_tree_black;
							break ;
						}
						sibling = get_sibling(node);
					}
					else
					{
						if (get_node_color(sibling->left) == rb_tree_black)
						{
							sibling->right->flip_color();
							sibling->flip_color();
							rotate_left(sibling);
							sibling = sibling->parent;
						}
						sibling->color = sibling->parent->color;
						sibling->parent->color = rb_tree_black;
						sibling->left->color = rb_tree_black;
						rotate_right(sibling->parent);
						break ;
					}
				}
			}
		}

		// void printBinaryTree(node_pointer root, int space = 0, int height = 10)
		// {
		// 	// ?????? ?????????
		// 	if (root == NULL) {
		// 		return;
		// 	}
		// 	// ?????? ????????? ?????? ??????
		// 	space += height;
		
		// 	// ????????? ????????? ?????? ??????
		// 	printBinaryTree(root->right, space);
		// 	std::cout << std::endl;
		
		// 	// ???????????? ?????? ??? ?????? ????????? ???????????????.
		// 	for (int i = height; i < space; i++) {
		// 		std::cout << ' ';
		// 	}
		// 	std::cout << root->data.first<< "," << root->data.second;

		// 	// ?????? ?????? ??????
		// 	std::cout << std::endl;
		// 	printBinaryTree(root->left, space);
		// }
	};

	template<typename T, typename Compare, typename Alloc>
	void swap(Rb_tree<T, Compare, Alloc>& lhs, Rb_tree<T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif