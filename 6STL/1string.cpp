#include "../head.h"

// 1 string 和 char* 互转
void test01()
{
    string str = "hello";
    const char *cstr = str.c_str();
    cout << "cstr: " << cstr << endl;
    char *c = (char *)"world";
    char const *c2 = "world";
    c2 = "eee";
    str = string(c2);
    cout << "str: " << str << endl;
}

// 2 string 构造
void test02()
{
    //默认构造
    string str0;
    str0 = "str0";
    // 带参构造
    string str5(10, 'a');
    string str2("str2");

    //拷贝构造
    string str1 = "str1";
    string str3 = str1;
    string str4(str2);
}

// 3 string 赋值
void test03()
{
    string str = "hello"; //字符赋值给当前的字符串
    str.assign("hello");  //字符赋值给当前的字符串

    str.assign("hello", 3); //把字符串s的前n个字符赋给当前的字符串

    str.assign(3, 'h');        //用n个字符c赋给当前字符串
    str.assign("hello", 1, 3); //将s从start开始n个字符赋值给字符串
    cout << str << endl;
}

// string 存器
void test04()
{
    string str = "hello";
    // cout << str[100] << endl; //越界挂程序
    cout << str.at(10) << endl; //越界抛异常
}
// string查找和替换
void test05()
{
    string str = "ab";

    string s(&str[0]);
    cout << s << endl;

    cout << str.substr(0, 1) << endl;
}
int main()
{
    test05();
    return 0;
}