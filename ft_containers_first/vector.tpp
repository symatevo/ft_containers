#include "vector.hpp"

template <typename T, typename Alloc >
ft::vector<T, Alloc >::vector(const allocator_type& alloc) {
	std::cout << "vector: default constructor called" << std::endl;
	CurrentSize = 0;
	myalloc = alloc;
	Arr = myalloc.allocate(0);
}

template <typename T, typename Alloc > 
ft::vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc) {
	std::cout << "vector constructor with parametrs called" << std::endl;
	CurrentSize = n;
	Capacity = n * 2;
	myalloc = alloc;
	Arr = myalloc.allocate(n);
	myval = val;
	for (size_t i = 0; i < CurrentSize; i++) {
		myalloc.construct(&Arr[i], myval);
	}
}

template <typename T, typename Alloc>
ft::vector<T, Alloc>::vector(const vector& other) {
	std::cout << "vector copy constructor called" << std::endl;
	*this = other;
}

template <typename T, typename Alloc>
ft::vector<T, Alloc> &ft::vector<T, Alloc>::operator= (const vector &other) {
	std::cout << "vector operator assignement called" << std::endl;
	if (this != other) {
		this->CurrentSize = other.CurrentSize;
		this->Capacity = other.Capacity;
		this->Arr = myalloc.allocate(CurrentSize);
		for (size_t i = 0; i < CurrentSize; i++) {
			myalloc.construct(&Arr[i], other.Arr[i]);
		}
	}
	return (*this);
}

template <typename T, typename Alloc>
ft::vector<T, Alloc>::~vector() {
	std::cout << "vector destructor called" << std::endl;
	if (CurrentSize) {
		myalloc.deallocate(Arr, CurrentSize);
	}
	myalloc.destroy(Arr);
}

template <typename T, typename Alloc>
size_t ft::vector<T, Alloc>::size() const {
	return CurrentSize;
}

template <typename T, typename Alloc> 
size_t ft::vector<T, Alloc>::max_size() const {
	return 2^32 - sizeof(myval);
}

template <typename T, typename Alloc>
void ft::vector<T, Alloc>::resize(size_t n, value_type val = value_type()) const {
	if (n < CurrentSize) {
		CurrentSize = n;
		vector(n);
	}
}
