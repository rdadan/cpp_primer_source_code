#include "../../head.h"

// 1.非静态成员的存储
//   非静态成员变量
//   非静态成员函数

// 2.静态成员的存储
//   静态成员变量
//   静态成员函数

class testA
{
public:
private:
};

void tEmptyA()
{
    cout << sizeof(testA) << endl; // 1
    testA a;
    cout << sizeof(a) << endl; // 1
}

class testB
{
public:
    void print() {}

private:
    char m_a;   // 1
    short m_b;  // 2
    int m_c;    // 4
    double m_d; // 8
};

void tNonStaticB()
{
    cout << sizeof(testB) << endl; // 1+2+4+8=15->16
    testB B;
    cout << sizeof(B) << endl; // 16
}

class testC
{
public:
    static void print() {}

private:
    int m_a;        // 4
    static int m_c; // 4
};
int testC::m_c = 100.00;

// 静态成员变量和函数都不保存在类对象中；
// 普通成员函数也不保存在对象中
// C++中类对象中的函数和变量是分开存储的
// 只有普通成员变量存储与对象中，和struct一样有字节对齐
// 静态成员变量存储与全局数据区中
// 所有的成员函数都存储在代码段

// #pragma pack(n)   // 编译器将按照n个字节对齐；
// #pragma pack()    // 恢复先前的pack设置,取消设置的字节对齐方式
// #pragma pack(pop) // 恢复先前的pack设置,取消设置的字节对齐方式
// #pragma pack(1)   // 按1字节进行对齐 即：不行进行对齐

// · __attribute((aligned(n))) ，让所作用的结构成员对齐在n字节自然边界上。如果结构中有成员的长度大于n，则按照最大成员的长度来对齐。
// · __attribute__((packed)) ，取消结构在编译过程中的优化对齐，按照实际占用字节数进行对齐。

// // 取消在编译过程中的优化对齐，按照实际占用字节数进行对齐
// struct person1
// {
//     char *name;
//     int age;
//     char score;
//     int id;
// } __attribute__((packed));

// // 构体成员对齐在4字节边界上
// struct person2
// {
//     char *name;
//     int age;
//     char score;
//     int id;
// } __attribute__((aligned(4)));

void tStaticC()
{
    cout << sizeof(testC) << endl; // 大小还是4 说明静态成员是放在静态存储区的
    testC C;
    cout << sizeof(C) << endl; // 4 说明静态成员是放在静态存储区的，不保存在对象中
}

int main()
{
    tStaticC();
    return 0;
}