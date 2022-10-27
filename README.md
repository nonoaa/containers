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

## 