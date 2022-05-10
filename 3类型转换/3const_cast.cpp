#include "../head.h"

// 该运算符用来修改类型的const属性。仅用于指针或者引用
// 	常量指针被转化成非常量指针，并且仍然指向原来的对象；
// 	常量引用被转换成非常量引用，并且仍然指向原来的对象；

// 注意:不能直接对非指针和非引用的变量使用const_cast操作符去直接移除它的const.
//常量指针转换成非常量指针
void test01()
{

    const int *p = NULL;
    int *np = const_cast<int *>(p);

    int *pp = NULL;
    const int *npp = const_cast<const int *>(pp);

    const int a = 10; //不能对非指针或非引用进行转换
    // int b = const_cast<int>(a);
}
//常量引用转换成非常量引用
void test02()
{

    int num = 10;
    int &refNum = num;

    const int &refNum2 = const_cast<const int &>(refNum);
}
