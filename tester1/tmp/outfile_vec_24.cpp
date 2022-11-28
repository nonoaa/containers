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
void test_vector_access(long count){
	//print job name
	test_name = "-VECTOR ACCESS TEST-";
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
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res) ++err_count;
		if (v1.front() != v2.front()) ++err_count;
		if (v1.back() != v2.back()) ++err_count;
		size_t pos = rand() % num;
		if (v1.at(pos) != v2.at(pos)) ++err_count;
		if (v1[pos] != v2[pos]) ++err_count;

	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}

int main(){
	test_vector_access(10000);
}