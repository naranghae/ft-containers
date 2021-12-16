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

	template<class T>
	const T& max(const T& a, const T& b)
	{
		return (a > b) ? a : b;
	}
}
#endif