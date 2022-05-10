#include "../../head.h"

class A
{

public: // 可以类外访问， 可以继承
    int pub;

protected: // 不可以类外访问，可以继承
    int pro;

private: // 不可以类外访问，可以继承
    int pri;
};

class A1 : public A // 基类中的属性在A2中保持不变
{
    void print()
    {
        pub = 1;
        pro = 2;
        // pri=3;//父类私有的访问不到
    }
};
class A1_1 : public A1
{
    void print()
    {
        pub = 1;
        pro = 2;
        // pri=3; //父类私有的访问不到
    }
};

class A2 : protected A // 基类中的public属性在A2中都变成protected
{
    void print()
    {
        pub = 1;
        pro = 2;
        // pri=3; //父类私有的访问不到
    }
};
class A2_1 : public A2
{
    void print()
    {
        pub = 1;
        pro = 2;
        // pri=3; //父类私有的访问不到
    }
};

class A3 : private A // 基类中的属性都在A3中都变成prvate
{
    void print()
    {
        pub = 1;
        pro = 2;
        // pri=3; //父类私有的访问不到
    }
};

class A3_1 : public A3
{
    void print()
    {
        // pub = 1; // 不可访问
        // pro = 2; // 不可访问
        // pri=3; //父类私有的访问不到
    }
};

void test01()
{
    A objA;
    objA.pub;

    A1 objA1;
    objA1.pub;

    A2 objA2;
    // objA2.pub; // pub变pro类外访问不到

    A3 objA3;
    // objA3.pub; // pub变pri类外访问不到
}