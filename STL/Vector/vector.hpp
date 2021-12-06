
#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <vector>
# include "../Iterator/random_access_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"

namespace ft
{
	template<typename T, typename _Alloc = std::allocator<T>>
	class Vector
	{
	public:
		typedef T										value_type;
		typedef	_Alloc									allocator_type;
		typedef	value_type&								reference;
		typedef	const reference							const_reference;
		typedef	value_type*								pointer;
		typedef	const pointer							const_pointer;
		typedef	ft::random_access_iterator<T>			iterator;
		typedef	ft::random_access_iterator<const T>		const_iterator;
		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef	ptrdiff_t								difference_type;
		typedef	size_t									size_type;
	
		//constructor
		explicit	Vector(const allocator_type& alloc = allocator_type());
		explicit	Vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
		template<class InputIterator>
		Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		Vector(const Vector &x);
		//destructor

		//operator=

		//begin

		//end

		//rbegin

		//rend

		//size

		//max_size

		//resize

		//capacity

		//empty

		//reserve

		//operator[]

		//at

		//front

		//back

		//assign

		//push_back

		//pop_back

		//insert

		//erase

		//swap

		//clear

		//get_allocator

		//relational operator (==, !=, <, <=, >, >=)

		//swap

		//vector<bool>
	};

}
#endif
