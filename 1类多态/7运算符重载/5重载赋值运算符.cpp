#include "../../head.h"
class Point
{
private:
    int mX;
    int mY;

public:
    Point() { cout << "默认构造" << endl;}
    Point(int x, int y)
    {
        mX = x;
        mY = y;
    }
    Point(const Point &p)
    {
        mX = p.mX;
        mY = p.mY;
        cout << "拷贝构造" << endl;
    }

    ~Point() {}

    friend ostream &operator<<(ostream & os,  const Point & p);

    Point & operator=(Point &p) //传引用，省去一个临时的拷贝构造
    {
        if (&p == this) //自己给自己赋值就直接返回自己
            return *this;
        this->mX = p.mX;
        this->mY = p.mY;
        cout << "operator=" << endl;
        return *this;
    }

};
class Person
{
private:
    int mAge;
    char * mName;

public:
    Person() { cout << "默认构造" << endl; }
    Person(int age, const char *name)
    {
        cout << "赋值构造" << endl;
        mAge = age;
        mName = new char[strlen(name) + 1];
        strcpy(mName, name);
    }
    Person(const Person &person)
    {
        cout << "深拷贝构造" << endl;
        mAge = person.mAge;
        mName = new char[strlen(person.mName) + 1];
        strcpy(mName, person.mName);
    }


    friend ostream &operator<<(ostream &os, const Person &p)
    {
        os << "age:" << p.mAge << " name:" << p.mName << endl;
        return os;
    }

    // 重载赋值运算符
    Person &operator=(Person &p) //传引用，省去一个临时的拷贝构造
    {
        cout << "operator=" << endl;
        if (&p == this) //自己给自己赋值就直接返回自己
            return *this;
        
        // 如果当前对象以及存在，先将他原先占用的内存释放干净
        if(this->mName != NULL)
        {
            delete [] this->mName;
        }
        this->mName = new char[strlen(p.mName)+1];
        strcpy(mName, p.mName);

        mAge = p.mAge;
        return *this;
    }
    // 析构函数
    ~Person()
    {
        if(mName != NULL)
        {
            cout << "~Person()" << endl;
            delete [] mName;
            mName = NULL;
        }
    }
};


// void test01()
// {
//     Point p1(1,1), p2(2,2);
//     cout << p1 << endl;
//     p1 = p2; // operator=
//     cout << p1 << endl;

//     Point p3 = p1; // 拷贝构造
//     cout << p3 << endl;

//     p1 = p1;
//     cout << p1 << endl;
// }

void test02()
{
    Person p1(22, "zhang");
    cout << p1 << endl;
    Person p2 = p1;
    cout << p2 << endl;

    p1 = p2;
    cout << p1 << endl;
}
int main()
{
    test02();
    return 0;
}