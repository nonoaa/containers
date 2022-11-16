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
void test_vector_assign_n(long count){
	//print job name
	test_name = "-VECTOR ASSIGN NUM TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		int fill = rand() % M;
		std::vector<int> v1;
		ft::vector<int> v2;

		v1.assign(num, fill);
		v2.assign(num, fill);
		int std_res = v1.size();
		int ft_res = v2.size();
#if PRINT
		std::cout << "v1 size: " << std_res << " v2_size: " << ft_res << std::endl;
		std::cout << "std content:\n";
		for (size_t i = 0; i < v1_r.size(); ++i){
			std::cout << *(v1_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
		std::cout << "ft content:\n";
		for (size_t i = 0; i < v2_r.size(); ++i){
			std::cout << *(v2_r.begin() + i) << " "; 
		}
		std::cout << std::endl;
#endif
		if (std_res != ft_res)
			++err_count;
		if (!std::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
    std::vector<int> v1;
		v1.assign(N * N, M);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
	ft::vector<int> v2;
		v2.assign(N * N, M);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_assign_n(20000);
}