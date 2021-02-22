# C11_Feature

> 面向Android开发者关注C++11新特性知识点的总结


## std::function
**C++11中提供了std::bind。bind()函数的意义就像它的函数名一样，是用来绑定函数调用的某些参数的。**
* bind的思想实际上是一种延迟计算的思想，将可调用对象保存起来，然后在需要的时候再调用。
* 这种绑定是非常灵活的，不论是普通函数、函数对象、还是成员函数都可以绑定，而且其参数可以支持占位符，比如你可以这样绑定一个二元函数auto f = bind(&func, _1, _2);调用的时候通过f(1,2)实现调用。* 简单的认为就是std::bind就是C++98提供的std::bind1st和std::bind2nd的加强版。

![image-20210222145441004](https://tva1.sinaimg.cn/large/008eGmZEly1gnwbgec1irj30hp0h3wfj.jpg)

## std::function
**在C语言的时代，我们可以使用函数指针来把一个函数作为参数传递，这样我们就可以实现回调函数的机制。到了C++11以后在标准库里引入了std::function模板类，这个模板概括了函数指针的概念。function可以将普通函数，lambda表达式和函数对象类统一起来。它们并不是相同的类型，然而通过function模板类，可以转化为相同类型的对象（function对象），从而放入一个map里**。
代码参考：function.cpp
