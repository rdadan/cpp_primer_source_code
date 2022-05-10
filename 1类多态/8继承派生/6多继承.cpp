#include "../../head.h"

// 一个类继承了多个父类
// 多继承中有二义性问题， 比如 A是基类， B1， B2都继承了A， C又继承B1， B2
// 

class A
{
public:
    int mA; //4
    A() : mA(0) {}
    A(int x) : mA(x) {}

    void print() { cout << "mA: " << mA << endl; }
    static int staticA2;
};
int A::staticA2 = 20;
class B1 : public A
{
public:
    B1():A(1) {}
    B1(int x) : A(x) {}
    int mB1; 
};

class B2 : public A
{
public:
    B2(): A(2){}
    B2(int x) : A(x) {}

    int mB2; //4
};

class C : public B1,B2
{
public:
    int mD; //4
    C():B1(11), B2(22) {}
    void funcC()
    {
        // cout << mA << endl; // err:mA不明确 reference to 'mA' is ambiguous
        // cout << A::mA << endl; // err: C没有直接继承A， 'A' is an ambiguous base of 'C'
        cout << "B1::mA: " << B1::mA << endl; //指定使用B1的
        cout << "B2::mA: " << B2::mA << endl;
        cout << "static: : " << staticA2 << endl;
    }
};


void test()
{
    cout << "sizeof(A)" << sizeof(A) << endl; // 4

    cout << "sizeof(B1)" << sizeof(B1) << endl; // 8

    cout << "sizeof(B2)" << sizeof(B2) << endl; // 8

    cout << "-----" <<endl;

    
    C objC;
    objC.staticA2 = 20;
    cout << "sizeof(C)" << sizeof(C) << endl; // C:4+ B1:8+ B2:8 = 20
    objC.funcC();

    A objA;
    cout << "A::mA: " << objA.mA << endl; // 0
}

int main()
{
    test();
    return 0;
}