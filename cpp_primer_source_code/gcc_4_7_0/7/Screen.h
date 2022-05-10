/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
 */
#ifndef _sereen_h
#define _sereen_h
#include <string>
#include <iostream>

class Screen
{
public:
    // typedef std::string::size_type pos;
    using pos = std::string::size_type;
    Screen() = default; // needed because Screen has another constructor
                        // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
    {
        cout << " Screen(pos ht, pos wd, char c)" << endl;
    }
    // Window_mgr是Screen的友元,可以访问Screen的私有部分
    friend class Window_mgr;

    Screen(pos ht = 0, pos wd = 0)
        : cursor(0), height(ht), width(wd), contents(ht * wd, ' ')
    {
        cout << " Screen(pos ht = 0, pos wd = 0)" << endl;
    }

    char get() const { return contents[cursor]; } // 读取光标处的字符， 隐式内联
    inline char get(pos ht, pos wd) const;        // 显示内联, 返回指定行列位置的字符
    Screen &clear(char = bkground);

private:
    static const char bkground = ' ';

public:
    Screen &move(pos r, pos c); // 可以在类外被内联
    Screen &set(char);
    Screen &set(pos, pos, char);

    // 返回一个非常量引用,通过区分成员函数是否是const，可以重载
    // 因为const对象只能调用const成员。尽管非const对象两个都能，但是调用非const的更合适
    Screen &display(std::ostream &os)
    {
        cout << "Screen &display" << endl;
        do_display(os);
        return *this;
    }
    // 返回一个常量的引用。
    // 后面的const，将this变成一个指向const的指针，this指向的成员变量不能改变
    // 前面的const, 使*this变成一个const对象， 返回的对象本身将不能被改变
    const Screen &display(std::ostream &os) const
    {
        cout << "const Screen &display" << endl;
        do_display(os);
        return *this;
    }
    void get_mutable_num() const;

public:
private:
    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const
    {
        os << contents;
    }
    pos cursor = 0;            // 光标当前位置
    pos height = 0, width = 0; // 屏幕高和宽
    std::string contents;      // 屏幕内容
private:
    // mutable 定义一个可变数据成员, 它永远不会是const， 即使它是const对象的成员
    mutable size_t mutable_num; //即使在const成员函数内也能被修改
};
void Screen::get_mutable_num() const
{
    mutable_num++;
}
Screen &Screen::clear(char c)
{
    contents = std::string(height * width, c);
    return *this;
}
//在定义中指定inline， Screen &返回对象本身（而不是返回拷贝）
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; // compute the row location
    cursor = row + c;    // move cursor to the column within that row
    return *this;        // 将this对象最为左值返回， 即返回对象本身
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width;      // 计算行row位置
    return contents[row + c]; // 返回给定列的字符column
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this;         // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; // set specified location to given value
    return *this;                   // return this object as an lvalue
}

#endif