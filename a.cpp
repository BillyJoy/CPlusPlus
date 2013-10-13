// Last Update:2013-08-21 20:49:02
/**
 * @file a.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-08-21
 */
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    void f()
    {
        cout << "Base::f" << endl;
    }
    
    void f(int)
    {
        cout << "Base::f(int)" << endl;
    }
private:
    int a;
};

class Derived : private Base
{
public:
    using Base::f;

    void f(const string& str)
    {
        a = 5;
        cout << "Derived::f" << endl;
    }
};

int main(int argc, char* argv[])
{
    Derived d;
    d.f(2);
    return 0;
}
