#include <vector>
#include <iostream>
#include <type_traits>
//#include "vector.hpp"

bool mypredicate(int i, int j)
{
	return (i == j);
}

bool mycomp(char c1, char c2)
{
	return (std::tolower(c1) < std::tolower(c2));
}

int	main()
{
	std::vector<int> v(10);
	//ft::vector<int> v3(10);
	for(std::vector<int>::size_type i = 0; i < v.size() ;i++)
		v[i] = 1+i;
	// for(ft::vector<int>::size_type i = 0; i < v3.size() ;i++)
	// 	v3[i] = 1+i;
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i] << " " << v.size() << " " << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::vector<int> v2(10);
	// for(std::vector<int>::size_type i = 0; i < v.size() ;i++)
	// {
	// 	if (i < 5)
	// 		v2[i] = 1+i;
	// 	else
	// 		v2[i] = 11+i;
	// }
	// std::vector<int>::iterator it;
	// it = v.begin() + 1;

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
	// std::cout << std::endl;	
	// v.resize(15);
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
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
	//v2.assign(it, v.end() - 1);
	// v.insert(v.begin() + 1, v2.begin() + 3, v2.begin() + 6);	
	// for(std::vector<int>::size_type i = 0;i < v.size();i++)
	// 	std::cout << v[i]<< " " << v.size()<< " "  << v.capacity()<< std::endl;
	// std::cout << std::endl;
	// v2.assign(3, 11);
	// for(std::vector<int>::size_type i = 0;i < v2.size();i++)
	// 	std::cout << v2[i]<< " " << v2.size()<< " " << v2.capacity()<< std::endl;
	// std::cout << std::endl;
	//std::cout << v2.at(3) << std::endl;
	// for(std::vector<int>::size_type i = 0;i < v2.size();i++)
	// 	std::cout << v2[i]<< " " << v2.size()<< " " << v2.capacity()<< std::endl;
	// if (v == v2)
	// 	std::cout << "==="<< std::endl;
	return 0;
}