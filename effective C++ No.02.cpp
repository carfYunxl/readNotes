/*effective C++	No.02	尽量以const,enum,inline 替换 #define
1.#define的不足之处
当我们写出这样一个宏定义:*/
#define ASPECT-RATIO 1.653

/*名称 ASPECT-RATIO 编译器根本看不见，编译器只是负责将所有该名称替换为 1.653.
然而如果因为该常量而出现编译错误时，可能会带来困惑。编译器会提示1.653出错，而没有提到该名称，于是你将因为追踪该错误而浪费大量时间*/

/*我们希望的是，所有错误尽量能在编译时发现，而不要等到运行时期，因为那意味着，大量的修改，于是我们可以这样修改该代码：*/
const double Aspect_Ratio = 1.653;

//再例如常量的定义:
const char * const authorName = "Scott Meyers";//此处我们需要两个const，当然，用string会更好，仅以此为例

//类内常量的定义
class A{
private:
	static const int NumTurns = 5;//该静态常量意味着，其作用域限制于类内，且由于是static,最多只能出现一份该常量
	int scores[NumTurns];
}

//有一点要说明的是，如果是类的专属常量，又是静态类型static，且是整数类型（int char,bool），则只需声明就可以使用，因此上述NumTurns是声明，而不是定义；
//以上的例子意于说明：
//#define并不重视作用域，我们无法用#define创建一个类的专属常量；而且#define不提供任何封装性，没有private,public的区别

//对于数组的声明，编译器必须在声明数组时，知道数组的大小，假如上述类内数组的定义，编译器不支持，那么还可以这么写：
class A{
private:
	enum { NumTurns = 5 };
	int scores[NumTurns];
}
//其理论基础是：一个属于枚举类型的数值，可当作int被使用。即NumTurns是5的一个记号名称。
//enum同时禁止指针或引用指向枚举量，同时enum不会导致非必要的内存空间，其与#define相同。
//事实上，enum是template metaprogramming中的基础技术

//观察以下宏定义
#define CALL_WITH_MAX(a,b)  f((a) > (b) ? (a):(b))
//该宏有三个问题：
//1.看着吓人
//2.不能丢掉括号，所有的实参都要带上括号
//3.即使如此，可能仍然会发生不可思议的事情：
//看以下调用：
int a = 5,b = 0;
CALL_WITH_MAX(++a,b);//a被累加2次
CALL_WITH_MAX(++a,b+10);//a被累加1次

//当（b）的大小不同时，a的累加次数是不同的；显然这不是我们预想的结果；
//但是如果我们写成这样：
template<typename T>
inline void callWithMax(const T& a,const T& b)
{
	f(a > b ? a : b);
}
//该函数不需要在参数上加括号，也不会出现累加次数不同的问题，同时可以遵守作用域和访问规则，还能提高封装性

基于以上说明，充分使用const enum 和 inline 是有利的，在不是必须使用#define的地方，应尽量以这些技术来代替#define