#include <iostream>
#include <string>
#include <vector>
#include <thread>

struct A
{
    std::string name = "blacksmith";
    int age = 100;
};

struct B1
{
    std::string local_name = "jd-B1";

    void func1(A* a)
    {
        while (true)
        {
            a->name = local_name;
            std::string key = local_name + "**";
        }
    }
};

struct B2
{
    std::string local_name = "jd-B2";

    void func1(A* a)
    {
        while (true)
        {
            a->name = local_name;
            std::string key = local_name + "**";
        }
    }
};


int main()
{
    /**
     * 探测是否支持 COW
     */
    std::string* test = new std::string("blacksmith");
    std::string name = *test;
    std::cout << "test:" << test->data() << ", name=" << name.data() << std::endl;
    if (test->data() == name.data())
    {
        std::cout << "COW(Copy On Write) support!" << std::endl;
    }
    else
    {
        std::cout << "COW(Copy On Write) NOT support!" << std::endl;
    }
    delete test;


    /**
     * 多线程操作
     */
    std::vector<std::thread> th_vec;
    int thread_count = 4;
    A a;
    B1 b1;
    B2 b2;
    for (int i = 0; i < thread_count; i++)
    {
        th_vec.emplace_back([&]()
        {
            b1.func1(&a);
        });
        th_vec.emplace_back([&]()
        {
            b2.func1(&a);
        });
    }

    for (auto& item : th_vec)
    {
        item.join();
    }

    std::cout << "=========END==========" << std::endl;

    return 0;
}
