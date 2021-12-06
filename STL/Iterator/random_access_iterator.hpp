
#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP
# include "iterator_category.hpp"
# include "iter.hpp"

namespace ft
{
	template<typename T>
	class random_access_iterator
	{
	public:
		typedef	ft::iterator<ft::random_access_iterator_tag, T, ptrdiff_t, T*, T&> randomIter;
		typedef	typename randomIter::value_type				value_type;
		typedef	typename randomIter::difference_type		difference_type;
		typedef typename randomIter::pointer				pointer;
		typedef	typename randomIter::reference				reference;
		typedef	typename randomIter::iterator_category		iterator_category;

	private:
		pointer	ptr;

	public:		
		random_access_iterator(void): ptr(nullptr){};
		random_access_iterator(pointer _ptr): ptr(_ptr){}
		random_access_iterator(const random_access_iterator &src) : ptr(src.ptr){}
		~random_access_iterator() {}
		random_access_iterator	&operator=(const random_access_iterator &src)
		{
			if (this != &src)
				this->ptr = src.ptr;
			return *this;			
		}

		bool	operator==(const random_access_iterator &src) const
		{
			return this->ptr == src.ptr;
		}
	
		bool	operator!=(const random_access_iterator &src) const
		{
			return this->ptr != src.ptr;
		}

		reference	operator*(void) const
		{
			return *(this->ptr);
		}

		pointer		operator->(void) const
		{
			return this->ptr;
		}

		random_access_iterator<T>	&operator++() //prefix
		{
			ptr++;
			return *this;
		}

		random_access_iterator<T>	operator++(int) //postfix
		{
			random_access_iterator<T> post = *this;
			this->ptr++;
			return post;
		}

		random_access_iterator<T>	&operator--()
		{
			ptr--;
			return *this;
		}
	
		random_access_iterator<T>	operator--(int)
		{
			random_access_iterator<T> post = *this;
			this->ptr--;
			return post;
		}
	
		random_access_iterator<T>	operator+(difference_type n) const
		{
			random_access_iterator tmp(*this);
			tmp.ptr += n;
			return tmp;
		}

		random_access_iterator<T>	operator-(difference_type n) const
		{
			random_access_iterator tmp(*this);
			tmp.ptr -= n;
			return tmp;
		}

		random_access_iterator<T>	&operator+=(difference_type n)
		{
			this->ptr += n;
			return *this;
		}
		random_access_iterator<T>	&operator-=(difference_type n)
		{
			this->ptr -= n;
			return *this;
		}

		bool	operator<(const random_access_iterator &src) const
		{
			return this->ptr < src.ptr;
		}

		bool	operator>(const random_access_iterator &src) const
		{
			return this->ptr > src.ptr;
		}

		bool	operator<=(const random_access_iterator &src) const
		{
			return this->ptr <= src.ptr;
		}

		bool	operator>=(const random_access_iterator &src) const
		{
			return this->ptr >= src.ptr;
		}

		reference	operator[](difference_type n) const
		{
			return *(*(this) + n);
		}

	};


	template<typename T>
	typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs.ptr - rhs.ptr;
	}

	template<typename T>
	bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs.ptr < rhs.ptr;
	}

	template<typename T>
	bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs.ptr > rhs.ptr;
	}

	template<typename T>
	bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs.ptr <= rhs.ptr;
	}

	template<typename T>
	bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs.ptr >= rhs.ptr;
	}

	template<typename T>
	bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs.ptr == rhs.ptr;
	}

	template<typename T>
	bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs.ptr != rhs.ptr;
	}
}
#endif
