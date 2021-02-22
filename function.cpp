//
// Created by Jesson on 2021/2/18.
//

#include <iostream>
#include <map>
#include <functional>
/***
 * function可以将普通函数，lambda表达式和函数对象类统一起来。
 * 它们并不是相同的类型，然而通过function模板类，可以转化为相同类型的对象（function对象），
 * 从而放入一个map里。
 *
 */

using namespace std;

// 普通函数
int add(int i, int j) { return i + j; }
// lambda表达式
auto mod = [](int i, int j){return i % j; };
// 函数对象类
struct divide
{
    int operator() (int denominator, int divisor)
    {
        return denominator / divisor;
    }
};


int main(int argc, char *argv[])
{
// 受限的map
    map<char, int(*)(int, int)> binops_limit;
    binops_limit.insert({ '+', add });
    binops_limit.insert({ '%', mod });
// 错误 1 error C2664: “void std::_Tree<std::_Tmap_traits<_Kty,_Ty,_Pr,_Alloc,false>>::insert(std::initializer_list<std::pair<const _Kty,_Ty>>)”: 无法将参数 1 从“initializer-list”转换为“std::pair<const _Kty,_Ty> &&”
    //binops_limit.insert({ '%', divide() });

// 更灵活的map
    map<char, function<int(int, int)>> binops =
            {
                    { '+', add },
                    { '-', minus<int>() },
                    { '*', [](int i, int j){return i - j; } },
                    { '/', divide() },
                    { '%', mod },
            };
    cout << binops['+'](10, 5) << endl;
    cout << binops['-'](10, 5) << endl;
    cout << binops['*'](10, 5) << endl;
    cout << binops['/'](10, 5) << endl;
    cout << binops['%'](10, 5) << endl;
    return 0;
}

