#include "../../head.h"

// 希望基类仅仅作为其派生类的一个接口, 禁止创建一个实际的基类对象
// 建立公共接口目的是为了将子类公共的操作抽象出来，
// 可以通过一个公共接口来操纵一组类，且这个公共接口不需要事先(或者不需要完全实现)。可以创建一个公共类.
// 基类中加入至少一个纯虚函数(pure virtual function),使得基类称为抽象类(abstract class).
// 纯虚函数使用关键字virtual，并在其后面加上=0。如果试图去实例化一个抽象类，编译器则会阻止这种操作（纯虚类不能实例化对象）。
// 当继承一个抽象类的时候，必须实现所有的纯虚函数，否则由抽象类派生的类也是一个抽象类。（B继承抽象类A,B要实现所有的纯虚函数，不然B也变成抽象类）

// 怎么做到让纯虚类不能实例化对象？
// Virtual void fun() = 0; 告诉编译器在vtable中为函数保留一个位置，但在这个特定位置不放地址。
// 当试图创建这个类时，编译器会由于不能安全的创建一个纯抽象类的对象， 而发出一个出错信息，这样编译器就可以保证抽象类的纯洁性
// 含有纯虚函数的类，定义了成员函数的地址是空，无法分配内存，该成员函数对类是没有意义的，失去了普通类的数据和方法绑定于同一对象中的意义
// 因此无法构造对象，只能通过派生类继承这些成员函数并实现，才能构造派生类对象。此时抽象类就起到了定义接口的作用。

// 含有虚函数的类，实例化的时候会插入一个指向虚函数表的指针，虚函数表里放的是函数的地址。
// 因为纯虚函数没有定义，也就没有地址，所以就不能实例化。

// 虚函数的原理采用 vtable。
// 类中含有纯虚函数时，其vtable 不完全，有个空位。
// 即“纯虚函数在类的vftable表中对应的表项被赋值为0。也就是指向一个不存在的函数。
// 由于编译器绝对不允许有调用一个不存在的函数的可能，所以该类不能生成对象。
// 在它的派生类中，除非重写此函数，否则也不能生成对象。”
// 所以纯虚函数不能实例化。

class Animal
{
public:
    // 提取动物类的三个共同特征作为接口, 通过一个公共接口来操纵一组类
    virtual void eat() = 0; //只有声明没有，没有实现，初始化为0。 由派生类重写
    virtual void play() = 0;
    virtual void sleep() = 0;
    Animal(void) { cout << "Animal()" << endl; }
    Animal(int a) : mA(a) { cout << "Animal(int a) a:" << mA << endl; }
    void MyAnimal() //该成员函数对Animal类是没有意义的
    {
        eat();
        play();
        sleep();
    }
    void print() { cout << "Animal" << endl; }
    int mA;
};

void DoAnimal(Animal *pAnimal)
{
    pAnimal->MyAnimal(); //子类继承 DoAnimal成员函数，
    pAnimal->print();    // 能调用到父类的成员函数 打印Animal
}

class Cat : public Animal
{
public:
    // 任何一个父类的纯虚函数没有被重写， Cat都会变成抽象类， 而变得也不能实例化对象
    virtual void eat() { cout << " cat eat..." << endl; }
    virtual void play() { cout << " cat play..." << endl; }
    virtual void sleep() { cout << " cat sleep..." << endl; }
};

class Dog : public Animal
{
public:
    virtual void eat() { cout << " dog eat..." << endl; }
    virtual void play() { cout << " dog play..." << endl; }
    virtual void sleep() { cout << " dog sleep..." << endl; }
};

int main()
{
    // Animal animal; //纯序类不能实例化对象
    Cat cat;
    Dog dog;
    DoAnimal(&cat);
    cout << "------" << endl;
    DoAnimal(&dog);
    return 0;
}