#ifndef IMPLEMENT_HPP
# define IMPLEMENT_HPP

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
		static const T 					value = v;
		typedef T 						value_type;
		typedef integral_constant<T, v> type;
		const operator T() {return v;}
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;	

	template<class T>
	struct is_integral: public false_type {};
	template<>
	struct is_integral<bool>: public true_type {};
	template<>
	struct is_integral<char>: public true_type {};
	template<>
	struct is_integral<char16_t>: public true_type {};
	template<>
	struct is_integral<char32_t>: public true_type {};
	template<>
	struct is_integral<wchar_t>: public true_type {};
	template<>
	struct is_integral<signed char>: public true_type {};
	template<>
	struct is_integral<short int>: public true_type {};
	template<>
	struct is_integral<int>: public true_type {};
	template<>
	struct is_integral<long int>: public true_type {};
	template<>
	struct is_integral<long long int>: public true_type {};
	template<>
	struct is_integral<unsigned char>: public true_type {};
	template<>
	struct is_integral<unsigned short int>: public true_type {};
	template<>
	struct is_integral<unsigned int>: public true_type {};
	template<>
	struct is_integral<unsigned long int>: public true_type {};
	template<>
	struct is_integral<unsigned long long int>: public true_type {};

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
