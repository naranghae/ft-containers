#ifndef UTILS_HPP
# define UTILS_HPP
namespace ft
{
	template<class T>
	inline void swaping(T& a, T& b)
	{
		T c(a);
		a = b;
		b = c;
	}
}
#endif