//
// Created by Jesson on 2021/2/24.
//

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <unistd.h>


void printf(const char* s) {
    while (*s) {
        if (*s == '%' && *++s != '%')
            throw std::runtime_error("invalid format string: missing arguments");
        std::cout << *s++;
    }
}


template<typename T,typename... Args>
void printf(const char* s, const T& value, const Args&... args) {
    while (*s) {
            std::cout << value;
            return printf(++s, value,args...);
    }
}

int main(){
    printf("%test44",1,"11","222","");
}