#include "../../head.h"

// 运算符重载的本质是函数重载
// 函数类型 operator运算符名称 (参数) {}
// operator运算符名称 就是新的函数名称
// 运算符重载函数可以是友元函数，类成员函数，也可以是普通函数
// 除了赋值号（=）外， 基类中其余被重载的操作符都会被派生类继承

// >>, << 只能是全局加友元来重载
// 一元都建议用成员
// =, (), [],-> *必须是成员
// +=， -=， /=， *=， !=, >=, <= 建议用成员
// 不建议重载 &&， ||, 因为C++的函数参数都会被求值，无法实现短路规则

// 友元重载函数
class Point
{
private:
    int mX;
    int mY;
    
public:
    Point(int x, int y)
    {
        mX = x;
        mY = y;
    }
    ~Point() {}
    void print() {cout <<"x:" << mX << " y:" << mY << endl;}

    friend const Point operator+(const Point &p1, const Point &p2);
    const Point operator+(const Point &p);

};

// 重载函数是友元函数
const Point operator+(const Point &p1, const Point &p2)
{
    cout << "重载函数是友元函数" << endl;

    return Point(p1.mX + p2.mX, p1.mY + p2.mY);
}

// 重载函数是成员函数
const Point Point::operator+(const Point &p)
{
    cout << "重载函数是成元函数" << endl;
    return Point(this->mX + p.mX, mY + p.mY);
}

void test01()
{
    Point p1(1,1), p2(2,2);
    Point p3 = p1+p2; //默认使用成员函数形式的重载
    p3.print();

    Point p4 = operator+(p1, p2); //调用友元函数
    p4.print();

    Point p5 = p1.operator+(p2); //调用成员函数
    p5.print();
}

int main()
{
    test01();
    return 0;
}