// Last Update:2013-08-27 19:35:24
/**
 * @file b.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-08-27
 */
#include <iostream>

template <typename T>
class MyClass
{
public:
    explicit MyClass(const T& value) : value_(value)
    {
    }
    template<typename T2>
    void assign(const MyClass<T2>& x)
    {
        value_ = x.value_;
    }
private:
    T value_;
};

int main(int argc, char* argv[])
{
    MyClass<int> a(3);
    MyClass<double> b(4.0);
    a.assign(b);

    return 0;
}
