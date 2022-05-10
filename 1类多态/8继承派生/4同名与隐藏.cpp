#include "../../head.h"

class A
{
public:

    A():val(1) {}
    void print() { cout << "void A::print(), val :" << val << endl; }
    // ----------
    void func1(void) { cout << "vodi A::func1(void)" << endl; }
    void func1(int a) { cout << "void A::func1(int a)" << endl; }
    void my_func() { cout << "void A::my_func()" << endl; }

    int val;
};

class B : public A
{
public:
    B() : val(2) {}
    void print() { cout << "void B::print(), val :" << val << " " << A::val << endl; }
    void my_func() { cout << "void B::my_func()" << endl; }
    int val;
};

class C: public A
{
public:
    //重载了父类的重载函数
    void func1(int a, int b) { cout << "void C::func1(int a, int b)" << endl; }
};

class D : public A
{
public:
    //重定义了和父类的重载函数同名的函数func1(int a)，仅仅是返回值不同， 所以没有重载
    int func1(int a) { cout << "int D::func1(int a)" << endl;  return 0;}
};
//---------------------
void test01()
{
    B b;
    b.print();    // 子类优先调用自己的 成员变量和函数
    b.A::print(); // 指定调用父类的
}

//-------------------
void test02()
{
    B b;
    b.func1(); // A func1
    b.func1(1); // A func1(int a)
    b.my_func(); // B my_func()
    cout << "------" << endl;
    C c;
    // c.func1(); // 子类C重载了父类的重载函数func1，父类的重载函数全部被隐藏, 子类只能访问自己定义的函数
    // c.func1(1); 
    c.func1(1, 1); // C func1(int a, int b)
    c.my_func();   //  A my_func()
    cout << "------" << endl;

    D d;
    //d.A::func1(void); // 父类的 func1(void)在子类中没有被重新定义， 被隐藏，指定也访问不到
    d.A::func1(1); // void A::func1(int a)  父类的func1(int a)在子类中 被重新定义， 没被隐藏， 可以指定访问
    d.func1(1);    // int D::func1(int a)
    d.my_func();   // void A::my_func()
}

int main()
{
    test02();
    return 0;
}