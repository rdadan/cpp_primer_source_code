#include "../../head.h"

//  C++ 多态性由虚函数实现，虚函数允许子类重新定义父类成员函数
//  子类重新定义父类的虚函数就叫覆盖(重写)
//  virtual虚函数只能是成员函数
//  构造函数不能是虚函数
//  加virtual， 只有传子类对象的引用或者指针才能表现出多态
//  父类引用或指针可以指向子类对象，通过父类指针或引用来操作子类对象。

class Animal
{
private:
    /* data */
public:
    virtual void speak()
    {
        cout << "Animal is Speaking..." << endl;
    }
};

class Dog : public Animal
{
public:
    virtual void speak()
    {
        cout << "Dog is Speaking..." << endl;
    }
};
void doSpeak(Animal &animal)
{
    animal.speak();
}
void doSpeak1(Animal *animal)
{
    animal->speak();
}
void test01() // 不加virtual ，调用的都是父类的对象 Animal is Speaking...
{
    Dog dog;
    Animal objAnimal = dog;
    doSpeak(objAnimal);
    Animal &rAnimal1 = dog;
    doSpeak(rAnimal1);

    doSpeak1(&objAnimal);
    doSpeak1(&rAnimal1);
}

void test02() // 加virtual， 只有传子类对象的引用或者指针才能表现出多态
{
    Dog dog;
    Animal objAnimal = dog;
    doSpeak(objAnimal); // Animal is Speaking...

    Animal &rAnimal1 = dog;
    doSpeak(rAnimal1); // Dog is Speaking...

    doSpeak1(&objAnimal); // Animal is Speaking...
    doSpeak1(&rAnimal1);  // Dog is Speaking...
}

int main()
{
    test02();
    return 0;
}