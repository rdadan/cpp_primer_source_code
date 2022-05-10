#include "ex7_32_screen.h"
// #include "ex7_32_window_mgr.h"
#include <iostream>
using namespace std;
int main()
{
    Screen myScreen(5, 3);
    cout << "\n---------------------" << endl;
    Screen myScreen2(5, 3, '?'); // ??? ??? ??? ??? ???
    myScreen2.set(2, 2, '!').display(cout);
}