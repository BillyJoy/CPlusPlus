// Last Update:2013-10-01 06:09:53
/**
 * @file unique_ptr1.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-10-01
 */
#include <memory>
#include <string>
#include <iostream>
using namespace std;

// The following code won't complie due to use copy constructor and assignment without define it
class Test
{
public:
    explicit Test(int a) : ptr_(new int(a))
    {
    }
    bool empty()
    {
        if (!ptr_)
        {
            return true;
        }
        
        return false;
    }
private:
    unique_ptr<int> ptr_;
};

int main(int argc, char* argv[])
{
    Test t1(1);
    Test t2(2);
    Test t3(3);
    t1 = t2;
    Test t4 = t3;
    return 0;
}
