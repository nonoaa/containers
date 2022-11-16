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
void test_vector_copy_ctor(long count){
	//print job name
	test_name = "-VECTOR COPY CONSTRUCTOR TEST-";
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
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		// if (!num) continue;
		std::vector<int> v1_r(v1);
		ft::vector<int> v2_r(v2);
		int std_res = v1_r.size();
		int ft_res = v2_r.size();
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
		if (!std::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
	    std::vector<int> v1_r(v1);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::vector<int> v2(N * N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::vector<int> v2_r(v2);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_copy_ctor(20000);
}