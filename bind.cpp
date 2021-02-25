//
// Created by Jesson on 2021/2/22.
//
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

class View{
public:
    void onClick(int x,int y){
        cout<<"x:"<<x<<"y:"<<y<<endl;
    }
};

function<void(View ,int ,int )> clickCall;

int TestBindFunc(int a, int c, int f)
{
    cout << a << endl;
    cout << c << endl;
    cout << f << endl;
    return a;
}



int main(){
    vector<int> datas;
    for (int i = 0; i < 10; ++i) {
            datas.push_back(i);
    }

    View button;

    clickCall = &View::onClick; //指向成员函数

    clickCall(button,10,22);

    //测试bind
    auto bindFunc  = bind(TestBindFunc,1,2,3);
    bindFunc();

    //利用std::placeholders 占位符可以完成参数顺序的改变
    auto bindFunc1  = bind(TestBindFunc,std::placeholders::_1,std::placeholders::_2,3);
//    bindFunc1(4);

    /***
     * bind 完成函数的转换、参数顺序的改变
     */

}

