//
// Created by Jesson on 2021/2/23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return  a < b;
}

/**
 * Top！
 * @tparam T
 * @param array
 * @param num
 * @param index
 */
template<class T>
void argsort(T *array, int num, int *index) {
    const auto function = [array](int a, int b) mutable -> bool {
        if(a>b)
        throw "$$$$$";
        return array[a] < array[b];

    };
    assert(num < INT_MAX);
    int *temp = new int[num];
    std::sort(temp, temp + num, function);
    memcpy(index, temp, num * sizeof(int));
    delete[] temp;
}



int main()
{
    vector<int> myvec{ 3, 2, 5, 7, 3, 2 };
    vector<int> lbvec(myvec);

    sort(myvec.begin(), myvec.end(), cmp); // 旧式做法
    cout << "predicate function:" << endl;
    for (int it : myvec)
        cout << it << ' ';
    cout << endl;

    sort(lbvec.begin(), lbvec.end(), [](int a, int b)  -> bool { return a < b; });   // Lambda表达式
    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ';

    printf("==================\n");

    int a = 123;
    auto f = [a] { cout << a << endl; }; //捕获外部变量
    a = 321;
    f(); // 输出：123 还是321
    //怎么修改？？
    int a1 = 123;
    auto f1 = [&a1] { cout << a1 << endl; };
    a1 = 321;
    f1(); // 输出：321



    int a2 = 123;
    auto f2 = [a2]() mutable{ cout << ++a2; }; // 不会报错
    cout << a2 << endl; // 输出：123
    f2(); // 输出：124

    std::function<int(int,int)> fun2 = [=](int a,int b) {return a+b; };
    cout <<"\n" <<"fun2(3)=" << fun2(3,5) << endl;


}
