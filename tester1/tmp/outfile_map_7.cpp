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
void test_map_operator_at(long count) {
	//print job name
	test_name = "-MAP OPERATOR[] AT TEST-";
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
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
	        int  fill_n = rand() % M;
            v1.insert(std::make_pair<std::string, int>(fill, fill_n));
            v2.insert(ft::make_pair<std::string, int>(fill, fill_n));
        }
        std::string ref = getNewId();
        if (v1[ref] != v2[ref]) ++err_count;
		if (v1.size() != v2.size()) ++err_count;
        if (v1.at(ref) != v2.at(ref)) ++err_count;
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
        v1[fill_s];
        v1.at(fill_s);
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
        v2[fill_s];
        v2.at(fill_s);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_operator_at(10000);
}