
#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory> //std::allocator<T>
# include "../Iterator/random_access_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"
# include "../Share/implement.hpp"
# include "../Share/utils.hpp"

namespace ft
{
	template<typename T, typename _Alloc = std::allocator<T>>
	class vector
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
	
	private:
		allocator_type		_alloc;
		pointer				_start; // array first.
		pointer				_finish; // array last.
		pointer				_end_of_storage; //maximum allocated size of vector

	public:
		//empty constructor
		explicit	vector(const allocator_type& alloc = allocator_type());

		//element fill constructor
		explicit	vector(size_type n, const value_type& val = value_type(),
						const allocator_type& _alloc = allocator_type());
		
		//range constructor
		template<class InputIterator>
		vector(InputIterator first, InputIterator last, 
					const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0));
		
		//copy constructor
		vector(const vector &x);

		//destructor
		~vector();

		//operator=
		vector&	operator=(const vector& x);

		//begin
		iterator begin()
		{
			return (iterator(this->_start));
		}

		const_iterator begin() const
		{
			return (const_iterator(this->_start));
		}

		//end
		iterator end()
		{
			return (iterator(this->_finish));
		}
		const_iterator end() const
		{
			return (const_iterator(this->_finish));
		}

		//rbegin
		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}
		
		//rend
		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}

		//size
		size_type size() const
		{
			return static_cast<size_type>(_finish - _start);
		}

		//max_size
		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max()/sizeof(value_type));
		}

		//resize
		void resize(size_type n, value_type val = value_type())
		{
			size_type size = ft::vector<T>::size();
			if (n < size)
				erase(begin() + n, end());
			else if (n > size)
			{
				if (n > capacity())
					reserve(n);
				insert(end(), n - size, val);
			} 
		}

		//capacity
		size_type capacity() const
		{
			return static_cast<size_type>(_end_of_storage - _start);
		}

		//empty
		bool empty() const
		{
			return  begin() == end();
		}

  	protected:
		void reallocate(size_type n) const
		{
			pointer new_array = this->_alloc.allocate(n);
			size_type size = this->size();
			for (size_type i = 0 ; i < this->size; i++)
			{
				this->_alloc.construct(&new_array[i], _start[i]);
				this->_alloc.destroy(&_start[i]);
			}
			this->_alloc.deallocate(_start, capacity());
			_start = new_array;
			_finish = _start + size;
			_end_of_storage = _start + n;
		}

		size_type sizeCheck(size_type n) const
		{
			size_type max_size = this->max_size();
			size_type capacity = this->capacity();

			if (max_size < n)
				throw std::length_error("ft::vecvor::size error");
			if ((max_size / 2) < capacity)
				return max_size;
			return ft::max<size_type>(capacity + (capacity / 2), n);
		}

	public:
		//reserve
		void reserve(size_type n)
		{
			if (max_size() < n)
				throw std::out_of_range("ft::vector::reserve Error");
			if (capacity() < n)
				reallocate(sizeCheck(n));
		}

		//operator[]
		reference operator[](size_type n)
		{
			return *(this->_start + n);
		}
		const_reference operator[](size_type n) const
		{
			return *(this->_start + n);
		}

  	protected:
		void range_check(size_type n) const
		{
			if (n >= this->size())
				throw std::out_of_range("ft::vector::at Index Error");
		}

	public:
		//at
		reference at(size_type n)
		{	
			range_check(n); 
			return _start[n]; 
		}

		const_reference at(size_type n) const
		{
			range_check(n); 
			return _start[n]; 
		}

		//front
		reference front()
		{
			return *begin();
		}
		const_reference front() const
		{
			return *begin();
		}	

		//back
		reference back()
		{
			return *(end() - 1);
		}
		const_reference back() const
		{
			return *(end() - 1);
		}
		//assign
		template<class InputIterator>
		void	assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0))
		{
			clear();
			insert(begin(), first, last);
		}
		void assign(size_type n, const value_type& val) //val:value, n: count
		{
			clear();
			insert(begin(), n, val);
		}
		//push_back
		void push_back(const value_type& val)
		{
			if (this->_finish != this->_end_of_storage)
			{
				this->alloc.construct(this->_finish, val);
				++this->_finish;
			}
			else
				insert(end(), val);
		}
		//pop_back
		void pop_back()
		{
			if (!empty())
			{
				--this->_finish;
				this->alloc.destroy(this->_finish);
			}
		}
		//insert
		iterator insert(iterator position, const value_type& val)
		{
			difference_type idx = position - this->begin();
			insert(position, 1, val);
			return (begin() + idx);
		}
		void insert(iterator position, size_type n, const value_type& val)
		{
			if (n == 0)
				return ;
			difference_type idx = position - this->begin();
			difference_type distance = this->end() - this->begin();
			difference_type capacity = capacity();
			if (capacity - distance < n)
				reallocate(sizeCheck(n)));
			for (size_type i = distance; i > idx; i--)
				this->_alloc.construct(&_start[idx + (i - 1) + n], _start[idx + (i - 1)]);			
			for(size_type i = 0; i < n; i++)
				this->_alloc.construct((&_start[idx + i], val);
			this->_finish += n;
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			if (first == last)
				return ;
			difference_type n = last - first;
			difference_type idx = position - begin();
			difference_type distance = end() - begin();
			difference_type capacity = capacity();
			if (capacity - distance < n)
				reallocate(sizeCheck(n)));
			for (size_type i = distance; i > idx; i--)
				this->_alloc.construct(&_start[idx + (i - 1) + n], _start[idx + (i - 1)]);			
			for(size_type i = 0; i < n; i++)
				this->_alloc.construct((&_start[idx + i], _start[i]);
			this->_finish += n;
		}
	
		//erase
		iterator erase(iterator position)
		{
			return erase(position, position + 1);
		}
		iterator erase(iterator first, iterator last)
		{
			if (first == last)
				return first;
			difference_type n = last - first;
			difference_type start = first - this->begin();
			difference_type end = start + n;
			for(difference_type i = start; i < end; i++)
				this->_alloc.destroy(&_start[i]);
			for (difference_type i = end; i < this->size(); i++)
			{
				this->_alloc.construct(&_start[i - n], _start[i]);
				this->_alloc.destroy(&_start[i]);
			}
			this->_finish -= n;
			return first;
		}

		//swap
		void swap(vector& x)
		{
			if (*this != x)
			{
				ft::swaping(this->_start, x._start);
				ft::swaping(this->_finish, x._finish);
				ft::swaping(this->_end_of_storage, x._end_of_storage);
			}
		}

		//clear
		void clear()
		{
			this->erase(this->begin(), this->end());
			this->_finish = this->_start;
		}
	
		//get_allocator
		allocator_type get_allocator() const
		{
			return this->_alloc;
		}
	};

	//empty constructor
	template<class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type& alloc = allocator_type())
		:_alloc(alloc), _start(0), _finish(0), _end_of_storage(0){}
 
	//element fill constructor
	template<class T, class Alloc>
	vector<T, Alloc>::vector(size_type n, const value_type& val = value_type(),
						const allocator_type& _alloc = allocator_type())
		:_alloc(alloc), _start(0), _finish(0), _end_of_storage(0)
	{
		size_type capacity = sizeCheck(n);
		_start = this->_alloc.allocate(capacity);
		_finish =  _start + n;
		_end_of_storage = _start + capacity;
		for (size_type i = 0; i < n; i++)
			this->_alloc.construct(_start + i, val);
	}
		
	//range constructor
	template<class T, class Alloc>
	template<class InputIterator>
	vector<T, Alloc>::vector(InputIterator first, InputIterator last, 
			const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		:_alloc(alloc), _start(0), _finish(0), _end_of_storage(0)
	{
		size_type n = last - first;
		size_type capacity = sizeCheck(n);
		_start = this->_alloc.allocate(capacity, this);
		_finish =  _start + n;
		_end_of_storage = _start + capacity;
		for(size_type i = 0; i < n; i++)
			this->_alloc.construct(&_start[i], first[i]);
	}
		
	//copy constructor
	template<class T, class Alloc>
	vector<T, Alloc>::vector(const vector &x)
	:_alloc(x.get_allocator())
	{
		_start = _alloc.allocate(x.capacity(), this);
		_finish = _start + x.size();
		_end_of_storage = _start + x.capacity();
		for (size_type i = 0; i < x.size(); i++)
			_alloc.construct(&_start[i], x._start[i]);
	}

	//destructor
	template<class T, class Alloc>
	vector<T, Alloc>::~vector()
	{
		clear();
		this->_alloc.deallocate(_start, capacity());
		this->_start = NULL;
		this->_finish = NULL;
		this->_end_of_storage = NULL;
	}

	//operator=
	template<class T, class Alloc>
	vector<T, Alloc>& ft::vector<T, Alloc>::operator=(const vector& x)
	{
		this->assign(x.begin(), x.end());
		return *this;
	}


	//relational operator (==, !=, <, <=, >, >=)
	template<class T, class _Alloc>
	bool operator==(const vector<T, _Alloc>& lhs, 
					const vector<T, _Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class _Alloc>
	bool operator!=(const vector<T, _Alloc>& lhs,
					const vector<T, _Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class _Alloc>
	bool operator<(const vector<T, _Alloc>& lhs, 
					const vector<T, _Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class _Alloc>
	bool operator<=(const vector<T, _Alloc>& lhs,
					const vector<T, _Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class _Alloc>
	bool operator>(const vector<T, _Alloc>& lhs,
					const vector<T, _Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template<class T, class _Alloc>
	bool operator>=(const vector<T, _Alloc>& lhs,
					const vector<T, _Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
	
	//swap
	template<class T, class _Alloc>
	void swap(vector<T, _Alloc>& x, vector<T, _Alloc>& y)
	{
		x.swap(y);
	}
}
#endif
