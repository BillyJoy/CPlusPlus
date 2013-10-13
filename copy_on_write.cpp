// Last Update:2013-09-15 15:13:32
/**
 * @file copy_on_write.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-15
 */
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[])
{
    string str1("hello world!");
    string str2(str1);

    cout << "sharing the memory" << endl;
    printf("str1's address:%x\n", str1.c_str());
    printf("str2's address:%x\n", str2.c_str());

    str1[1] = 'q';
    str2[1] = 'w';

    printf("After Copy-On-Write\n");
    printf("str1's address:%x\n", str1.c_str());
    printf("str2's address:%x\n", str2.c_str());
    return 0;
}
