//
// Created by Jesson on 2021/2/24.
//
//https://en.cppreference.com/w/cpp/language/converting_constructor

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <complex>
#include <set>
#include <list>
#include "../../../../Library/Developer/CommandLineTools/usr/include/c++/v1/locale"

void print(std::initializer_list<int> list) {
    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


int main(){
        int values[]{ 1, 2, 3 };
        std::vector<int> v{ 2, 3, 6, 7 };
        std::vector<std::string> cities{
            "Berlin", "New York", "London",  "Braunschweig"
        };
        std::complex<double> c{4.0, 3.0}; //等价于 c(4.0, 3.0)
        auto ar = { 1, 2, 3 };  // ar 是一个std::initializer_list<int>类型

        std::vector<int> v1 = { 1, 2, 3 };
        std::set<int> s = { 1, 2, 3 };
        std::map<int, std::string> m = { {1, "a"}, {2, "b"} };
        std::list<int> ss = {1,2,3,4};

         //std::initializer_list
    print({ 1,2,3,4,5,6,7 });

    //https://codechina.csdn.net/mirrors/nlohmann/json/-/blob/develop/test/src/unit-readme.cpp#L117

    
//    std::map<std::string,int>::value_type
}
