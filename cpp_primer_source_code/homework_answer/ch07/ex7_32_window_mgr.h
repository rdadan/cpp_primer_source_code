//
//  ex7_32.h
//  Exercise 7.32
//
//  Created by pezy on 11/18/14.
//
//  @See ex7_27.h

#ifndef CP5_ex7_32_win_mgr_h
#define CP5_ex7_32_win_mgr_h

#include <vector>
#include <string>
#include <iostream>

class Screen;

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

inline void Window_mgr::clear(ScreenIndex i)
{
    if (i >= screens.size())
        return; // judge for out_of_range.
    // Screen *s = &(screens[i]);
    screens[i].contents = std::string(screens[i].height * screens[i].width, ' ');
}

#endif
