#ifndef UTILS_HPP
# define UTILS_HPP

typedef __PTRDIFF_TYPE__ ptrdiff_t;
namespace ft
{
	//enable_if
	template<bool Cond, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	//is_integral
	template<class T, T v>
	struct integral_constant
	{
		static constexpr T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		constexpr operator T() {return v;}

		constexpr operator value_type()
		{
			
		}
	};

	template<class T>
	struct is_integral: ft::integral_constant
	{
	public:
		typedef T		type;
	};

	//equal
	template<class InputLterator1, class InputLterator2>
	bool equal(InputLterator1 first1, InputLterator1 last1, InputLterator2 first2)
	{
		while(first1 != last1){
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template<class InputLterator1, class InputLterator2, class BinaryPredicate>
	bool equal(InputLterator1 first1, InputLterator1 last1, InputLterator2 first2, BinaryPredicate pred)
	{
		while(first1 != last1){
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	//lexicographical compare
	template<class InputLterator1, class InputLterator2>
	bool lexicographical_compare(InputLterator1 first1, InputLterator1 last1,
		InputLterator2 first2, InputLterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1) return false;
			else if (*first1 < *first2) return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<class InputLterator1, class InputLterator2, class Compare>
	bool lexicographical_compare(InputLterator1 first1, InputLterator1 last1,
		InputLterator2 first2, InputLterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}
#endif