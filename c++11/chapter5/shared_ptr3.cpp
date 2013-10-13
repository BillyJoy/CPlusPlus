// Last Update:2013-09-29 18:38:18
/**
 * @file shared_ptr3.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-29
 */
#include <memory>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <cerrno>
#include <string>
#include <iostream>
using namespace std;

class SharedMemoryDetacher
{
public:
    void operator()(int* p)
    {
        cout << "unlink /tmp1234" << endl;
        if (shm_unlink("/tmp1234") != 0)
        {
            cout << "oops: shm_unlink() failed!" << endl;
        }
    }
};

shared_ptr<int> getSharedIntMemory(int num)
{
    void* mem;
    int shmfd = shm_open("/tmp1234", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0)
    {
        throw string(strerror(errno));
    }

    if (ftruncate(shmfd, num * sizeof(int)) == -1)
    {
        throw string(strerror(errno));
    }

    mem = mmap(nullptr, num * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (mem == MAP_FAILED)
    {
        throw string(strerror(errno));
    }

    return shared_ptr<int>(static_cast<int*>(mem), SharedMemoryDetacher());
}

int main(int argc, char* argv[])
{
    shared_ptr<int> smp(getSharedIntMemory(100));
    for (int i = 0; i < 100; ++i)
    {
        smp.get()[i] = i * 42;
    }
    cout << "<return>" << endl;
    smp.reset();
    return 0;
}
