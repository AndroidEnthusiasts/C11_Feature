//
// Created by Jesson on 2021/2/24.
//
#include<thread>
#include<iostream>
#include<string>
#include<iostream>
#include<mutex>
#include<vector>
#include<iterator>
#include<thread>
#include<iostream>
#include<string>
std::mutex g_mutex;

void doThreadFunc(int n, char c)
{
    //std::lock_guard<std::mutex> lg(g_mutex); 这样写更好啊
    g_mutex.lock();

    std::vector<int> vec(n, c);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << std::endl;

    g_mutex.unlock();
}


template<typename ... Args >
void threadFunc(Args&& ... args)
{
    try
    {
        doThreadFunc(std::forward<Args>(args)...);
    }
    catch (...)
    {
    }
}



void threadFunc1(std::string &str, int* a)
{
    str = "change by threadFunc";
    *a = 13;
}

int main()
{
    std::string str("main");
    int a = 9;
    std::thread th(threadFunc1, std::ref(str), &a);

    th.join(); //主线程通过调用join()函数，等待线程运行完毕。主线程调用join函数后会进入等待状态，直至次线程运行完毕后，主线程才从join函数返回。
    // 不同于pthread_join可以获取线程函数的返回值，std::thread的join函数并不能获取线程函数的返回值。

    //调用detach函数后，std::thread变量会和其关联的线程失去关联，由C++运行库释放相关的线程资源。

    std::cout<<"str = " << str << std::endl;
    std::cout<<"a = " << a << std::endl;

    std::thread th1([] {threadFunc(10, '*'); });//这么蹩脚的写法是因为threadFunc需要先实例化
    std::thread th2([] {threadFunc(5, '#'); });

    th1.join();
    th2.join();

    return 0;
}