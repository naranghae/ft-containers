
#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory> //std::allocator<T>
# include "../Iterator/random_access_iterator.hpp"
# include "../Iterator/reverse_iterator.hpp"

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
			this->alloc.destroy(this->base); // erase memory
		}

		//operator=
		vector&	operator=(const vector& x);

		//begin
		iterator begin();
		const_iterator begin() const;

		//end
		iterator end();
		const_iterator end() const;

		//rbegin
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		
		//rend
		reverse_iterator rend();
		const_reverse_iterator rend() const;

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
		void resize(size_type n, value_type val = value_type());

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
			if (n > this->capacity)
			{
				pointer new_base = this->alloc.allocate(n);
				for (size_type i = 0 ; i < this->size; i++)
					new_base[i] = this->base[i];
				this->alloc.deallocate(this->base, this->capacity);
				for (size_type i = 0 ; i < this->size; i++)
					this->alloc.destroy(&this->base[i]);
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
		reference front(size_type n);
		const_reference front(size_type n) const;		

		//back
		reference back(size_type n);
		const_reference back(size_type n) const;

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
		void pop_back();

		//insert
		iterator insert(iterator position, const value_type& val);
		void insert(iterator position, size_type n, const value_type& val);

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
	
		//erase
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);

		//swap
		void swap(Vector& x);

		//clear
		void clear();
	
		//get_allocator
		allocator_type get_allocator() const
		{
			allocator_type tmp = this->alloc;
			return tmp;
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
	void swap(Vector<T, Alloc>& x, Vector<T, Alloc>& y);
}
#endif
