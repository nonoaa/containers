# containers
+ C++ STL의 컨테이너들을 직접 구현하며 학습한 내용

## Allocator
+ 메모리 관리를 좀 더 세밀하게 컨트롤하고 유연하고 효율적으로 사용해야할 때 (주로 라이브러리를 작성할 때, 특히 표준 라이브러리의 컨테이너를 구현할 때) 많이 사용된다.
+ new 연산자는 값의 초기화를 진행하기 때문에 초기화되지 않은 공간으로 메모리 할당을 하는 Allocator에 비해 자원 소모량이 크다.
+ 주로 다음 4개의 멤버함수와 비멤버 함수를 사용한다.
	```cpp
	template <class T>
	class allocator
	{
	public:
	T* allocate(size_t);
	void deallocate(T*, size_t);
	void construct(T*, const T&);
	void destory(T*);
	
	....
	};

	template <class In, class For>
	For uninitialized_copy(In, In, For);

	template <class For, class T>
	void uninitialized_fill(For, For, const T&);
	```
	+ T* allocate(size_t);
		+ 초기화되지 않은 메모리를 할당하고 그 시작 주소를 반환하는 함수
		+ 매개변수는 T객체의 개수이다.
		+ 할당될 크기 + 4바이트만큼 할당하여 여유있게 공간을 할당한다.
	+ void deallocate(T*, size_t);
		+ 인자로 할당한 메모리의 시작 주소를 가리키는 포인터와 T객체의 개수를 받는다.
	+ void construct(T*, const T&);
		+ 포인터가 가리키는 위치(초기화되지 않은 공간)에 객체를 저장하는 함수
	+ void destory(T*);
		+ 객체를 소멸시킨다. (객체의 소멸자를 호출시킨다)
	+	template \<class In, class For\> For uninitialized_copy(In, In, For);
		+ std::copy함수와 비슷하다.
		+ 입력 반복자2개 (first, last)와 순방향 반복자 1개(out)을 인자로 받는다.
		+ first, last 범위의 요소들을 out이 가리키는 위치에 순서대로 복사한다.
		+ 복사가 완료된 위치의 다음요소를 가리키는 포인터를 반환한다.
	+ template \<class For, class T\> void uninitialized_fill(For, For, const T&);
		+ 세번째 인자로 들어온 값으로 주어진 범위의 공간을 채운다.

## Iterator
### Iterator 종류별 사용가능한 기능
+ Input Iterator(입력 반복자): 읽기(rvalue, Write 불가능), 비교 (==, !=), 증감연산은 ++만 가능
+ Output Iterator(출력 반복자): 쓰기(lvalue, Read 불가능), 비교 (==, !=), 증감연산은 ++만 가능
+ Forward Iterator(순방향 반복자): Input / Output Iterator의 모든 기능
+ Bidirectional Iterator(양방향 반복자): 읽기, 쓰기, 산술 연산(++, --), 비교 연산(==, !=)
	+ list, set, map이 이 반복자를 지원한다.
	+ reverse()함수가 이 양방향 반복자를 사용하기 때문에 양방향 반복자를 지원하지 않는 컨테이너는 reverse()함수를 사용할 수 없다.
+ Random Access Iterator(임의 접근 반복자): 읽기, 쓰기, 산술 연산(++, --, +, -, +=, -=), 비교 연산(==, !=, >, <, >=, <=), 첨자 연산([])
	+ vector, deque가 이 반복자를 지원한다.

### iterator_traits
+ traits(특성정보) 클래스는 컴파일 도중에 어떤 주어진 타입의 정보를 얻을 수 있게 하는 객체를 지칭하는 개념이다.
+ C++ 프로그래머들이 관용적으로 사용하는 기법으로 C++에 정의된 문법구조나 키워드는 아니다.
+ 관례적으로 아래와 같은 항목들을 충족해야 한다.
	+ 일반적으로 특성정보는 구조체로 구현하나, 이를 특성정보(traits) 클래스라 부른다.
	+ 특성정보는 기본제공 타입에 대해서 쓸 수 있어야 한다.
+ traits를 활용하여 컴파일 도중에 인자로 넘어온 iterator에 맞는 함수를 실행할 수 있다.
+ iterator_traits\<T*\>:포인터는 산술 연산이 가능하므로 random_access_iterator_tag를 지정해준다.

## 기타

### operator->() 를 오버로딩할 때 일어나는 현상 및 주의점
+ operator->() 를 오버로딩하고 화살표 연산자(arrow operator)에 의해 operator->() 가 호출될 경우 자동적으로 -> 가 한 번 더 적용된다.
	+ 다음과 같은 경우 A->A->A->... 로 무한 재귀에 빠져버린다. 그러므로 operator->()를 오버로딩할 때에는 함수가 호출된 클래스 자신을 반환해서는 안 된다. 
	```cpp
	struct A
	{
		A operator->()
		{
			return *this;
		}
	};
	```

### 연산자 오버로딩 시 교환법칙이 성립하도록 만들기
+ 클래스 내부에서 멤버함수로 연산자를 오버로딩할 경우 Class + int 는 가능하지만 int + Class는 불가능하다.
	```cpp
		template <typename T1, typename T2>
		bool operator==(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
		{
			return lhs._ptr == rhs._ptr;
		}
	```
	+ 위와 같이 비멤버함수로 오버로딩하면 교환법칙이 성립할 수 있다.