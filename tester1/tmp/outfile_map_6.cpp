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
void test_map_rbegin_rend(long count) {
	//print job name
	test_name = "-MAP RBEGIN REND ITERS TEST-";
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
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
        if (!num) continue;
		std::map<std::string, int>::reverse_iterator it = v1.rbegin();
		ft::map<std::string, int>::reverse_iterator it_ft = v2.rbegin();
		if (*it != *it_ft) ++err_count;
        std::map<std::string, int>::const_reverse_iterator c_it = v1.rbegin();
		ft::map<std::string, int>::const_reverse_iterator c_it_ft = v2.rbegin();
		if (*c_it != *c_it_ft) ++err_count;
        std::map<std::string, int>::reverse_iterator eit = v1.rend();
		ft::map<std::string, int>::reverse_iterator eit_ft = v2.rend();
        if (*(--eit) != *(--eit_ft)) ++err_count;
        std::map<std::string, int>::const_reverse_iterator c_eit = v1.rend();
		ft::map<std::string, int>::const_reverse_iterator c_eit_ft = v2.rend();
        if (*(--c_eit) != *--(c_eit_ft)) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    size_t num = rand() % N;
	std::map<std::string, int> v1;
    for (size_t i = 0; i < num; ++i) {
	    std::string fill = getNewId();
        v1.insert(std::make_pair<std::string, int>(fill, N));
    }
	timer_start();
	for (int i = 0; i < count; ++i){
	    v1.rbegin();
        v1.rend();
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
	for (int i = 0; i < count; ++i){
		v2.rbegin();
        v2.rend();
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_rbegin_rend(10000);
}