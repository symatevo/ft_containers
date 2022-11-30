#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>

namespace ft {
	template <typename T, typename Alloc = std::allocator<T> > class vector {
		public:
			typedef T	value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference cons_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			//typedef reverse_iterator<iterator> reverse_iterator;
			//typedef reverse_iterator<con0st_iterator> const_reverse_iterator;
			//typedef iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;
		private:
			T* Arr;
			size_t Capacity;
			size_t CurrentSize;
			Alloc myalloc;
			value_type myval;
		public:
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			// template< class InputIt >
			// vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type());
			vector( const vector& other );
			~vector();
			vector &operator= (const vector &other);
			size_type size() const;
			size_type max_size() const;
			void resize(size_type n, value_type val = value_type()) const;
			size_type Capacity() const;
			bool empty() const;
			reserve() const;
			shrink_to_fit() const;
	} ;
}

# include "vector.tpp"
#endif