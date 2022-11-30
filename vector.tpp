#include "vector.hpp"

//template <typename T, typename Alloc = std::allocator<T> >
template <typename T, typename Alloc >
ft::vector<T, Alloc >::vector(const allocator_type& alloc) {
	std::cout << "vector: default constructor called" << std::endl;
	CurrentSize = 0;
	myalloc = alloc;
	//malloc.allocate();
	Arr = myalloc.allocate(0);
}

template <typename T, typename Alloc > 
ft::vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) {
	CurrentSize = n;
	Capacity = n * 2;
	myalloc = alloc;
	Arr = myalloc.allocate(n);
	myval = val;
	//std::cout << myval << std::endl;
	for (size_t i = 0; i < CurrentSize; i++) {
		myalloc.construct(&Arr[i], myval);
	}
}

// template< class InputIt >
// vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) {
	
// }

template <typename T, typename Alloc>
ft::vector<T, Alloc>::vector(const vector& other) {
	//CurrentSize = other.CurrentSize;
	//Capacity = other.Capacity();
	*this = other;
}

template <typename T, typename Alloc>
ft::vector<T, Alloc> &ft::vector<T, Alloc>::operator= (const vector &other) {
	if (this != other) {
		this->CurrentSize = other.CurrentSize;
		this->Capacity = other.Capacity;
		this->Arr = myalloc.allocate(CurrentSize);
		for (size_t i = 0; i < CurrentSize; i++) {
			this->Arr[i] = other.Arr[i];
		}
	}
	return (*this);
}

// vector & vector::operator= (const vector &other) {
// 	if (&this != other) {
// 		this.CurrentSize = other.CurrentSize;
// 		this.Capacity = other.Capacity;
// 		this.Arr = alloc.allocate(CurrentSize);
// 		for (size_t i = 0; i < CurrentSize; i+00+) {
// 			alloc.construct(&Arr[i], other.Arr[i]);
// 		}
// 	}
// 	return (*this);
// }

template <typename T, typename Alloc>
ft::vector<T, Alloc>::~vector() {
	if (CurrentSize) {
		myalloc.deallocate(Arr, CurrentSize);
	}
	myalloc.destroy(Arr);
}