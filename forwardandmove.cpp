//
// Created by Jesson on 2021/2/25.
//
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>


template<class Function, class ... Args>
    inline auto FuncWrapper(Function && f, Args && ... args)->decltype(f(std::forward<Args>(args)...))
     {
         return f(std::forward<Args>(args)...);
     }



 void test0()
 {
     std::cout << "void" << std::endl;
 }

 int test1()
 {
     return 1;
 }

 int test2(int x)
 {
     return x;
 }

 std::string test3(std::string s1, std::string s2)
 {
     return s1+s2;
 }

 int main(){
     FuncWrapper(test0);  //没有返回值，打印1
     std::cout << FuncWrapper(test1) << std::endl;
     std::cout << FuncWrapper(test2,2) << std::endl;
     std::cout << FuncWrapper(test3,"tang","miao") << std::endl;
 }