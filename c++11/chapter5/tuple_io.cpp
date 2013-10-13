// Last Update:2013-09-26 20:42:32
/**
 * @file tuple_io.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-26
 */
#include <iostream>
#include <string>
#include "tuple_io.h"
using namespace std;

int main(int argc, char* argv[])
{
    tuple<int, string, float, char> t(1, "maoxin", 1.2, 'c');
    cout << t << endl;
    return 0;
}
