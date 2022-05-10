#include "../../head.h"

class A
{
public:
    // 传统的初始化列表
    // A(int a1, int a2, int a3)
    // {
    //     m_a1 = a1;
    //     m_a2 = a2;
    //     m_a3 = a3;
    //     cout << "传统的初始化列表A" << endl;;
    //     cout << m_a1 ;
    //     cout << m_a2 ;
    //     cout << m_a3 ;
    // }

    // 初始化列表 和上面的只能有其中一个
    A(int a1, int a2, int a3) 
    : m_a1(a1), m_a2(a2), m_a3(a3)
    {
        cout << "A的初始化列表";
        cout << m_a1;
        cout << m_a2;
        cout << m_a3 << endl;
    }
    ~A() { cout << "A的析构" << endl; }

private:
    int m_a1;
    int m_a2;
    int m_a3;
};

class B
{
public:
    // 初始化列表 和上面的只能有其中一个
    B(int b)
        : m_b(b) // 成员对象objA不完成初始化，就没法进行B对象的初始化
    {
        cout << "B的初始化列表" << m_b << endl;
    }
    ~B()
    {
        cout << "B的析构" << endl;
    }

private:
    int m_b;
};

class C
{
public:

    // 初始化列表 和上面的只能有其中一个
    C(int a1, int a2, int a3, int b, int c)
        : m_c(c),
          m_objA(a1, a2, a3), // 成员对象objA不完成初始化，就没法进行C的初始化
          m_objB(b)

    {
        cout << "C的初始化列表" << m_c << endl;
    }
    ~C()
    {
        cout << "C的析构" << endl;
    }

private:
    int m_c;
    B m_objB;
    A m_objA;
   
};


void tInitList()
{
    A objA(1,2,3);
}

// 先完成对象成员的初始化，再初始化自己的
void tInitListWithObj()
{
    B objB(100);
}

void tInitListWithObj2()
{
    C objC(1, 2,3, 11, 100); // 构造顺序 BAC
}

int main()
{
    tInitListWithObj2();
    return 0;
}