#include "../../head.h"

class Person
{
private:
    /* data */
public:
    Person();
    Person(const int age, const char *name);
    Person(const Person &p);
    ~Person();

public:
    int getAge()
    {
        return m_Age;
    }

private:
    int m_Age;
    char *m_Name;
};

Person::Person(/* args */)
{
    cout << "默认无参构造函数" << endl;
    m_Age = 0;
    m_Name = new char[32];
    strcpy(m_Name, "None");
    cout << "age:" << m_Age << " name: " << m_Name << endl;
}

Person::Person(const int age, const char *name)
{
    cout << "有参构造函数" << endl;
    m_Age = age;
    m_Name = new char[strlen(name) + 1];
    strcpy(m_Name, name);
    cout << "age:" << m_Age << " name: " << m_Name << endl;
}

Person::Person(const Person &p)
{
    cout << "拷贝构造函数" << endl;
    m_Age = p.m_Age;
    m_Name = new char[strlen(p.m_Name) + 1];
    strcpy(m_Name, p.m_Name);
    cout << "age:" << m_Age << " name: " << m_Name << endl;
}

Person::~Person()
{
    cout << "这是析构函数" << endl;
    if (NULL != m_Name)
        delete m_Name;
        m_Name = NULL;
}

void tConsructor()
{
    Person per0(12, "zhangsan");
    Person per1(12, "zhangsan");
    Person per2(per1);
    Person per3 = per1;
    Person per4 = Person(per1);
}
// 拷贝构造函数调用时机
// 1. 对象1初始化对象2
void tConstructionCase1()
{
    Person per0(12, "zhangsan");
    Person per2(per0);
    Person per3 = per0;
}

// 2. 函数参数是一个对象
void funcObj(Person per)
{
}
void tConstructionCase2()
{
    Person per0(12, "zhangsan");
    funcObj(per0);
}

// 3. 函数返回一个对象, dubug 模式下才会调用
Person funcObj2()
{
    Person tmp(44, "wanger");
    return tmp;
}
void tConstructionCase3()
{
    // 这样赋值有问题
    // Person per;
    // per = funcObj2();

    // 这样直接初始化ok
    Person per = funcObj2();
    cout << per.getAge() << endl;
}


class myTest
{
private:
    int m_a;
    int m_b;
public:
    myTest(int a, int b)
    {
        m_a = a;
        m_b = b;
    }
    myTest(int a)
    {
        m_a = a;
        myTest(a, 100); // 构造中调用构造危险行为，产生新的匿名对象
    }
    int getB()
    {
        return m_b;
    }
    ~myTest()
    {
        cout << "析构 myTest " << m_a << " " << m_b << endl;
    }
};

void test()
{
    myTest t = (1);
    cout << t.getB() << endl; // t.getB()=0, 而不是100
}

int main()
{
    test();
    return 0;
}