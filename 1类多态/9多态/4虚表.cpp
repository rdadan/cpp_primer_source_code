#include "../../head.h"

// 编译器通过虚表来处理虚函数
// 1. 编译器发现虚函数
// 2. 创建一张虚表
// 3. 将虚函数的入口地址放到虚函数表中， 并添加一个虚指针vptr
// 4. 指针指向对象的虚函数表，在多态调用的时候，通过vptr找到虚函数表来实现动态绑定

// 当类中声明虚函数时，编译器会在类中生成一个虚函数表
// 虚函数表是一个存储类成员函数指针的数据结构
// 虚函数表是由编译器自动生成与维护的
// virtual成员函数会被编译器放入虚函数表中
// 存在虚函数时，每个对象中都有一个指向虚函数表的指针(vptr指针)

// 过程分析：
// Animal* animal = new Dog;
// animal->fun1();
// 当程序执行到这里，会去animal指向的空间中寻找vptr指针，
// 通过vptr指针找到func1函数，
// 此时 如果子类并没有重写也就是覆盖基类的func1函数，所以调用func1时，仍然调用的是基类的func1.
// 如果子类重写基类的func1函数，所以调用func1时，调用的是子类的func1.

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal is Speaking..." << endl;
    }

    virtual void eat() {}
};

class Dog : public Animal
{
public:
    virtual void speak()
    {
        cout << "Dog is Speaking..." << endl;
    }
    virtual void eat() {}
};

void test01() // 不加virtual ，调用的都是父类的对象 Animal is Speaking...
{
    cout << "sizeof(Animal): " << sizeof(Animal) << endl; // 8, 不加virtual。空类大小是1
    cout << "sizeof(Dog): " << sizeof(Dog) << endl;       // 8
}

int main()
{
    test01();
    return 0;
}