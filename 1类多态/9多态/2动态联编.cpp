#include "../../head.h"

class Parent
{
public:
    Parent(int a) : mA(a) { cout << "Parent(a) a: " << mA << endl; }
    // 将print动作声明为virtual
    virtual void print() { cout << "Parent:print() a:" << mA << endl; }

private:
    int mA;
};

class Child : public Parent
{
public:
    Child(int a, int b) : Parent(a), mB(b) { cout << "Child(a, b) b: " << mB << endl; }
    // 这里的virtual可以省略 建议写上
    virtual void print() { cout << "Child:print() b:" << mB << endl; }

private:
    int mB;
};

void doPrint1(Parent *pParent) { pParent->print(); }
void doPrint2(Parent &rParent) { rParent.print(); }

// 动态联编 函数调用地址在在程序运行时确定， 比如 switch和if语句
// 这里的例子，virtual void print() 实现多态， 父类型指针指向的是父类的对象还是子类的对象， 在程序运行时确定
void test01()
{
    Parent *pParent = NULL;
    Parent oParent(10);
    Child oChild(20, 30);

    cout << "1------" << endl;
    pParent = &oParent;
    pParent->print(); // 调用父类的 Parent:print() a:10

    pParent = &oChild;
    pParent->print(); // 调用子类的 Child:print() b:30。和预期相符

    cout << "2------" << endl;

    Parent &rParent1 = oParent;
    Parent &rParent2 = oChild;

    rParent1.print(); // 调用父类的 Parent:print() a:10
    rParent2.print(); // 调用的子类的 Child:print() b:30。和预期相符

    cout << "3------" << endl;
    doPrint1(&oParent);        // Parent:print() a:10
    doPrint1(&oChild);         // Child:print() b:30

    doPrint2(oParent); // Parent:print() a:10
    doPrint2(oChild);  // Child:print() b:30
}

void test02()
{
}

int main()
{
    test01();
    return 0;
}