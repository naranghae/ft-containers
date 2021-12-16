#ifndef ITER_HPP
# define ITER_HPP
typedef __PTRDIFF_TYPE__ ptrdiff_t;

namespace ft
{
	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef	T				value_type;
		typedef	Distance		difference_type;
		typedef Pointer			pointer;
		typedef	Reference		reference;
		typedef	Category		iterator_category;
	};
}
#endif