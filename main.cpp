#include <vector>
#include <iostream>

int	main()
{
	std::vector<int> v(10);
	for(std::vector<int>::size_type i = 0; i < v.size() ;i++)
		v[i] = 1+i;
	for(std::vector<int>::size_type i = 0; i < v.size();i++)
		std::cout << v[i] ;
	std::cout << std::endl;
	std::vector<int> v2(10);
	for(std::vector<int>::size_type i = 0; i < v.size() ;i++)
		v2[i] = 10+i;
	// v.resize(7, 10);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i] << " " << v.size() << " " << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// v.resize(5);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i] << " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// v.resize(7);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	
	// v.resize(15);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;

	// v.resize(4);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// v.resize(7, 5);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// v.erase(v.begin() + 1, v.begin() + 3);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// v.insert(v.begin() + 1, 12, 9);	
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// v.insert(v.begin() + 1, v.begin() + 3, v.begin() + 6);	
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
	v.insert(v.begin() + 1, v2.begin() + 3, v2.begin() + 6);	
	for(std::vector<int>::size_type i = 0;i < v.size();i++)
		std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	std::cout << std::endl;
	for(std::vector<int>::size_type i = 0;i < v2.size();i++)
		std::cout << v2[i]<< " " << v2.size()<< " " << v2.capacity()<< std::endl;

	return 0;
}