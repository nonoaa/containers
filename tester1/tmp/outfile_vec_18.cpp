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
void test_vector_comparison(long count){
	//print job name
	test_name = "-VECTOR COMPARISON TEST-";
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
		std::vector<int> v1(N);
		std::vector<int> v1_s(N);
		ft::vector<int> v2(N);
		ft::vector<int> v2_s(N);
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v1_s.push_back(fill);
			v2.push_back(fill);
			v2_s.push_back(fill);
		}
		if ((v1==v1_s) != (v2==v2_s)) ++err_count;
		if ((v1<v1_s) != (v2<v2_s)) ++err_count;
		if ((v1!=v1_s) != (v2!=v2_s)) ++err_count;
		if ((v1>v1_s) != (v2>v2_s)) ++err_count;
		if ((v1<=v1_s) != (v2<=v2_s)) ++err_count;
		if ((v1>=v1_s) != (v2>=v2_s)) ++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}
}

int main(){
	test_vector_comparison(10000);
}