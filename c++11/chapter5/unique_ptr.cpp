// Last Update:2013-10-01 05:34:16
/**
 * @file unique_ptr.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-10-01
 */
#include <memory>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    unique_ptr<string> up(new string("maoxin"));
    (*up)[0] = 'N';
    up->append("lai");
    cout << *up << endl;

    // unique_ptr<int> up1 = new int; // won't complie
    unique_ptr<int> up1(new int);

    // two ways to set a unique_ptr to point to a nullptr
    up1 = nullptr;
    up.reset();

    // give up ownership
    unique_ptr<string> up2(new string("hello"));
    string* ptr = up2.release();

    // the following code is the correct way to compare an empty unique_ptr to a nullptr
    if (!up2)
    {
       cout << "after release ownership, up2 must be nullptr now" << endl;
    }
    
    if (up2 == nullptr)
    {
        cout << "after release ownership, up2 must be nullptr now" << endl;
    }

    if (up2.get() == nullptr)
    {
        cout << "after release ownership, up2 must be nullptr now" << endl;
    }
    
    unique_ptr<string> up3(new string("world"));
    // unique_ptr<string> up4(up3); // won't complie
    unique_ptr<string> up4(move(up3));

    unique_ptr<string> up5(new string());
    unique_ptr<string> up6;
    // up5 = up6; // won't complie
    up5 = move(up6);

    // we have to explicit assign a unique_ptr
    unique_ptr<string> ptr1;
    // ptr = new string(); // won't complie
    ptr1 = unique_ptr<string>(new string());
    ptr1 = nullptr;
    // unique_ptr with array
    unique_ptr<int[]> p(new int[10]); 
    return 0;
}
