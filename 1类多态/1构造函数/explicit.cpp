#include "../../head.h"

class Point
{
public:
    // Effective C++： 被声明为explicit的构造函数通常比其 non-explicit 兄弟更受欢迎, 因为它们禁止编译器执行非预期 (往往也不被期望) 的类型转换.
    // 除非有一个好理由允许构造函数被用于隐式类型转换, 否则我会把它声明为explicit. 我鼓励你遵循相同的政策.
    explicit Point(int x = 0, int y = 0)
    :m_x(x), m_y(y)
    {
        // cout << "Point(int x, int y)" <<endl;
    }
    int getX() const { return m_x; }
    int getY() const { return m_y; }

private:
    int m_x;
    int m_y;
};

void printPoint(const Point &p)
{
    cout << "x: " << p.getX() << " y: " << p.getY() << endl;
}
void test()
{
    //传的是整形， 但是执行成功，构造函数发生隐式转换
    // 加入 explicit 无法编译
    printPoint(2); // x: 2 y: 0

    //传的是整形， 但是执行成功，构造函数发生隐式转换
    // 加入 explicit 无法编译
    Point p = 100;
    cout << "x: " << p.getX() << " y: " << p.getY() << endl; // x: 100 y: 0
}

int main()
{
    test();
    return 0;
}