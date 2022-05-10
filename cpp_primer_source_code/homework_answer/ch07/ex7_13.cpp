//
//  ex7_13.cpp
//  Exercise 7.13
//
//  Created by pezy on 11/9/14.
//

#include "ex7_12.h"

int main()
{
    cout << " is >> item.bookNo >> item.units_sold >> price " << endl;
    Sales_data total(std::cin);
    if (!total.isbn().empty())
    {
        std::istream &is = std::cin;
        while (is)
        {
            Sales_data trans(is);
            if (!is)
                break;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        cout << "total: " << endl;
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}
