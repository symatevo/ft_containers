#include "vector.hpp"

template <typename T, typename alloc = std::allocator<T> >
vector<T, alloc = std::allocator<T> >::vector(const allocator_type& alloc = allocator_type()) {
	std::cout << "vector: default constructor called" << std::endl;
	Capacity = 0;
	CurrentSize = 0;
	Arr = alloc.allocate(0);
}

explicit vector::vector(size_type n, const value_type& val = value_type()) {
	CurrentSize = n;
	Capacity = n * 2;
	Arr = alloc.allocate(n);
	for (size_t i = 0; i < CurrentSize; i++) {
		alloc.construct(&Arr[i], val);
	}
}

// template< class InputIt >
// vector (InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) {
	
// }

vector::vector(const vector& other) {
	//CurrentSize = other.CurrentSize;
	//Capacity = other.Capacity();
	*this = other;
}
vector & vector::operator= (const vector &other) {
	if (&this != other) {
		this.CurrentSize = other.CurrentSize;
		this.Capacity = other.Capacity;
		this.Arr = alloc.allocate(CurrentSize);
		for (size_t i = 0; i < CurrentSize; i++) {
			alloc.construct(&Arr[i], other.Arr[i]);
		}
	}
	return (*this);
}
vector::~vector() {
	for (size_t i = 0; i < CurrentSize; i++) {
		alloc.deallocate(&Arr[i]);
	}
	alloc.destroy(Arr);
}