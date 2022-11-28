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
void test_vector_insert_iter(long count){
	//print job name
	test_name = "-VECTOR INSERT ITERATOR TEST-";
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
		std::vector<int> v1_s;
		ft::vector<int> v2;
		ft::vector<int> v2_s;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
			fill = rand() % M;
			v1_s.push_back(fill);
			v2_s.push_back(fill);
		}
		if (!num) continue;
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		v1.insert(it, v1_s.begin(), (v1_s.begin() + it_pos));
		v2.insert(its, v2_s.begin(), (v2_s.begin() + it_pos));
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!std::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(N, M);
    std::vector<int> v1_s(1, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.insert(v1.begin(), v1_s.begin(), v1_s.end());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(N, M);
	ft::vector<int> v2_s(N, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.insert(v2.begin(), v1_s.begin(), v1_s.end());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_insert_iter(10000);
}