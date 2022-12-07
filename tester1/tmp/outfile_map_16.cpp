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
void test_map_erase_pos(long count) {
	//print job name
	test_name = "-MAP ERASE POS TEST-";
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
	    size_t num = rand() % N + 1;
	    std::map<std::string, int> v1;
	    ft::map<std::string, int> v2;
        for (size_t i = 0; i < num; ++i) {
	        std::string fill = getNewId();
	        int  fill_n = rand() % M;
            v1.insert(std::make_pair<std::string, int>(fill, fill_n));
            v2.insert(ft::make_pair<std::string, int>(fill, fill_n));
        }
		if (v1.size() != v2.size())  ++err_count;
		v1.erase(v1.begin());
		v2.erase(v2.begin());
		if(v1.empty() != v2.empty()) ++err_count;
		if (v1.size() != v2.size())  ++err_count;
		if (!std::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = count;
	std::map<std::string, int> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(std::make_pair<std::string, int>(fill, N));
    }
	timer_start();
	for (size_t i = 0; i < num; ++i){
		v1.erase(v1.begin());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working
	ft::map<std::string, int> v2;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v2.insert(ft::make_pair<std::string, int>(fill, N));
    }
	timer_start();
	for (size_t i = 0; i < num; ++i){
		v2.erase(v2.begin());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_erase_pos(10000);
}