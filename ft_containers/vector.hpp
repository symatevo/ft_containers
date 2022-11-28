#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T, typename alloc = std::allocator<T> >
class vector {
	public:
		typedef T	value_type;
		typedef alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference cons_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		//typedef reverse_iterator<iterator> reverse_iterator;
		//typedef reverse_iterator<const_iterator> const_reverse_iterator;
		//typedef iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;
	private:
		T* Arr;
		int Capacity;
		int CurrentSize;
		//allocator_type alloc;
	public:
		vector();
		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		// template< class InputIt >
		// vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type());
		vector( const vector& other );
		~vector();
		vector &operator= (const vector &other);
} ;

#endif