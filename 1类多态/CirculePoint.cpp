#include "../head.h"

class Point
{
public:
    void setX1(int x1) { _mX1 = x1; }
    void setY1(int y1) { _mY1 = y1; }
    int getX1() { return _mX1; }
    int getY1() { return _mY1; }

private:
    int _mX1;
    int _mY1;
};

class Circule
{
public:
    void setCirculeR(int r) { _mR = r; }
    void setCirculePoint(int x, int y)
    {
        _mPoint.setX1(x);
        _mPoint.setY1(y);
    }
    Point getCirculePoint() { return _mPoint; }

    double getDistance(Point point)
    {
        return pow((_mPoint.getX1() - point.getX1()), 2) + pow((_mPoint.getY1() - point.getY1()), 2);
    }
    void relationPointAndCircule(Point point)
    {
        double d = getDistance(point);
        cout << "distance:" << d << endl;
        if (d == pow(_mR, 2))
            cout << "point on circule" << endl;
        else if (d > pow(_mR, 2))
            cout << "point out circule" << endl;
        else if (d < pow(_mR, 2))
            cout << "point in circule" << endl;
    }

private:
    int _mR;       //半径
    Point _mPoint; //圆心
};

int main()
{
    Point p;
    p.setX1(1);
    p.setY1(0);

    Circule cir;
    cir.setCirculePoint(1, 1);
    cir.setCirculeR(1);

    cir.relationPointAndCircule(p);
    return 0;
}