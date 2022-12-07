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
void test_map_copy_ctor(long count) {
	//print job name
	test_name = "-MAP COPY CONSTRUCTOR TEST-";
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
		std::map<std::string, int> v1_r(v1);
		ft::map<std::string, int> v2_r(v2);
		int std_res = v1_r.size();
		int ft_res = v2_r.size();
		if (std_res != ft_res)
		{ 
			++err_count;
			std::cout << "std size: " << std_res << " ft size : " << ft_res << std::endl;
		}
		if (!std::equal(v1_r.begin(),v1_r.end(),v2_r.begin()))
			++err_count;
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
	    std::map<std::string, int> v1_r(v1);
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
		ft::map<std::string, int> v2_r(v2);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_copy_ctor(10000);
}