#include "../head.h"

template <class Tname, class Tage>
class Person
{
private:
    Tname mName;
    Tage mAge;

public:
    Person(Tname &name, Tage age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
    Person operator+(Person &person);
};
template <class Tname, class Tage>
Person<Tname, Tage> Person<Tname, Tage>::operator+(Person<Tname, Tage> &person)
{
    mAge += person.mAge;
}
void test01()
{
    // 类模板不能进行类型自动推导
    // Person P1("ZhangSan", 18); // err missing template arguments before 'P1'

    //使用类模板需要指定参数类型
    string str = "ZhangSan";
    Person<string, int> P1(str, 18);
    P1.showPerson();
}
// 编译过程：预处理(将宏展开 .i文件)->编译器(汇编语言 .s)->汇编器(目标文件 .o)->链接器(可执行文件)

// 类模板的声明和实现必须放到一个文件中，我们把这个文件命名为.hpp(这个是个约定的规则，并不是标准，必须这么写).
// 原因：
// 	类模板需要二次编译，在出现模板的地方编译一次，在调用模板的地方再次编译。
//
// 	C++编译规则为独立编译。cpp文件里的东西都是相对独立的，
// 在编译一个.cpp文件时是不知道任何其他的.cpp文件的存在，
// 只需要在编译成目标文件（.o/.obj文件）后再与其他的目标文件做一次链接（link）就行了。

// 模板（或者struct）的编译，会根据你的具体调用生成相应的代码。
// 但是假如你没有任何调用，那么编译器也不会生成任何与此模板相关的代码。
#include "PersonT.hpp"

void test02()
{
    string str("WangEr");
    PersonT<string, int> p(str, 20);
    p.ShowPerson();
}

// 类模板中的static, StaticClass<int>, StaticClass<char>各自有自己的 staticVal
template <class T>
class StaticClass
{
public:
    static T staticVal;
};
template <class T>
T StaticClass<T>::staticVal = 0;

void test03()
{
    StaticClass<int> a1, a2;
    StaticClass<int>::staticVal = 10;
    StaticClass<int>::staticVal++;
    cout << "a1.staticVal: " << a1.staticVal << endl;
    cout << "a2.staticVal: " << a2.staticVal << endl;

    StaticClass<char> b1, b2;
    StaticClass<char>::staticVal = 'a';
    StaticClass<char>::staticVal++;

    cout << "a1.staticVal: " << b1.staticVal << endl;
    cout << "a2.staticVal: " << b2.staticVal << endl;
}
int main()
{
    test03();
    return 0;
}
