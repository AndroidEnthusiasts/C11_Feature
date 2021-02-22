#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
std::mutex mt;


void share(int a){

}


void myPrint(int a,int b)
{
    cout << "我的线程开始运行" << endl;
    //-------------
    //-------------
    cout << "我的线程运行完毕" << endl;
    printf("第一个参数是%d\n",a);
    printf("第一个参数是%d\n",b);
    return;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    thread myThread(myPrint,1,2);
    myThread.join();
    if (myThread.joinable())
    {
        cout << "可以调用可以调用join()或者detach()" << endl;
    }
    else
    {
        cout << "不能调用可以调用join()或者detach()" << endl;
    }
    return 0;
}
