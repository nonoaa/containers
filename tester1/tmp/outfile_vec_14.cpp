#include <iostream>
#include "test_utils.hpp"
#include <vector>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "type_traits.hpp"
#include "vector.hpp"

extern std::string	test_name;
void test_vector_swap(long count){
	//print job name
	test_name = "-VECTOR SWAP TEST-";
	print_test_name(count);

	//init
    const size_t N1 = 21;
    const size_t N2 = 42;
    const int M1 = 99;
    const int M2 = 44;
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		ft::vector<int> v1(N1, M1);
		ft::vector<int> v2(N2, M2);

		v1.swap(v2);
		if (v1.size() != N2) ++err_count;
		if (v2.size() != N1) ++err_count;
		if (*(v1.begin()) != M2) ++err_count;
		if (*(v2.begin()) != M1) ++err_count;
		if (v1.capacity() != N2) ++err_count;
		if (v2.capacity() != N1) ++err_count;
		
		ft::swap(v1, v2);
		if (v1.size() != N1) ++err_count;
		if (v2.size() != N2) ++err_count;
		if (*(v1.begin()) != M1) ++err_count;
		if (*(v2.begin()) != M2) ++err_count;
		if (v1.capacity() != N1) ++err_count;
		if (v2.capacity() != N2) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
	
	//std working
    std::vector<int> v1(count, M1);
    std::vector<int> v2(count, M2);
	timer_start();
	for (int i = 0; i < count; ++i)
	v1.swap(v2);
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v3(count, M1);
	ft::vector<int> v4(count, M2);
	timer_start();
	for (int i = 0; i < count; ++i)
	v3.swap(v4);
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_swap(20000);
}