// Last Update:2013-09-29 17:41:44
/**
 * @file shared_ptr2.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-29
 */
#include <string>
#include <fstream>
#include <memory>
#include <cstdio>
using namespace std;

class FileDeleter
{
public:
    FileDeleter(const string& file_name) : file_name_(file_name)
    {
    }
    void operator()(ofstream* fp)
    {
        fp->close();
        remove(file_name_.c_str());
    }
private:
    string file_name_;
};

int main(int argc, char* argv[])
{
    shared_ptr<ofstream> fp(new ofstream("tmpfile"), FileDeleter("tmpfile"));
    if (fp)
    {
        *fp << "maoxin is a good man!" << endl;
    }
    return 0;
}
