#include "../../head.h"

class Parent
{
public:
    Parent(int a) : mA(a) { cout << "Parent(a) a: " << mA << endl; }
    void print(){cout << "Parent:print() a:" << mA << endl;}
private:
    int mA;
};

class Child :public Parent
{
public:
    Child(int a, int b) : Parent(a), mB(b) { cout << "Child(a, b) b: " << mB << endl; }
    void print() { cout << "Child:print() b:" << mB << endl; }

private:
    int mB;
};

void doPrint1(Parent *pParent) { pParent->print(); }
void doPrint2(Parent &rParent) { rParent.print(); }

//静态联编 比如函数重载。 函数的调用，在编译阶段就确定了函数的调用地址
// 这里的例子，编译器不知道父类型指针到底指向的是父类对象还是子类对象
// 为了安全只能假设执行的是父类的对象， 因此调用的都是父类的成员函数

void test01()
{
    Parent *pParent = NULL;
    Parent oParent(10);
    Child oChild(20,30);

    cout << "1------" << endl;
    pParent = &oParent;
    pParent->print(); // 调用父类的 Parent:print() a:10

    pParent = &oChild;
    pParent->print(); // 调用的还是父类的 Parent:print() a:20。但是想让他执行child的

    cout << "2------" << endl;

    Parent &rParent1 = oParent;
    Parent &rParent2 = oChild;

    rParent1.print(); // 调用父类的 Parent:print() a:10
    rParent2.print(); // 调用的还是父类的 Parent:print() a:20。但是想让他执行child的

    cout << "3------" << endl; // 调用的都是Parent:print()
    doPrint1(&oParent); // 10
    doPrint1(&oChild);  // 20

    doPrint2(oParent);  // 10
    doPrint2(oChild);  //20
}

void test02()
{

}

int main()
{
    test01();
    return 0;
}