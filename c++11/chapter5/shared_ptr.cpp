// Last Update:2013-09-29 17:27:57
/**
 * @file shared_ptr.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-29
 */
#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char* argv[])
{
    shared_ptr<int> p(new int[10], [](int* p){cout << "ready to delete p" << endl;delete [] p;});
    shared_ptr<int> p1(new int[10], std::default_delete<int[]>());
    p.reset();
    return 0;
}
