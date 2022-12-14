#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "test_utils.hpp"
#include "algorithm.hpp"
#include "iterator.hpp"
#include "map.hpp"
#include "pair.hpp"
#include "rb_tree.hpp"
#include "set.hpp"
#include "stack.hpp"
#include "type_traits.hpp"
#include "utilities.hpp"
#include "vector.hpp"

extern std::string	test_name;
void test_map_size_empty_max(long count) {
	//print job name
	test_name = "-MAP SIZE EMPTY MAX TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = 99;
	srand(time(NULL));
	{ 
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i){
	    size_t num = rand() % N;
	    std::map<std::string, int> v1;
	    ft::map<std::string, int> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
	        int  fill_n = rand() % M;
            v1.insert(std::make_pair<std::string, int>(fill, fill_n));
            v2.insert(ft::make_pair<std::string, int>(fill, fill_n));
        }
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        std_res = v1.max_size();
        ft_res = v2.max_size();
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
	std::map<std::string, int> v1;
	timer_start();
	for (int i = 0; i < count * 100; ++i){
		v1.size();
		v1.max_size();
		v1.empty();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	    ft::map<std::string, int> v2;
	timer_start();
	for (int i = 0; i < count * 100; ++i){
		v2.size();
		v2.max_size();
		v2.empty();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_size_empty_max(10000);
}