#include "../../head.h"
class Person
{
public:
    Person() { cout << "默认构造" << endl; }
    Person(int age, const char *name)
    {
        cout << "Person赋值构造" << endl;
        mAge = age;
        mName = new char[strlen(name) + 1];
        strcpy(mName, name);
    }
    Person(const Person &person)
    {
        cout << "Person深拷贝构造" << endl;
        mAge = person.mAge;
        mName = new char[strlen(person.mName) + 1];
        strcpy(mName, person.mName);
    }


    // 重载赋值运算符
    Person &operator=(Person &p) //传引用，省去一个临时的拷贝构造
    {
        cout << "Person operator=" << endl;
        if (&p == this) //自己给自己赋值就直接返回自己
            return *this;

        // 如果当前对象以及存在，先将他原先占用的内存释放干净
        if (this->mName != NULL)
        {
            delete[] this->mName;
        }
        this->mName = new char[strlen(p.mName) + 1];
        strcpy(mName, p.mName);

        mAge = p.mAge;
        return *this;
    }

    void printPerson()
    {
        cout << "age: " << mAge << " name: " << mName << endl;
    }
    // 析构函数
    ~Person()
    {
        if (mName != NULL)
        {
            cout << "~Person()" << endl;
            delete[] mName;
            mName = NULL;
        }
    }

private:
    int mAge;
    char *mName;
};


class SmartPointer
{
public:
    SmartPointer(Person *p)
    {
        cout << "SmartPointer()" << endl;
        _p = p;
    }    
    // 重载->
    Person * operator->()
    {
        cout << "operator->()" << endl;
        return _p;
    }

    // 重载 *
    Person & operator*()
    {
        cout << "operator*()" << endl;
        return *_p;
    }

    ~SmartPointer()
    {
        if(_p != NULL)
        {
            cout << "~SmartPointer()" << endl;
            delete _p;
            _p = NULL;
        }
    }

private:
    Person *_p;
};

void test01()
{
    unique_ptr<Person> pPerson(new Person(22, "'afaf")); // C++11 把auto_ptr废弃
    pPerson->printPerson();
}
void test02()
{
    SmartPointer smartPerson(new Person(22,"zhang"));
    smartPerson->printPerson();

    cout << "--" << endl;
    Person p2 = *smartPerson;
    p2.printPerson();
}

int main()
{
    test01();
    return 0;
}