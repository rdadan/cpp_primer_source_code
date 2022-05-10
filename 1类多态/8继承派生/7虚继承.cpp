#include "../../head.h"

// 一个类继承了多个父类
// 多继承中有二义性问题， 比如 A是基类， B1， B2都继承了A， C又继承B1， B2
//
// 解决多继承的二义性问题，
class A
{
public:
    int mA;
    // A() : mA(0) {}

    A() { mA= 0;}
    A(int x) : mA(x) {}

    void print() { cout << "A::mA: " << mA << endl; }
};

class B1 : virtual public A
{
public:
    // B1() { mA = 1;}

    B1() : A(11) {}
    
    // int mB1;
};

class B2 : virtual public A //virtual base pointer
{
public:
    // B2() { mA = 2; }
    B2():A(22) {}
    // int mB2;
};

class C : public B2, public B1 
{
public:
    // 虚基类的初始话是由最后的子类完成的， 其他的初始化语句不会在调用
    // 所以每一次继承子类中 都要写 初始化列表
    C():A(100) {}
    // C()  {mA=1000;}
    void funcC()
    {
        cout << "C::mA: " << mA << endl;      // 值是最后一个继承的  C():A(100) 100
        cout << "B1::mA: " << B1::mA << endl; // 指定使用B1的 100
        cout << "B2::mA: " << B2::mA << endl; // 100
    }
    // int mD;
};

void test()
{
    int *p=NULL;
    char *p1=NULL;
    char p2[64];
    cout << sizeof(p) << " " << sizeof(p1) << " " << sizeof(p2) << endl; //8,8,64

    cout << "sizeof(A)" << sizeof(A) << endl; // 4

    cout << "sizeof(B1)" << sizeof(B1) << endl; // 4_4 + vbptr_8 = 16

    cout << "sizeof(B2)" << sizeof(B2) << endl; // 4_4 + vbptr_8 = 16

    cout << "sizeof(C)" << sizeof(C) << endl; //  4_4 + vbptr_8 + vbptr_8 = 24

    C objC;

    objC.funcC();
    cout << objC.mA << endl; // 100 ,100, 100

    cout << "----" << endl;
    A objA;
    cout << "A::mA: " << objA.mA << endl; // 0
}

int main()
{
    test();
    return 0;
}