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
void test_vector_reverse_iter(long count){
	//print job name
	test_name = "-VECTOR REVERSE ITER TEST-";
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
		if (!num) continue;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		std::vector<int>::reverse_iterator it_rb = v1.rbegin();
		std::vector<int>::reverse_iterator it_re = v1.rend();
		ft::vector<int>::reverse_iterator its_rb = v2.rbegin();
		ft::vector<int>::reverse_iterator its_re = v2.rend();

		if (*it_rb != *its_rb)
			++err_count;
		if (it_rb - it_re != its_rb - its_re)
			++err_count;
		if (!ft::equal(it_rb, it_re, its_rb))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}

int main(){
	test_vector_reverse_iter(10000);
}