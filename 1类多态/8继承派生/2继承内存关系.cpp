#include "../../head.h"

class A
{
    int a1; // 4
    double a2; // 8
    static int s_a; // 4 但是放在静态区
};
int A::s_a = 1;
class B: public A
{
    int b1; // 4 
};

class C : public B
{
    int c1; // 4
};

void test()
{
    cout << "sizeof A: " << sizeof(A) << endl; // (4+4)+8=16(对齐到最大字节的倍数)
    cout << "sizeof B: " << sizeof(B) << endl; // (4+4)+8+(4+4) = 24
    cout << "sizeof C: " << sizeof(C) << endl; // (4+4)+8+(4+4) + 4 =24 //最后一个4字节，刚好把前面那个对齐的四字节补上
    cout << "-------------" << endl;

    A objA;
    B objB;
    C objC;

    cout << "sizeof objA: " << sizeof(objA) << endl;
    cout << "sizeof objB: " << sizeof(objB) << endl;
    cout << "sizeof objC: " << sizeof(objC) << endl;
}

int main()
{
    test();
    return 0;
}