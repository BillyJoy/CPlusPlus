// Last Update:2013-08-12 17:59:33
/**
 * @file test.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-08-12
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

template<class T>
struct Base
{
    void foo()
    {
        cout << "Base<T>::foo" << endl;
    }
};

template<class T>
struct Test : public Base<T>
{
    void print()
    {
        Base<T>::foo();
    }
};

template<typename T, int n>
T addValue(const T& value)
{
    return value + n;
}

int main(int argc, char* argv[])
{
    vector<int> ivec;
    vector<int> dst_vec(10);
    for (size_t i = 0; i < 10; ++i)
    {
        ivec.push_back(i);
    }
    
    transform(ivec.begin(), ivec.end(), dst_vec.begin(), addValue<int, 10>);
    for_each (dst_vec.begin(), dst_vec.end(), [](int x){ cout << x << " ";});
    cout << endl;

    Test<int> t;
    t.print();

    set<int> iset;
    for (int i = 9; i >=0; --i)
    {
        iset.insert(i);
    }

    for_each(iset.begin(), iset.end(), [] (int x){ cout << x << " ";});
    cout << endl;
    return 0;
}
