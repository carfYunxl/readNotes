No.3 尽可能使用const

const 可以作用与常量，变量，指针，函数，类对象等等。
1 const与变量：
int a = 10;
int *p = &a;//普通指针
const int* p = &a;//非常量指针，常量数据
int* const p = &a;//常量指针，非常量数据
const int* const p = &a;//常量指针，常量数据

可以这样简记：
const 出现在*号左边，表示常量数据；const出现在*号右边，表示常量指针；

再以STL 迭代器为例：
vector<int> vec;

const vector<int>::iterator it;//常量指针
vector<int>::const_iterator it;//常量数据

2 const 可以与函数返回值，函数参数，函数自身(如果是成员函数)产生内联；

	2.1 const 作为返回值可以防止意外错误的发生，考虑乘法操作符
	const A operator*(const A& lhs,const A& rhs);
	如果不是返回const对象，那么有可能发生以下行为：
	( a * b ) = c;
	或者：
	if( a * b = c )...
	这样显然不是我们想要的行为，声明const可以预防这些不经意的错误代码！
	
	2.2 const 成员函数
	例如类成员函数：
	class A{
		public:
		...
		void get() const ;
	};
	标记了 const 的成员函数可以作用于 const 对象，由此可以区分类中哪些函数可以修改类对象，而哪些不可以；
	同时，接口更易于理解。
	
	成员函数因 const 的区分，是可以被重载的,如：
	const int operator[]()const{}
	int operator[]{}
	
	
