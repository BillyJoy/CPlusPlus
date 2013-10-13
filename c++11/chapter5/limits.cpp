// Last Update:2013-10-01 16:33:24
/**
 * @file limits.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-10-01
 */
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    cout << boolalpha;

    cout << "max(short): " << numeric_limits<short>::max() << endl;
    cout << "max(int): " << numeric_limits<int>::max() << endl;
    cout << "max(long): " << numeric_limits<long>::max() << endl;
    cout << endl;

    cout << "max(float): " << numeric_limits<float>::max() << endl;
    cout << "max(double): " << numeric_limits<double>::max() << endl;
    cout << "max(long double): " << numeric_limits<long double>::max() << endl;
    cout << endl;

    cout << "is_signed(char) :" << numeric_limits<char>::is_signed << endl;
    cout << endl;

    cout << "is_specialized(string): " << numeric_limits<string>::is_specialized << endl;
    return 0;
}
