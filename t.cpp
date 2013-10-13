// Last Update:2013-08-20 20:21:44
/**
 * @file t.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-08-20
 */
#include <iostream>
namespace X
{
    template<typename T> void f(T);
}

namespace N
{
    using namespace X;
    enum E
    {
        e1
    };

    void f(E)
    {
        std::cout << "N::f(N::E) called\n";
    }
}

void f(int)
{
    std::cout << "::f(int) called\n";
}

int main()
{
    ::f(N::e1);
    f(N::e1);
    return 0;
}
