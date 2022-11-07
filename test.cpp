#include "stack.hpp"
#include <stack>
#include <vector>
#include <iostream>

#include <memory>

using namespace std;

class S
{
private:
   int a;
public:
   S(int a) : a(a)
   {
      cout << "기본 생성자" << endl;
   }

   S(const S& a)
   {
      this->a = a.a;
      cout << "복사 생성자" << endl;
   }

   ~S()
   {

   }
};

int main()
{
   vector<shared_ptr<S> > v;

   auto s = make_shared<S>(10);
//    v.push_back(s);
//    cout << v[0].use_count() << endl;
//    v.push_back(make_shared<S>(20));
//    cout << v[1].use_count() << endl;

   for (auto i : v)
   {
      cout<<i.use_count()<<endl;
   }
   return 0;
}

// int main()
// {
// 	// stack

// 	// std::stack<int> s;
// 	// s.push(5);

// 	// std::stack<int> a(s);
// 	// std::cout << a.top();

// 	// ft::stack<int> s;
// 	// s.push(5);

// 	// ft::stack<int> a(s);
// 	// // std::cout << a.top();

// 	// std::cout << (s == a) << (s > a);


// 	// vector

// 	// std::vector<int> a;
// 	// std::vector<int> b;

// 	// std::vector<int>::iterator iter1;
// 	// std::vector<int>::iterator iter2;

// 	// a.push_back(1);
// 	// a.push_back(2);
// 	// a.push_back(3);

// 	// iter1 = a.begin();
// 	// iter2 = a.end();

// 	// std::cout << (iter2 - iter1);

	

// 	return 0;
// }