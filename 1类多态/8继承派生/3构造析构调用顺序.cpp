#include "../../head.h"
// 构造和析构不被继承， 也就是说每个派生类都有自己的构造和析构
// operator= 不能被继承，它类似完成构造的功能
class Z
{
public:
    Z() { cout << "Z()" << endl; }
    ~Z() { cout << "~Z()" << endl; }
};
class A
{
public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }
};
class B : public A
{
public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }
    Z z;
};

class C : public B
{
public:
    C() { cout << "C()" << endl; }
    ~C() { cout << "~C()" << endl; }
    A a;
};

int main()
{
    // 顺序：先构造父类的， 再构造对象成员的， 最后构造自己； 析构反过来
    C c; // 构造A Z B A C， 析构 C A B Z A
    return 0;
}