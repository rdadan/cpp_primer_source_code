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
    // 重载前++
    friend Point & operator++(Point &p); // 返回引用

    // 重载后++
    friend Point operator++(Point &p, int); // 返回临时对象
};

// 前++, 返回引用
Point &operator++(Point &p)
{
    p.mX++;
    p.mY++;
    return p;
}

// 后++, // 返回临时对象
Point operator++(Point &p, int)
{
    Point temp(p.mX, p.mY);
    p.mX++;
    p.mY++;
    return temp;
}

void test01()
{
    int a=1;
    // 前++
    cout << "++a: " << ++++a << endl;
    cout << "a: " << a << endl;

    int b = ++a;
    cout << "b: " << b << endl;

    Point p(1, 1);
    cout << "++++p: " << endl;
    (++++p).print();
    cout << "p: " << endl;
    p.print();

    Point p2 = ++p;
    cout << "p2: " << endl;
    p2.print();
}

void test02()
{
    int a = 1;
    // 后++
    cout << "a: " << a << endl;
    cout << "a++: " << a++ << endl; // a++++ error
    cout << "a: " << a << endl;

    Point p(1, 1);
    cout << "p: " << endl;
    p.print();
    Point p2 = p++;
    cout << "p++: " << endl;
    p2.print();

    cout << "p: " << endl;
    p.print();
}

int main()
{
    test02();
    return 0;
}
