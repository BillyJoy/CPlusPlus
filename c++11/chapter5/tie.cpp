// Last Update:2013-09-26 19:07:07
/**
 * @file tie.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-26
 */
#include <utility>
#include <iostream>
#include <tuple>
using namespace std;

int main(int argc, char* argv[])
{
    pair<char, char> p = make_pair('x', 'y');
    char c;
    tie(ignore, c) = p;
    return 0;
}
