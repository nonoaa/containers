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
void test_map_empty_ctor(long count){
	//print job name
	test_name = "-MAP EMPTY CONSTRUCTION TEST-";
	print_test_name(count);

	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
		std::map<std::string, int> p1;
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;

	//ft working
	timer_start();
	for (int i = 0; i < count; ++i){
		ft::map<std::string, int> p2;
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_map_empty_ctor(10000);
}