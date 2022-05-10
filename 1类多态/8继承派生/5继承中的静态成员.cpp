#include "../../head.h"


// 被所有派生类共享。 类内定义，类外初始化，显示的告诉编译器分配内存
class Base
{
public:
    void add()
    {
        mA++;
        sPrivate++;
        sPublic++;
    }

    void print()
    {
        cout << "mA:" << mA << " sPublic:" << sPublic << " sPrivate:" << sPrivate << endl;
    }

    // static int getPublicStatic()
    // {
    //     return sPublic;
    // }
    static int getPrivateStatic()
    {
        return sPrivate;
    }
static int sPublic;

private:
    int mA;
    static int sPrivate;
};

int Base::sPrivate = 0;
int Base::sPublic = 0;

class Derive: public Base
{
public:
    void func()
    {
        print();
        add();
        // cout << "Base::sPrivate:" << Base::sPrivate << endl; // 私有的静态不能类外直接访问
        cout << "Base::sPrivate:" << getPrivateStatic() << endl; 
        cout << "Base::sPublic:" << sPublic << endl;          
    }
};


int main()
{
    Base base;
    Derive derive;

    cout << "sizeof(Base): " << sizeof(Base) << endl;//4
    cout << "sizeof(base): " << sizeof(base) << endl; //4
    cout << "sizeof(Derive): " << sizeof(Derive) << endl;//4
    cout << "sizeof(derive): " << sizeof(derive) << endl;//4

    cout << "----" << endl;

    base.print();
    cout << "Base::sPublic: " << Base::sPublic << endl;
    cout << "base.sPublic: " << base.sPublic << endl;
    
    cout << "----" << endl;
    
   
    cout << "Derive::sPublic: " << Derive::sPublic << endl;
    cout << "derive.sPublic: " << derive.sPublic << endl;
    

    cout << "----" << endl;
    base.add();
    cout << "Base::sPublic: " << Base::sPublic << endl;
    cout << "base.sPublic: " << base.sPublic << endl;
    cout << "Derive::sPublic: " << Derive::sPublic << endl;
    cout << "derive.sPublic: " << derive.sPublic << endl;

    cout << "----" << endl;
    derive.func();

    cout << "----" << endl;
    cout << "Base::sPublic: " << Base::sPublic << endl;
    cout << "base.sPublic: " << base.sPublic << endl;
    cout << "Derive::sPublic: " << Derive::sPublic << endl;
    cout << "derive.sPublic: " << derive.sPublic << endl;
    return 0;
}