#include "../head.h"

class Cube
{

public:
    Cube(/* args */);
    ~Cube();
    void setL(int val);

    void setW(int val);
    void setH(int val);
    int getL();
    int getW();
    int getH();
    static bool s_CompareCube(Cube cube1, Cube cube2);
    bool compareCube(Cube cub);
    int calS();
    int calV();

private:
    int _ml; //长
    int _mw; //宽
    int _mh; // 高
};

Cube::Cube(/* args */)
{
}

Cube::~Cube()
{
}
void Cube::setL(int val) { _ml = val; }
void Cube::setW(int val) { _mw = val; }
void Cube::setH(int val) { _mh = val; }
int Cube::getL() { return _ml; }
int Cube::getW() { return _mw; }
int Cube::getH() { return _mh; }
int Cube::calS() { return 2 * (_ml * _mw + _ml * _mh + _mw * _mh); }
int Cube::calV() { return _ml * _mw * _mh; }

bool Cube::s_CompareCube(Cube cube1, Cube cube2)
{
    return cube1._ml == cube2._ml && cube1._mw == cube2._mw && cube1._mh == cube2._mh;
}
bool Cube::compareCube(Cube cub)
{
    return _ml == cub._ml && _mw == cub._mw && _mh == cub._mh;
}

int main()
{
    Cube cub1, cub2;
    cub1.setL(2);
    cub1.setW(3);
    cub1.setH(4);

    cout << cub1.getW() << endl;

    cub2.setL(2);
    cub2.setW(3);
    cub2.setH(4);
    cout << cub2.getH() << endl;

    cout << Cube::s_CompareCube(cub1, cub2) << endl;
    cout << cub1.compareCube(cub2) << endl;

    return 0;
}