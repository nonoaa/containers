#include <iostream>
#include "test_utils.hpp"
#include <vector>
#include "algorithm.hpp"
#include "iterator.hpp"
#include "map.hpp"
#include "rb_tree.hpp"
#include "stack.hpp"
#include "type_traits.hpp"
#include "vector.hpp"

extern std::string	test_name;
void test_vector_size_capacity_empty(long count){
	//print job name
	test_name = "-VECTOR SIZE CAPACITY EMPTY TEST-";
	print_test_name(count);

	{ //0 test: size, capacity, empty, max_size
	std::vector<int> v1;
	ft::vector<int> v2;

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		std_res = v1.capacity();
		ft_res = v2.capacity();
		if (std_res != ft_res)
			++err_count;
		size_t std_res_t = v1.max_size();
		size_t ft_res_t = v2.max_size();
		if (std_res_t != ft_res_t)
			++err_count;
		bool std_res_b = v1.empty();
		bool ft_res_b = v2.empty();
		if (std_res_b != ft_res_b)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
	
	//std working
    std::vector<int> v1;
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.size();
		v1.capacity();
		v1.max_size();
		v1.empty();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2;
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.size();
		v2.capacity();
		v2.max_size();
		v2.empty();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_size_capacity_empty(10000);
}