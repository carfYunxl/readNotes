一个类，如果没有声明默认构造函数，合成版本的默认构造函数总是会被合成出来吗？

例如：
class base{
public:
	int i;
		
};

这里先给出结论：并不总是！以上的例子，class base 就不会合成默认构造函数，当你试图调用它时，像这样：

int main()
{
	base b;
	cout << b.i << endl;
}

编译器将会报错，并提示：
*******************************
C6001	使用未初始化的内存“b”。
*******************************
即表示，该对象并没有被构造出来！这似乎与我们的想象有出入，如果你之前没有研究过这个问题，你可能会认为，没有定义默认构造函数的类，都能自动合成出来。

看到这里，你可能会问：什么时候，编译器不会合成出来默认构造函数呢？

我们不妨来看，什么时候编译器能够合成出来默认构造函数，反面则不言自明了！

1.类A含有类成员B，且类B有构造函数，那么类A将需要合成默认构造函数，用来调用B的构造函数，初始化类B。
class B{//类B
public:
	B() = default;
	int i;
};

class A//类A
{
public:
	int j;
	B b;
};
int main()
{
	A a;
	cout << b.i << endl; //没问题
}
**你可能会进一步问这样的问题：如果A有默认构造函数呢？怎么调用B的默认构造函数？
**这一步，本质上编译器将A的默认构造函数进行了扩充，看下面的例子：
class B{//类B
public:
	B() = default;
	int i;
};

class A//类A
{
public:
	A() = default;
	int j;
	B b;
};

**A的构造函数实际上可能是这样：
A::A()
{
	b.B::B();
	...其他
}
**即编译器扩充了A的默认构造函数，并在其中调用了B的默认构造函数。

2.类A派生自类B，且类B含有默认构造函数，那么类A将需要合成默认构造函数，用来调用B的构造函数，初始化类B。
class B{//类B
public:
	B() = default;
	int i;
};

class A : public B//类A
{
public:
	int j;
};
int main()
{
	A a;
	cout << b.i << endl; //没问题
}

3.如果类A含有虚函数，或者A继承了别的类而获得虚函数，那么类A需要合成默认构造函数。
class A//类A{}
{
public:
	virtual void get();
	int i;
}
int main()
{
	A a;
	cout << b.i << endl; //没问题
}

**此处的原因值得一提，含有虚函数的对象，编译器会为其生成一张虚函数表：virtual function table ,表中存放的是该类所有虚函数的地址。同时，为了使类对象能
**追踪到该虚函数表，并合适的调用其虚函数，一个额外的指针成员：vptr指针会被生成出来，并指向该虚函数表。为了让这个机制发挥功效，编译器必须为每一个对象
**的vptr指针初始化，即设定初值，放置virtual function table的地址。为了完成这些操作，编译器必须为该对象合成默认构造函数，并将这些任务交给默认构造函数
**来完成。

4.如果类A虚继承于类B，即类A含有虚基类B，那么类A需要合成默认构造函数。
**通过类的引用和指针来对有类继承进行的操作，会发生运行期的动态绑定，即直到运行时，编译器才能确定下来到底使用的是哪一个对象的操作。看下面的例子：
class Base{
public:
    int i;
};
class A : public virtual Base{public:int j;};
class B : public virtual Base{public:double k;};
class C : public A,public B {public:int k;};
class D : public virtual A{};
void foo(A* pa)
{
	pa->i = 1024;
}

**函数foo()接受A类型的指针，同时类C/类D又继承于类A，根据动态绑定的规则，传入foo()函数的参数，A类型/C类型/D类型的指针都是合法的，像这样：

foo(new A);		//正确
foo(new C);		//正确
foo(new D);		//正确

**问题在于，编译器如何能够做到运行期动态绑定操作的呢？
**实际上，编译器为该类生成了一个指针，用来控制运行期调用动态绑定。foo()函数的实际代码可能是这样：

void foo(A* pa)
{
	pa->_vbcX->i = 1024;
}

**_vbcX即是编译器所产生的指针，指向那个 virtual base class Base;
**_vbcX必须在类构造期间被完成，而该构造操作必须交给默认构造函数，因此必须能够合成默认构造函数。

5.除该4中可能之外，编译器将不能为没有默认构造函数的类合成默认构造函数。
**另外需要说明的是，合成的默认构造函数，并不会为类的所有数据成员初始化，只有 static data member 才会被合成的构造函数初始化，像 int / 
int * / int [] 等，都不会被初始化。