// Last Update:2013-10-01 06:28:08
/**
 * @file unique_ptr2.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-10-01
 */
#include <memory>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Test
{
public:
    void operator()(Test* p)
    {
        cout << "call delete for Test" << endl;
        delete p;
    }
};
int main(int argc, char* argv[])
{
    // the second template parameter is a deleter
    unique_ptr<Test,Test> up(new Test());
    unique_ptr<int, void(*)(int*)> up1(new int[10], [](int* p){delete [] p;});
    unique_ptr<int, function<void(int*)>> up2(new int[10], [](int* p){delete [] p;});
    return 0;
}
