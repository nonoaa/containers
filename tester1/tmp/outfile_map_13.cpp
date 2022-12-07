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
void test_map_count_clear(long count) {
	//print job name
	test_name = "-MAP COUNT CLEAR TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count / 3; ++i) {
	    size_t num = rand() % N;
	    std::map<std::string, int> v1;
	    ft::map<std::string, int> v2;
		std::string save_to_find;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
	        int  fill_n = rand() % M;
            v1.insert(std::make_pair<std::string, int>(fill, fill_n));
            v2.insert(ft::make_pair<std::string, int>(fill, fill_n));
			save_to_find = fill;
        }
        std::string ref = getNewId();
		size_t d1 = v1.count(ref);
		size_t d2 = v2.count(ref);
        if (d1 != d2) ++err_count;
		d1 = v1.count(save_to_find);
		d2 = v2.count(save_to_find);
        if (d1 != d2) ++err_count;
		v1.clear();
		v2.clear();
		d1 = v1.count(save_to_find);
		d2 = v2.count(save_to_find);
        if (d1 != d2) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::map<std::string, int> v1;
    std::string fill_s;
    for (size_t i = 0; i < num; ++i) {
	    fill_s = getNewId();
        v1.insert(std::make_pair<std::string, int>(fill_s, N));
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.count(fill_s);
		v1.clear();
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::map<std::string, int> v2;
    for (size_t i = 0; i < num; ++i) {
	    fill_s = getNewId();
        v2.insert(ft::make_pair<std::string, int>(fill_s, N));
    }
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.count(fill_s);
		v2.clear();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_count_clear(10000);
}