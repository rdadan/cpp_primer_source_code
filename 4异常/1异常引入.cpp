#include "../head.h"

//如果判断返回值，那么返回值是错误码还是结果？
//如果不判断返回值，那么b==0时候，程序结果已经不正确
// A写的代码
int A_MyDivide(int a, int b)
{

    if (b == 0)
    {
        cout << "A_MyDivide, ret: " << -1 << endl;
        return -1;
    }
    int ret = a / b;
    cout << "A_MyDivide, ret: " << ret << endl;

    return ret;
}

// B写的代码
int B_MyDivide(int a, int b)
{
    int ba = a + 100;
    int bb = b;
    int ret = A_MyDivide(ba, bb); //由于B没有处理异常，导致B结果运算错误
    cout << "B_MyDivide, ret: " << ret << endl;

    return ret;
}

// C写的代码
int C_MyDivide()
{
    int a = 10;
    int b = 0;
    int ret = B_MyDivide(a, b);                 //更严重的是，由于B没有继续抛出异常，导致C的代码没有办法捕获异常
    cout << "C_MyDivide, ret: " << ret << endl; // 没处理异常导致的是错误的结果
    if (ret == -1)
    {
        return -1;
    }
    else
    {
        return ret;
    }
}

// 所以,我们希望：
// 1.异常应该捕获，如果你捕获，可以，那么异常必须继续抛给上层函数,你不处理，不代表你的上层不处理
// 2.这个例子，异常没有捕获的结果就是运行结果错的一塌糊涂，结果未知，未知的结果程序没有必要执行下去

int main()
{
    C_MyDivide();
    return 0;
}