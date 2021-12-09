
#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory> //std::allocator<T>
# include "../Iterator/random_access_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"
# include "../Share/utils.hpp"

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
	
	private:
		allocator_type		alloc;
		pointer				base; //elements storage.
		size_type			size; // the number of elements actually stored in the vector.
		size_type			capacity; //maximum allocated size of vector

		void shiftElement(difference_type idx, size_type n)
		{
			for(size_type i = 0; i < n; i++)
				this->alloc.construct(&base[idx + n + i], this->base[idx + i]);
			for(size_type i = 0; i < n; i++)
				this->alloc.construct(&base[idx + i], 0);
		}
	public:
		//constructor
		explicit	Vector(const allocator_type& _alloc = allocator_type())
			: alloc(_alloc), base(0), size(0), capacity(0) // vector<T>()
		{
			this->base = this->alloc.allocate(0);
		}

		explicit	Vector(size_type n, const value_type& val = value_type(),
						const allocator_type& _alloc = allocator_type())
			: alloc(_alloc), base(0), size(0), capacity(0) // vector<T>(n)
		{

		}
		
		template<class InputIterator>
		Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		
		Vector(const Vector &x);

		//destructor
		~vector()
		{
			this->clear(); //delete element
			this->alloc.deallocate(this->base, this->capacity); //free memory space.
		}

		//operator=
		vector&	operator=(const vector& x);

		//begin
		iterator begin()
		{
			return (iterator(this->base));
		}
		const_iterator begin() const
		{
			return (const_iterator(this->base));
		}

		//end
		iterator end()
		{
			return (iterator(this->base + this->size));
		}
		const_iterator end() const
		{
			return (const_iterator(this->base + this->size));
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
			return this->size;
		}

		//max_size
		size_type max_size() const
		{
			return (std::numeric_limits<difference_type>::max());
		}

		//resize
		void resize(size_type n, value_type val = value_type())
		{
			this->reserve(n);
			for (size_type i = this->size; i < this->capacity; i++)
			{
				if (val)
					this->base[i] = val;
				else
					this->base[i] = 0;
			}
			this->size = n;
		}

		//capacity
		size_type capacity() const
		{
			return this->capacity;
		}

		//empty
		bool empty() const
		{
			return (this->size == 0);
		}

		//reserve
		void reserve(size_type n)
		{
			if (this->capacity < n)
			{
				pointer new_base = this->alloc.allocate(n);
				for (size_type i = 0 ; i < this->size; i++)
				{
					new_base[i] = this->base[i];
					this->alloc.destroy(&this->base[i]);
				}
				this->alloc.deallocate(this->base, this->capacity);
				this->base = new_base;
				this->capacity = n; 
			}
		}

		//operator[]
		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		
		//at
		reference at(size_type n);
		const_reference at(size_type n) const;

		//front
		reference front(size_type n)
		{
			return base[0];
		}
		const_reference front(size_type n) const
		{
			return base[0];
		}	

		//back
		reference back(size_type n)
		{
			return base[this->size - 1];
		}
		const_reference back(size_type n) const
		{
			return base[this->size - 1];
		}

		//assign
		template<class InputIterator>
		void assign(InputIterator first, InputIterator last);

		void assign(size_type n, const value_type& val);

		//push_back
		void push_back(const value_type& val)
		{
			if (this->size < this->capacity)
			{
				this->base[this->size] = val;
				(this->size)++;
			}
			else
			{
				this->reserve(this->capacity + (this->capacity / 2));
				this->push_back(val);
			}
		}
	
		//pop_back
		void pop_back()
		{
			this->erase(this->end() - 1);
		}

		//insert
		iterator insert(iterator position, const value_type& val)
		{
			difference_type idx = position - this->begin();
			insert(position, 1, val);
			return (this->begin() + idx);
		}
		void insert(iterator position, size_type n, const value_type& val)
		{
			difference_type idx = position - this->begin();
			this->reserve(this->size + n);
			shiftElement(idx, n);
			for(size_type i = 0; i < n; i++)
				this->alloc.construct(&base[idx + i], val);
			this->size += n;
		}
		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			difference_type n = last - first;
			difference_type idx = position - begin();

			this->reserve(this->size + n);
			shiftElement(idx, n);
			for(size_type i = 0; i < n; i++)
				this->alloc.construct(&base[idx + i], *(first + i));
			this->size += n;
		}
	
		//erase
		iterator erase(iterator position)
		{
			return erase(position, position + 1);
		}
		iterator erase(iterator first, iterator last)
		{
			difference_type range = last - first;
			difference_type start = first - this->begin();
			difference_type end = start + range;
			for(difference_type i = start; i < end; i++)
				this->alloc.destroy(base + i);
			for (difference_type i = end; i < this->size(); i++)
			{
				this->alloc.construct(&base[i - range], base[i]);
				this->alloc.destroy(&base[i]);
			}
			this->size -= range;
			return first;
		}

		//swap
		void swap(Vector& x)
		{
			pointer	tmp_base = this->base;
			size_type tmp_size = this->size;
			size_type tmp_capacity = this->capacity;
			
			this->base = x.base;
			this->size = x.size;
			this->capacity = x.capacity;

			x.base = tmp_base;
			x.size = tmp_size;
			x.capacity  = tmp_capacity;
		}

		//clear
		void clear()
		{
			this->erase(this->begin(), this->end());
			this->size = 0;
		}
	
		//get_allocator
		allocator_type get_allocator() const
		{
			allocator_type getAllo = this->alloc;
			return getAllo;
		}
	};

	//relational operator (==, !=, <, <=, >, >=)
	template<class T, class Alloc>
	bool operator==(const Vector<T, Alloc>& lhs, 
					const Vector<T, Alloc>& rhs);

	template<class T, class Alloc>
	bool operator!=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs);

	template<class T, class Alloc>
	bool operator<(const Vector<T, Alloc>& lhs, 
					const Vector<T, Alloc>& rhs);

	template<class T, class Alloc>
	bool operator<=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs);

	template<class T, class Alloc>
	bool operator>(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs);

	template<class T, class Alloc>
	bool operator>=(const Vector<T, Alloc>& lhs,
					const Vector<T, Alloc>& rhs);

	
	//swap
	template<class T, class Alloc>
	void swap(Vector<T, Alloc>& x, Vector<T, Alloc>& y)
	{
		x.swap(y);
	}
}
#endif
