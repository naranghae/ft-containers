#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T>>
	class stack
	{
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t			size_type;
	private:
		container_type	_c;

	public:
		explicit stack(const container_type& ctnr = container_type());

		bool empty() const
		{
			return _c.empty();
		}

		size_type size() const
		{
			return _c.size();
		}

		value_type& top()
		{
			return _c.back();
		}

		const value_type& top() const
		{
			return _c.back();	
		}

		void push(const value_type& val)
		{
			_c.push_back(val);
		}

		void pop()
		{
			_c.pop_back();
		}
	};

	template<class T, class Container>
	stack<T, Container>::stack(const container_type& ctnr = container_type())
		:_c(ctnr) {}

	//relational operator (==, !=, <, <=, >, >=)
	template<class T, class Container>
	bool operator==(const stack<T, Container>& lhs, 
					const stack<T, Container>& rhs)
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Container>
	bool operator!=(const stack<T, Container>& lhs,
					const stack<T, Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Container>
	bool operator<(const stack<T, Container>& lhs, 
					const stack<T, Container>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Container>
	bool operator<=(const stack<T, Container>& lhs,
					const stack<T, Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class Container>
	bool operator>(const stack<T, Container>& lhs,
					const stack<T, Container>& rhs)
	{
		return rhs < lhs;
	}

	template<class T, class Container>
	bool operator>=(const stack<T, Container>& lhs,
					const stack<T, Container>& rhs)
	{
		return !(lhs < rhs);
	}
}
#endif