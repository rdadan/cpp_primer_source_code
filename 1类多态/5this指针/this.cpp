#include "../../head.h"

// 同一个类的对象，每个对象都有自己的存储空间，但是共享成员函数（即共享同一份代码段）
// this指针隐藏在成员函数中，指向被调用的成员函数的所属对象
// 当一个对象被创建后，它的每一个成员函数都自动生成一个隐含的this指针，用于保存这个对象的地址
// 静态成员函数没有this指针，不能操作非静态成员变量

class TestA
{
public:
    TestA() {}
    TestA(int a, int b) // -> TestA(TestA *this, int a, int b)
    {
        this->m_a = a;
        m_b = b;
    }

    int getA() const// // -> TestA(TestA *this)
    {
        return this->m_a;
    }

    int getB() const
    {
        // m_b = m_b+1;
        return m_b;
    }
    void printA()
    {
        cout << this->m_a << " " << this->m_b << " " << this->m_c << " " << m_d << endl;
    }

    // 成员函数加上const
    // const 修饰this指针指向的区域，不可再修改类中的任何普通成员变量
    void setVal(int a, int b, int c, int d) const 
    {
        // this->m_a = a;
        // this->m_b = b;
        this->m_c = c; // 静态成员变量可以修改
        this->m_d = d; // mutable 修饰的变量可以修改
    }

    // static成员函数没有this
    // static void sPrintA()
    // {
    //     cout << this->m_a << endl; // err
    // }

    // 这里不能返回引用，如果返回引用就是一个局部变量的引用，就是非法的栈空间引用
    TestA add1(const TestA &A)
    {
        int a = this->m_a + A.m_a;
        int b = this->m_b + A.m_b;
        TestA newA(a, b);
        return newA; 
    }

    TestA & add2(const TestA &A)
    {
        this->m_a = this->m_a + A.m_a;
        this->m_b = this->m_b + A.m_b;
        return *this;
    }


private:
    int m_a;
    int m_b;
    static int m_c;
    mutable int m_d;
};
int TestA::m_c = 0;

// 全局函数
TestA add3_g(const TestA &A1, const TestA &A2)
{
    int a = A1.getA() + A2.getA();
    int b = A1.getB() + A2.getB();
    TestA newA(a, b);
    return newA;
} 
void testA_01()
{
    TestA A1(2, 4);
    cout << A1.getA() << endl;
    A1.printA();

    cout << A1.getB() << endl;
}

void testA_02()
{
    TestA a1(1,2), a2(2,3);
    TestA a3 = a1.add1(a2);
    a3.printA();

    a1.add2(a2);
    a3.printA();
}

void testA_03()
{
    TestA a1(1, 2), a2(2, 3);
    TestA a3 = add3_g(a1, a2);
    a3.printA();
}

void testA_04()
{
    TestA a1(1, 2);
    a1.setVal(11,12,100, 200);
    a1.printA();

    TestA a2(5, 6);
    a2.setVal(21, 22, 300, 400);
    a2.printA();

    TestA a3(8, 9);
    a3.setVal(31, 32, 500, 600);
    a3.printA();
    /* --- */
    a1.printA();
    a2.printA();
}

int main()
{
    testA_04();
    return 0;
}