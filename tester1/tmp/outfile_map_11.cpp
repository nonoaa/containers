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
void test_map_find(long count) {
	//print job name
	test_name = "-MAP FIND TEST-";
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
		ptrdiff_t d1 = std::distance(v1.begin(), v1.find(ref));
		ptrdiff_t d2 = std::distance(v2.begin(), v2.find(ref));
        if (d1 != d2) ++err_count;
		d1 = std::distance(v1.begin(), v1.find(save_to_find));
		d2 = std::distance(v2.begin(), v2.find(save_to_find));
        if (d1 != d2){
			 ++err_count;
			//  std::cout << "distance std : " << d1 << std::endl;
			//  std::cout << "distance ft : " << d2 << std::endl;
		}
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
		v1.find(fill_s);
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
		v2.find(fill_s);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_find(10000);
}