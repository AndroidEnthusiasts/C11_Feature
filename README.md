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