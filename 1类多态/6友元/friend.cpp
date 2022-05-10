#include "../../head.h"

// 允许友元访问自己的私有成员
// 类，成员函数，全局函数都可以声明为自己的友元
// 友元可以访问自己的任何属性的成员，包括私有属性

// 友元关系不能被继承
// 友元关系是单项的，B是A的友元， A不一定是B的友元；
// 友元关系不能传递， B是A的友元， A是C的友元， 但B不一定是C的友元
// 友元的声明位置不受 public， private， protected位置影响
// 友元不是类成员， 但是可以访问类的私有成员，破坏了类的封装性和隐藏性

class TestA
{
public:
    TestA() {}
    TestA(int a, int b)
    {
        this->m_a = a;
        m_b = b;
    }

    int getA() const { return this->m_a; }
    int getB() const { return m_b; }
    void printA() { cout << this->m_a << " " << this->m_b << endl; }
    void setVal(int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }

    // 将类成员函数Add声明为TestA的友元函数
    friend TestA Add(const TestA A1, const TestA A2);
    // 全局函数Distance为TestA的友元函数
    friend double Distance(const TestA A1, const TestA A2);

private : int m_a;
    int m_b;
    friend class TestB; //将TestB类声明为TestA的友元
};

// 友元类, TestB是TestA的友元， 可以访问他的所有成员
class TestB
{
public:
    void setAbyB(TestA &A, int a, int b)
    {
        A.m_a = a;
        A.m_b = b;
    }
};

// 类成员函数Add为TestA的友元函数， 可以访问类的私有成员变量
TestA Add(const TestA A1, const TestA A2)
{
    int a = A1.m_a + A2.m_a;
    int b = A1.m_b + A2.m_b;
    TestA A(a,b);
    return A;
}

// 全局函数Distance为TestA的友元函数， 可以访问类的私有成员变量
double Distance(const TestA A1, const TestA A2)
{
    double a = A1.m_a + A2.m_a;
    double b = A1.m_b + A2.m_b;
    return sqrt(a*a + b*b);
}

void test01()
{
    TestA A1(1, 2);
    TestA A2(3, 4);
    TestA A3 = Add(A1, A2);
    A3.printA();

    double d = Distance(A1, A2);
    cout << "d: " << d << endl;

    TestB B;
    B.setAbyB(A1, 10, 20);
    A1.printA();
}



int main()
{
    test01();
    return 0;
}

