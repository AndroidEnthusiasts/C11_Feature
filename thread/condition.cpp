#include <climits>
//
// Created by Jesson on 2021/2/23.
//

#include<thread>
#include<iostream>
#include<mutex>
#include<list>
#include<condition_variable>
#include <unordered_map>
#include <functional>

using namespace std;
std::mutex g_mutex;
std::condition_variable cond;

//std::unordered_map test;




std::list<int> alist;

struct hashfunc{
    template<typename T,typename U>
    size_t operator()(const pair<T,U> &i) const {
        return hash<T>()(i.first) ^ hash<T>()(i.second);
    }
};

void threadFun1()
{
    std::unique_lock<std::mutex> ul(g_mutex);

//    std::unordered_map<pair<int,int>,int,hashfunc> map;

    while (alist.empty())
    {
        cond.wait(ul); //condition_variable的wait()函数会对ul调用unlock()进行解锁，
    }

    std::cout << "threadFun1 get the value : " << alist.front() << std::endl;
    alist.pop_front();
}


void threadFun2()
{
    std::lock_guard<std::mutex> lg(g_mutex);
    alist.push_back(13);
    cond.notify_one();
}


int main()
{

    std::thread th3 ;
    std::thread th1(threadFun1);
    std::thread th2(threadFun2);

    th1.join();
    th2.join();

    return 0;
}