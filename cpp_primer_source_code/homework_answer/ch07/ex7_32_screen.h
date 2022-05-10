//
//  ex7_32.h
//  Exercise 7.32
//
//  Created by pezy on 11/18/14.
//
//  @See ex7_27.h

#ifndef CP5_ex7_32_screen_h
#define CP5_ex7_32_screen_h

#include <vector>
#include <string>
#include <iostream>
#include "ex7_32_window_mgr.h"

class Screen
{
    using ScreenIndex = std::vector<Screen>::size_type;

    friend void Window_mgr::clear(ScreenIndex);

public:
    using pos = std::string::size_type;

    Screen() = default;                                                             // 1
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}       // 2
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {} // 3

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }
    inline Screen &move(pos r, pos c);
    inline Screen &set(char c);
    inline Screen &set(pos r, pos c, char ch);

    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const { os << contents; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}

#endif
