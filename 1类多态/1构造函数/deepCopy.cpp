#include "../../head.h"

class Person
{
public:
    Person(const char *name);
    // 提供深拷贝
    Person(const Person &p);
    ~Person()
    {
        if (m_Name != NULL)
        {
            cout << "析构函数" << endl;
            delete m_Name;
            m_Name = NULL;
        }

    }

private:
    char *m_Name;
};

Person::Person(const char *name)
{
    cout << "有参构造函数" << endl;
    m_Name = new char[strlen(name) + 1];
    strcpy(m_Name, name);
}

// 默认的拷贝构造函数是浅拷贝；有堆内存需要提供深拷贝
Person::Person(const Person &p)
{
    cout << "深拷贝，拷贝构造函数" << endl;
    // 给构造的函数申请空间
    m_Name = new char[strlen(p.m_Name) + 1];
    strcpy(m_Name, p.m_Name);
}

void tCopy()
{
    Person per1("lisi");
    Person per2 = per1;
}

int main()
{
    tCopy();
    return 0;
}