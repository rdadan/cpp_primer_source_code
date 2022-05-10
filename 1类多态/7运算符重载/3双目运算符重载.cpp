#include "../../head.h"
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
    void print() { cout << "x:" << mX << " y:" << mY << endl; }
    // 重载+=, 单目重载用成员函数
    Point & operator+=(const Point &p) // 返回引用
    {
        this->mX+=p.mX;
        this->mY+=p.mY;
        return *this;
    }

    
};

void test01()
{
    int a1=1, a2=2, a3=3;
    // a1+=a2;
    // a2+=a3;
    // cout << "a1:" << a1 << " a2:" <<a2 <<endl;
    // a1+=a2+=a3; // ->a2=a2+a3=5, a1=a1+a2=6 // 5,6,3
    (a1 += a2) += a3; // 6,2,3
    cout << "a1:" << a1 << " a2:" << a2 << " a3:" << a3 << endl;
}

void test02()
{
    Point p1(1,1), p2(2,2),p3(3,3);
    // p1+=p2;
    // p2+=p3;
    // p1.print();
    // p2.print();
    // p1 += p2+=p3;
    // p1.print();
    // p2.print();
    // p3.print();

    // 这里重载函数如果返回引用其结果是6，2，3； 返回对象结果是3，2，3；
    (p1 += p2) += p3; 
    p1.print();
    p2.print();
    p3.print();
}
int main()
{
    test02();
    return 0;
}


