
#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterators_traits.hpp"

namespace ft
{
	template<class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator 												iterator_type;
		typedef	typename iterators_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename terators_traits<Iterator>::value_type			value_type;
		typedef	typename terators_traits<Iterator>::difference_type		difference_type;
		typedef typename iterators_traits<Iterator>::pointer			pointer;
		typedef	typename iterators_traits<Iterator>::reference			reference;

	private:
			iterator_type	it;
	
	public:
		reverse_iterator(): it() {}
		explicit reverse_iterator(iterator_type it): it(it) {}

		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it): it(rev_it.it){}
		~reverse_iterator() {}
		iterator_type base() const {return this->it;} 

		reference operator*() const
		{
			iterator_type tmp = base();
			tmp--;
			return (*tmp);
		}

		reverse_iterator 	operator+(difference_type n) const
		{
			return (reverse_iterator(this->base() - n));
		}

		reverse_iterator	&operator++() //prefix
		{
			it--;
			return *this;
		}

		reverse_iterator	operator++(int) //postfix
		{
			reverse_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		reverse_iterator	&operator+=(difference_type n)
		{
			this->it -= n;
			return *this;
		}

		reverse_iterator	operator-(difference_type n) const
		{
			return (reverse_iterator(base() + n));
		}

		reverse_iterator	&operator--()
		{
			it++;
			return *this;
		}

		reverse_iterator	operator--(int)
		{
			reverse_iterator tmp(*this);
			--(*this);
			return tmp;
		}

		reverse_iterator	&operator-=(difference_type n)
		{
			it += n;
			return *this;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference	operator[](difference_type n) const
		{
			return this->it[-n - 1];
		}

	};

	template<class Iterator>
	bool	operator==(const reverse_iterator<Iterator> &lhs, 
						const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool	operator!=(const reverse_iterator<Iterator> &lhs, 
						const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool	operator<(const reverse_iterator<Iterator> &lhs, 
						const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class Iterator>
	bool	operator<=(const reverse_iterator<Iterator> &lhs, 
						const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<class Iterator>
	bool	operator>(const reverse_iterator<Iterator> &lhs, 
						const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool	operator>=(const reverse_iterator<Iterator> &lhs, 
						const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class Iterator>
	typename reverse_iterator<Iterator>::reverse_iterator operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &rev_it)
	{
		return rev_it + n;
	}

	template<class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() - rhs.base();
	}
}
#endif
