#include "../head.h"

// 1.const 变量初始化
// 如果用一个对象去初始化另一个对象，它们是不是const都无关紧要
void test01()
{
    int i = 42;
    const int ci = i; // ok
    int j = ci;       // ok
    // ci 的常量特征仅仅在改变ci的时候才会体现处理
    //用ci去初始化j时，无需在意ci是不是常量。因为拷贝一个对象不会去改变它
    // 一旦拷贝完成，新的对象就和原理的对象没关系了
}

// 2.默认状态下，const对象仅在文件内有效
// const int bufsize = 512;
// 编译器将在编译过程中把用到bufsize的地方都替换成512
// 当多个文件都出现了同名的 const 变量时，这相当于在不同文件中分别定义了独立的变量
// 那么如何在只在一个文件中定义const变量，能够在其他文件中声明并使用它呢
// 方法是，不管是声明还是定义都加上extern关键字
// file1.cpp 定义并初始化一个常量
// extern const int bufsize = func();
// file.h 头文件, 指明bufsize并非本文件所有，它的定义将在别处出现
// extern const int bufsize;

// 3 对const的引用（常量引用）
void test03()
{
    const int ci = 42;
    const int &r1 = ci; // ok 常量引用
    cout << "ci :" << ci << endl;
    cout << "r1 :" << r1 << endl;

    // r1 = 40; // err r1是对常量的引用
    // int &r2 = ci; // err 不能将非常量引用指向一个常量对象
}
// 4 初始化和对常量的引用
void test04()
{
    int i = 42;
    const int &r1 = i;            // 允许将const int&绑定到普通int对象上 why?
    i = 44;                       // i = r1 = 44
    cout << "i :" << i << endl;   // 44
    cout << "r1 :" << r1 << endl; // 44
    // ri = 45;        // err
    const int &r2 = 42;     // r2是常量引用
    const int &r3 = r1 * 2; // r3是常量引用
    // int &r4 = r1 * 2;       // r4是普通的非常量引用，其初始值必须为左值

    // 引用的类型必须和它引用的对的类型一致， 但是有两个例外
    // 第一个例外就是 允许将const int&绑定到普通int对象上
    // 那么当一个常量引用被绑定到另外一种类型上发生了什么？
    double dval = 3.14;
    const int rd = dval;              // ok
    cout << "dval :" << dval << endl; // 3.14
    cout << "rd :" << rd << endl;     // 3
    dval = 6.28;
    cout << "dval :" << dval << endl; // 6.28
    cout << "rd :" << rd << endl;     // 3 rd并没有改变
    // // 编译器会把上面代码改成下面形式：
    // const int tmp = dval;
    // const int &rd = tmp; // 事实上，rd是绑定在一个临时变量上的,而非dval
}

// 5 对const的引用可能引用一个非const的对象
void test05()
{
    int i = 42;
    int &r1 = i;
    const int &r2 = i;
    r1 = 0; // r2尽管是常量引用，但是它还是被改变了
    // r2 = 0; // err
}

// 6 指向常量的指针 point to const，
// 不要求这个指针指向的对象必须常量，只是规定不能通过该指针改变其对象的值
void test06()
{
    const double pi = 3.14; // pi是个常量，它的值不能被改变
    // double *ptr = &pi;        // err, ptr是个普通指针
    const double *cptr = &pi; // ok cptr是个常量指针 const修饰的是 *cptr， 所有不能改变 *cptr的值
    // *cptr = 6.28;             // err 不能给*ptr赋值

    double dval = 3.14; // dval的值可以改变
    cptr = &dval;       // ok ，但是不能通过cptr改变dval的值
}

// const指针 const pointer 常量指针
// 必须初始化。一旦初始化完成，则它的值（就是存放在指针中的那个地址）就不能再被改变
void test07()
{
    int num = 0;
    int *const pnum = &num; // pnum将一直指向num，const 修饰的是pnum， 所有不能改变pnum的值
    int num2 = 0;
    // pnum = &num2; // err表达式必须是可修改的左值
    *pnum = 10; // ok, num值也被改成10
}

void test08()
{
    const int num = 0;
    // 不能改变pnum，也不能改变 *pnum
    const int *const pnum = &num;

    class C
    {
    public:
        int getNum() const { return this->m_num; }

        //成员函数是通过隐私参数this来访问它的对象的。
        // 通过对象obj调用成员函数时obj.getNum()， 编译器会把对象的地址传给this C::getNum(&obj)
        // 默认情况下， this的类型是 C *const this, 所有这个this是和对象严格绑定的，
        // 即this是常量指针， 不能改变它的指向
        // 这里的成员函数在参数列表后面又加了 const， this的类型就变成了 const C *const this
        // 所有C::getNum(), 只能读取值，不能改变值了
    private:
        int m_num;
    };
}

int main()
{
    test08();
    return 0;
}