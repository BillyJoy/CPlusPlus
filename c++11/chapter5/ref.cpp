// Last Update:2013-09-26 19:04:11
/**
 * @file ref.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-26
 */
#include <utility>
#include <iostream>
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
    int i = 0;
    auto p = std::make_pair(ref(i), ref(i));
    ++p.first;
    ++p.second;
    cout << "i: " << i << endl;
    return 0;
}
