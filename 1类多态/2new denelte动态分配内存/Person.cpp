#include "../../head.h"

class PersonC
{
public:
    PersonC(int age, const char *name)
        : m_age(age)
    {
        // c动态申请内存
        m_name = (char*)malloc(strlen(name)+1);
        strcpy(m_name, name);
        cout << "age: " << age << " name: " << m_name << endl;
    }

    void initPerson(int age, const char *name)
    {
        m_age = age;
        // c动态申请内存
        m_name = (char *)malloc(strlen(name) + 1);
        strcpy(m_name, name);
        cout << "initPerson() age: " << age << " name: " << m_name << endl;
    }
    void freePerson()
    {
        if (NULL != m_name)
        {
            cout << "freePerson()" << endl;
            free(m_name);
            m_name = NULL;
        }
    }

    ~PersonC()
    {
        if(NULL != m_name)
        {
            cout << "~PersonC()" << endl;
            free(m_name);
            m_name = NULL;
        }
    }
private:
    int m_age;
    char *m_name;
};

int testC()
{
    // 调用 构造
    // string name = "shangsi";
    // PersonC per1(22, name.c_str());
    cout << "testC()" << endl;
    // malloc 不调用类的构造
    PersonC *pPer = (PersonC*)malloc(sizeof(PersonC));
    if (NULL == pPer)
    {
        return -1;
    }
    // 手动初始化
    pPer->initPerson(44, "ZhangSan");
    // 手动释放
    pPer->freePerson();

    free(pPer);
    cout << "testC() over" << endl;
    return 0;
}

class PersonCplus
{
public:
    PersonCplus()
    {
        m_age =0;
        // m_name = new char[strlen("123") + 1];
        m_name = (char *)malloc(strlen("123") + 1);
        strcpy(m_name, "123");
        cout << "PersonCplus() age: " << m_age << " name: " << m_name << endl;
    }
    PersonCplus(int age, const char *name)
        : m_age(age)
    {
        // c++动态申请内存
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        cout << "PersonCplus(,) age: " << m_age << " name: " << m_name << endl;
    }

    ~PersonCplus()
    {
        if (m_name != NULL)
        {
            delete m_name;
            m_name = NULL;
        }
    }

private:
    int m_age;
    char *m_name;
};

// new delete
int testCplus()
{
    // new 分配内存，调用构造
    PersonCplus *pPer = new PersonCplus(100, "1234");
    PersonCplus *pPer2 = new PersonCplus;

    // delete 调用析构，释放内存
    delete pPer; // 不能使用  delete []
    delete pPer2;
    return 0;
}

// 数组的new 和 delete
int testCplusArr()
{
    // 栈上聚合初始化， 会自动释放（2次）
    PersonCplus pPer[] = { PersonCplus(100, "aa"), PersonCplus(200, "aaa")};

    // new创建数组对象不能指定初始值，所以必须提供无参的构造函数
    PersonCplus *pPers = new PersonCplus[3];
    delete[] pPers; // 必须使用  delete [] 释放三次

    return 0;
}

int main()
{
    testCplusArr();
    return 0;
}