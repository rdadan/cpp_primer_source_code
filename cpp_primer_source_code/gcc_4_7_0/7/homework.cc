// #include "../GCC_4_7_0/7/Sales_data.h"
#include "Sales_data.h"
#include <iostream>

using namespace std;
using std::istream;
using std::ostream;

int main()
{
    Sales_data total;
    read(cin, total);
    print(cout, total);
    return 0;
}