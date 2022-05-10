#include "../head.h"

class Circle
{
public:
    void setRadius(double r)
    {
        _radius = r;
    }

    double getRadius()
    {
        return _radius;
    }

    double getCircleArea()
    {
        return 3.14 * _radius * _radius;
    }
private: 
    double _radius;
    // const short pi = 3.14;
};

void tCircle()
{
    Circle circle;
    cout << circle.getRadius() << endl;
    circle.setRadius(4);
    cout << circle.getRadius() << endl;
    cout << circle.getCircleArea() << endl;
}
int main()
{
    tCircle();

    return 0;
}