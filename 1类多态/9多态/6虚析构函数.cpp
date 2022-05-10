#include "../../head.h"
//虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。

class Animal
{
public:
    Animal(void) { cout << "构造Animal()" << endl; }
    Animal(int a) : mA(a) { cout << "构造Animal(int a) a:" << mA << endl; }
    // virtual ~Animal() { cout << "析构~Animal()" << endl; }
    virtual ~Animal() = 0;

public:
    // 提取动物类的三个共同特征作为接口, 通过一个公共接口来操纵一组类
    virtual void eat() = 0; //只有声明没有，没有实现，初始化为0。 由派生类重写
    virtual void play() = 0;
    virtual void sleep() = 0;
    void print() { cout << "Animal" << endl; }
    void MyAnimal() //该成员函数对Animal类是没有意义的
    {
        eat();
        play();
        sleep();
    }

private:
    int mA;
};

//纯虚析构函数和非纯析构函数之间唯一的不同之处在于纯虚析构函数使得基类是抽象类，不能创建基类的对象。
//如果类的目的不是为了实现多态，作为基类来使用，就不要声明虚析构函数，反之，则应该为类声明虚析构函数。
Animal::~Animal()
{
    cout << "纯析构~Animal()" << endl;
}

class Cat : public Animal
{

public:
    Cat(const char *name)
    {
        mName = new char[strlen(name) + 1];
        strcpy(mName, name);
        cout << "构造Cat()" << endl;
    }

    ~Cat()
    {
        cout << "析构Cat()" << endl;
        if (NULL != mName)
        {
            delete mName;
            mName = NULL;
        }
    }

public:
    // 任何一个父类的纯虚函数没有被重写， Cat都会变成抽象类， 而变得也不能实例化对象
    virtual void eat() { cout << mName << " cat eat..." << endl; }
    virtual void play() { cout << mName << " cat play..." << endl; }
    virtual void sleep() { cout << mName << " cat sleep..." << endl; }

private:
    char *mName;
};

void DoAnimal(Animal *pAnimal)
{
    pAnimal->MyAnimal(); //子类继承 DoAnimal成员函数，
}

void test01()
{
    Animal *p = new Cat("Tom");
    DoAnimal(p);
    delete p;
    p = NULL;

    // 基类析构函数如果不是虚析构，就没法释放子类的内存
    /*构造Animal()
    构造Cat()
    Tom cat eat...
    Tom cat play...
    Tom cat sleep...
    析构Cat() // 基类是虚析构才释放子类内存
    析构~Animal() */
}

int main()
{
    test01();
    return 0;
}