# C11_Feature

> 面向Android开发者关注C++11新特性知识点的总结


## std::bind
**C++11中提供了std::bind。bind()函数的意义就像它的函数名一样，是用来绑定函数调用的某些参数的。**
* bind的思想实际上是一种延迟计算的思想，将可调用对象保存起来，然后在需要的时候再调用。
* 这种绑定是非常灵活的，不论是普通函数、函数对象、还是成员函数都可以绑定，而且其参数可以支持占位符，比如你可以这样绑定一个二元函数auto f = bind(&func, _1, _2);调用的时候通过f(1,2)实现调用。* 简单的认为就是std::bind就是C++98提供的std::bind1st和std::bind2nd的加强版。

![image-20210222145441004](https://tva1.sinaimg.cn/large/008eGmZEly1gnwbgec1irj30hp0h3wfj.jpg)

## std::function
**在C语言的时代，我们可以使用函数指针来把一个函数作为参数传递，这样我们就可以实现回调函数的机制。到了C++11以后在标准库里引入了std::function模板类，这个模板概括了函数指针的概念。function可以将普通函数，lambda表达式和函数对象类统一起来。它们并不是相同的类型，然而通过function模板类，可以转化为相同类型的对象（function对象），从而放入一个map里**。
代码参考：function.cpp

## 线程池代码知识点
* using Task = function<void()> 是类型别名，简化了 typedef 的用法。
* delctype(expr) 用来推断 expr 的类型，和 auto 是类似的，相当于类型占位符，占据一个类型的位置。
* std::make_shared用来构造shared_ptr智能指针。
* bind 函数。
* lock_guard 是 mutex 的 stack 封装类，构造的时候 lock()，析构的时候 unlock()，是c++RAII特性体现。


## todo
threadpool 应该是编译环境问题会有错误 需要update
~~~
Scanning dependencies of target threadpool
[ 50%] Building CXX object CMakeFiles/threadpool.dir/threadpool/TestThreadPool.cpp.o
[100%] Linking CXX executable threadpool
CMakeFiles/threadpool.dir/threadpool/TestThreadPool.cpp.o: In function `std::thread::thread<std::threadpool::threadpool(unsigned short)::{lambda()#1}>(std::threadpool::threadpool(unsigned short)::{lambda()#1}&&)':
/usr/include/c++/7/thread:122: undefined reference to `pthread_create'
collect2: error: ld returned 1 exit status
CMakeFiles/threadpool.dir/build.make:94: recipe for target 'threadpool' failed
make[3]: *** [threadpool] Error 1
CMakeFiles/Makefile2:104: recipe for target 'CMakeFiles/threadpool.dir/all' failed
make[2]: *** [CMakeFiles/threadpool.dir/all] Error 2
CMakeFiles/Makefile2:116: recipe for target 'CMakeFiles/threadpool.dir/rule' failed
make[1]: *** [CMakeFiles/threadpool.dir/rule] Error 2
Makefile:131: recipe for target 'threadpool' failed
make: *** [threadpool] Error 2
~~~


https://www.stroustrup.com/C++11FAQ.html

http://www.cplusplus.com/reference/

http://gcc.gnu.org/



### variadic template

http://www.generic-programming.org/_dgregor/cpp/variadic-templates.html

```cpp
void printf(const char* s) {
  while (*s) {
    if (*s == '%' && *++s != '%') 
      throw std::runtime_error("invalid format string: missing arguments");
    std::cout << *s++;
  }
}
template
void printf(const char* s, const T& value, const Args&... args) {
  while (*s) {
    if (*s == '%' && *++s != '%') {
      std::cout << value;
      return printf(++s, args...);
    }
    std::cout << *s++;
  }
  throw std::runtime_error("extra arguments provided to printf");
}
```

### nullptr

c语言中NULL为void类型的指针，但允许将NULL定义为0。c++中将NULL定义为整数0(具体还要看编译器支不支持)。

```cpp
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
```

### function

```cpp
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

 map<char, function<int(int, int)>> binops; //function可以将普通函数，lambda表达式和函数对象类统一起来。
```

### explicit vs implicit

**C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式)。
记住：多形参调构造函数是没有构造函数的隐式转换，所以没必要声明explicit。Google建议单参数要加上explicit。**

### decltype、auto、using

**随着程序越来越复杂，程序中用到的类型也越来越多，这种复杂性体现在两个方面。一是一些类型难于“拼写”，它们的名字既难记又容易写错，还无法明确体现其真实目的和含义。二是有时候根本搞不清到底需要的类型是什么，程序员不得不回过头去从程序的上下文寻求帮助。所以可以借助别名。**
**type alias**

```cpp
typedef unsigned long idx;

using idx = unsigned long;

//基本类型
typedef double wages;  // 用一个double存储工资wages
using wages = double; // 同上

//自定义数据类型
class MassachusettsInstituteOfTechnology;
typedef MassachusettsInstituteOfTechnology MIT;
using MIT = MassachusettsInstituteOfTechnology;


//指针
typedef char *pstring;
pstring ps = "hello world";


typedef string name;
typedef bool (*pCompare)(const name &, const name &);//函数指针+引用别名
```

**decltype：**

```cpp
//简单函数模版
template<typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}


template<class T1, class U1>
auto Test(T1 x, U1 y)->decltype(x+y) //auto和decltype是成对使用，返回的就是decltype括号里面的类型。->decltype()是 后置返回类型
{
    typedef decltype(x+y) xy_type;  //xy_type是函数decltype(x+y)的别名
    xy_type xytype=x+y;             //函数decltype(x+y)声明后面的参数类型为x+y类型
    xy_type arr[10];
    xy_type &rxy=arr[3];
    return x+y;
}
```

**当有不同类型的数据进行混合运算，最终的返回结果无法确定是什么类型。此时，我们可以使用auto和decltype关键字来确定函数模板的返回值类型。**

### =default & =delete

**编译器默认为一个类生成的默认函数。**

# 1. 默认构造函数
# 2. 默认析构函数
# 3. 默认拷贝构造函数
# 4. 默认赋值函数
# 5. 移动构造函数
# 6. 移动拷贝函数

```c
class Data {
public:
    Data ()      =delete            // default constructor
    ~Data ()                 // destructor

    Data (const Data & rhs)         　 　  // copy constructor
    Data & operator=(const Data & rhs)    // copy assignment operator

    Data (const Data && rhs)         // C++11, move constructor
    Data & operator=(Data && rhs)    // C++11, move assignment operator
};

//禁止使用编译器默认生成的函数 = delete; =default来要求编译器生成一个默认函数
```

### lambda

https://en.cppreference.com/w/cpp/language/lambda

表达式：

```c
[capture list] (params list) mutable exception-> return type { function body }
```

**各项具体含义如下**

# 1. capture list：捕获外部变量列表
# 2. params list：形参列表
# 3. mutable指示符：用来说用是否可以修改捕获的变量
# 4. exception：异常设定
# 5. return type：返回类型
# 6. function body：函数体

| 捕获形式    | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| [变量名, …] | 默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&说明符） |
| [this]      | 以值的形式捕获this指针                                       |
| [=]         | 以值的形式捕获所有外部变量                                   |
| []          | 不捕获任何外部变量                                           |
| [&]         | 以引用形式捕获所有外部变量                                   |
| [=, &x]     | 变量x以引用形式捕获，其余变量以传值形式捕获                  |
| [&, x]      | 变量x以值的形式捕获，其余变量以引用形式捕获                  |

### C++11并发与多线程

#### **并发、进程、线程的基本概念和综述**

**并发**

- 两个或者更多的任务（独立的活动）同时发生（进行）：一个程序同时执行多个独立的任务；
- 以往计算机，单核cpu（中央处理器）：某一个时刻只能执行一个任务，由操作系统调度，每秒钟进行多次所谓的“任务切换”。并发的假象（不是真正的并发），切换（上下文切换）时要保存变量的状态、执行进度等，存在时间开销；
- 随着硬件发展，出现了多处理器计算机：用于服务器和高性能计算领域。台式机：在一块芯片上有多核（一个CPU内有多个运算核心，对于操作系统来说，每个核心都是作为单独的CPU对待的）：双核，4核，8核，10核（自己的笔记本是4核8线程的）。能够实现真正的并行执行多个任务（硬件并发）
- 使用并发的原因：主要就是同时可以干多个事，提高性能。

***进程***

- 运行一个可执行程序，在windows下，可双击；在linux下，./文件名
- 进行，一个可执行程序运行起来了，就叫创建了一个进程。进程就是运行起来的可执行程序。

#### **C++11新标准线程库**

以前的做法：

- windows：CreateThread(), _beginthread(),_beginthreadexe()创建线程；
- linux：pthread_create()创建线程；不能跨平台
- 临界区，互斥量
- POSIX thread(pthread):跨平台，但要做一番配置，也不方便

*C++11*：

- 从C++11新标准，C++语言本身增加对多线程的支持，意味着可移植性（跨平台），这大大减少开发人员的工作量

**C++11核心的头文件：**

- <atomic>：该头文主要声明了两个类, std::atomic 和 std::atomic_flag，另外还声明了一套 C 风格的原子类型和与 C 兼容的原子操作的函数。
- <thread>：该头文件主要声明了 std::thread 类，另外 std::this_thread 命名空间也在该头文件中。
- <mutex>：该头文件主要声明了与互斥量(mutex)相关的类，包括 std::mutex 系列类，std::lock_guard, std::unique_lock, 以及其他的类型和函数。
- <condition_variable>：该头文件主要声明了与条件变量相关的类，包括 std::condition_variable 和 std::condition_variable_any。
- <future>：该头文件主要声明了 std::promise, std::package_task 两个 Provider 类，以及 std::future 和 std::shared_future 两个 Future 类，另外还有一些与之相关的类型和函数，std::async() 函数就声明在此头文件中。


### c++11 左值，右值，左值引用，右值引用
**左值就是有名字的变量（对象），可以被赋值，可以在多条语句中使用，而右值呢，就是临时变量（对象），没有名字，只能在一条语句中出现，不能被赋值。**
~~~
int a = 10; //左值是有固定的内存地址，&a即左值的地址，我们可以把&a保存起来，后续通过&a这个地址读取、修改a的内容 但是a的数值是不确定的 地址也获取不到
~~~

**移动构造函数 （减少了开辟内存，构造成本就降低了。）** 
Tips:拷贝构造函数中，对于指针，我们一定要采用深层复制，而移动构造函数中，对于指针，我们采用浅层复制。
~~~
....
Str(char value[])
        {
            cout<<"普通构造函数..."<<endl;
            str = NULL;
            int len = strlen(value);
            str = (char *)malloc(len + 1);
            memset(str,0,len + 1);
            strcpy(str,value);
        }
        Str(const Str &s)
        {
            cout<<"拷贝构造函数..."<<endl;
            str = NULL;
            int len = strlen(s.str);
            str = (char *)malloc(len + 1);
            memset(str,0,len + 1);
            strcpy(str,s.str);
        }
        Str(Str &&s) //注意这里的写法 
        {
            cout<<"移动构造函数..."<<endl;
            str = NULL;
            str = s.str;
            s.str = NULL;
        }
        ~Str()
        {
            cout<<"析构函数"<<endl;
            if(str != NULL)
            {
                free(str);
                str = NULL;
            }
        }
...
~~~


### c++11  std::move & std::forward

**std::move 把一个左值引用“强制转换”为右值引用。** 
~~~
template< class T >
typename std::remove_reference<T>::type&& move( T&& t ) noexcept;
~~~
https://tva1.sinaimg.cn/large/008eGmZEly1gnzw2bq85bj30eu0l4dkn.jpg


**std::forward 谓完美转发（perfect forwarding），是指在函数模板中，完全依照模板的参数的类型，将参数传递给函数模板中调用的另外一个函数。c++11中提供了这样的一个函数std::forward，它是为转发而生的，它会按照参数本来的类型来转发出去，不管参数类型是T&&这种未定的引用类型还是明确的左值引用或者右值引用。**