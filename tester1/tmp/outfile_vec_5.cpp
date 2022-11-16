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
void test_vector_size_capacity_random(long count){
	//print job name
	test_name = "-VECTOR SIZE CAPACITY RANDOM TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = 99;
	srand(time(NULL));
	{ //random test: size, capacity, empty

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
	size_t num = rand() % N;
	int fill = rand() % std::numeric_limits<int>::max();
	std::vector<int> v1(num, fill);
	ft::vector<int> v2(num, fill);
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		std_res = v1.capacity();
		ft_res = v2.capacity();
		if (std_res != ft_res)
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
    std::vector<int> v1(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.size();
		v1.capacity();
		v1.empty();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.size();
		v2.capacity();
		v2.empty();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_size_capacity_random(20000);
}