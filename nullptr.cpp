//
// Created by Jesson on 2021/2/24.
//

//C语言中NULL定义
#define NULL (void*)0                //c语言中NULL为void类型的指针，但允许将NULL定义为0

//c++中NULL的定义
#ifndef NULL
#ifdef _cpluscplus
#define NULL 0                         //c++中将NULL定义为整数0
#else
#define NULL ((void*)0)             //c语言中NULL为void类型的指针
#endif
#endif
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstddef>
void fun(int i){std::cout<<"1";};
void fun(char *p){std::cout<<"2";};
int main()
{
    //fun(NULL);  if NULL=0 输出1 否则ambiguous 编译器不知道
    fun(nullptr);//输出2，nullptr 为空指针常量。是指针类型

//    std::nullptr_t;
}