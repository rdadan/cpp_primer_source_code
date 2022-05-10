#include "../../head.h"

// 静态成员只有一份，属于类，由全部对象共享
// 静态成员变量
// 1.在类内声明，类外定义(不再加static)
// 2.静态成员变量不属于某个对象，所以为对象分配的空间不包括 静态成员变量的空间
// 3.静态成员变量可以通过类名直接访问，也可以通过对象名调用
class Person
{
public:
    Person()
    {
        m_age = 0;
        m_name = (char *)malloc(strlen("123") + 1);
        strcpy(m_name, "123");
        cout << "PersonCplus() age: " << m_age << " name: " << m_name << endl;
    }
    Person(int age, const char *name)
        : m_age(age)
    {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        cout << "PersonCplus(,) age: " << m_age << " name: " << m_name << endl;
    }

  
    ~Person()
    {
        if (m_name != NULL)
        {
            delete m_name;
            m_name = NULL;
        }
    }

public:
    static void setPublicNum(int num)
    {
        s_PublicNum = num;
        // m_age = num; //static函数访问不到非static的变量
    }

    static void setPrivateNum(int num)
    {
        s_PrivateNum = num;
    }

    static int getPrivateNum() { return s_PrivateNum; }

private:
    static int _getPrivateNum() { return s_PrivateNum; }

public:
    static int s_PublicNum;

private:
    int m_age;
    char *m_name;
    static int s_PrivateNum;
};

// private可以直接初始化, 但是不能直接访问， 要通过静态成员函数访问
int Person::s_PrivateNum = 0;
// public可以直接初始化， 也可以直接访问
int Person::s_PublicNum = 0;

void tStaticVariable()
{
    // 1. 通过类名访问
    // private 访问不到
    // cout << "s_PrivateNum: " << Person::s_PrivateNum << endl;
    cout << "s_PublicNum: " << Person::s_PublicNum << endl;

    // 2. 对象名访问
    Person per1, per2;
    per1.s_PublicNum = 100;
    cout << "s_Other: " << per2.s_PublicNum << endl;
}

// 静态成员函数
// 是为了管理静态成员变量，所以不能访问非静态的变量
// 访问方法，访问权限和静态成员变量一样
void tStaticFuc()
{
    Person::setPublicNum(20);
    cout << "s_PublicNum: " << Person::s_PublicNum << endl;
    
    Person::setPrivateNum(200);
    // cout << "s_PrivateNum: " << Person::s_PrivateNum << endl; //私有的直接访问不到

    cout << "s_PrivateNum: " << Person::getPrivateNum() << endl;
    // cout << Person::_getPrivateNum() << endl; //私有的直接访问不到
}

// const 静态成员
// 既实现共享，又实现不可改变（只读区）
// 类内部初始化
int main()
{
    tStaticFuc();
    return 0;
}