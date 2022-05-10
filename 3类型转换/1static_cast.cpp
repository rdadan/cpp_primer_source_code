#include "../head.h"

//静态类型转换，在编译时完成的类型转换
//不仅可以替代C风格的转换，还可以进行检查

// 1. 用于基本数据类型之间的转换
void test01()
{
    double pi = 3.1415926;
    int num1 = (int)pi;              // C强制转换
    int num2 = pi;                   // C隐式转换
    int num3 = static_cast<int>(pi); // C++静态转换

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "num3: " << num3 << endl;
}

// 2 用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换
//	进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；
//	进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的。
class Animal
{
};
class Dog : public Animal
{
};
class Other
{
};

//继承关系指针互相转换
void test02()
{
    //继承关系指针转换
    Animal *animal01 = NULL;
    Dog *dog01 = NULL;
    //子类指针转成父类指针,安全
    animal01 = static_cast<Animal *>(dog01);
    //父类指针转成子类指针，不安全
    Dog *dog02 = static_cast<Dog *>(animal01);
}

//继承关系引用相互转换
void test03()
{
    Animal ani_ref;
    Dog dog_ref;
    //继承关系指针转换
    Animal &animal01 = ani_ref;
    Dog &dog01 = dog_ref;
    //子类指针转成父类指针,安全
    Animal &animal02 = static_cast<Animal &>(dog01);
    //父类指针转成子类指针，不安全
    Dog &dog02 = static_cast<Dog &>(animal01);
}

//无继承关系指针转换
void test04()
{
    Animal *animal01 = NULL;
    Other *other01 = NULL;

    //转换失败
    // Animal *animal02 = static_cast<Animal *>(other01); // 类型转换无效
}

int main()
{
    test03();
    return 0;
}