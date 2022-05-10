#include "../head.h"
int A_MyDivide(int a, int b)
{
    if (b == 0)
    {
        throw 0;
    }

    return a / b;
}

// B写的代码 B写代码比较粗心，忘记处理异常
int B_MyDivide(int a, int b)
{

    int ba = a;
    int bb = b;
    int ret = 0;
    // 没有处理异常，程序直接中断执行
    // ret = B_MyDivide(a, b);

    // 处理异常
    try
    {
        ret = A_MyDivide(ba, bb) + 100; //由于B没有处理异常，导致B结果运算错误
    }
    catch (int e)
    {
        cout << "B_MyDivide Call A_MyDivide 除数为:" << e << endl;
    }
    return ret;
}

// C写的代码
int C_MyDivide()
{

    int a = 10;
    int b = 0;

    int ret = 0;

    // //没有处理异常，程序直接中断执行
    // ret = B_MyDivide(a, b);

    //处理异常
    try
    {
        ret = B_MyDivide(a, b); //更严重的是，由于B没有继续抛出异常，导致C的代码没有办法捕获异常
    }
    catch (int e)
    {
        cout << "C_MyDivide Call B_MyDivide 除数为:" << e << endl;
    }

    return ret;
}

void TestFunction()
{

    cout << "开始抛出异常..." << endl;
    // throw 10; //抛出int类型异常
    // throw 'a'; //抛出char类型异常
    // throw "abcd"; //抛出char*类型异常
    // char c = 's';
    // throw c;
    // char *cp = "s";
    // throw cp;
    string ex = "string exception!";
    throw ex;
}

//异常机制和函数机制互不干涉,但是捕捉方式是通过严格类型匹配。
void test02()
{

    try
    {
        TestFunction();
    }
    catch (int)
    {
        cout << "抛出Int类型异常!" << endl;
    }
    catch (char)
    {
        cout << "抛出Char类型异常!" << endl;
    }
    catch (char *)
    {
        cout << "抛出Char*类型异常!" << endl;
    }
    catch (string)
    {
        cout << "抛出string类型异常!" << endl;
    }
    //捕获所有异常
    catch (...)
    {
        cout << "抛出其他类型异常!" << endl;
    }
}

int main()
{

    test02();

    return 0;
}
