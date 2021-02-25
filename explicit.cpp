//
// Created by Jesson on 2021/2/24.
//

//首先, C++中的explicit关键字只能用于修饰只有一个参数的类构造函数,
// 它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是implicit,
// 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).
#include <cstdio>
#include <cstdlib>

class CPlusPlusString  // 使用关键字explicit的类声明, 显示转换
{
public:
    char *_pstr;
    int _size;
    explicit CPlusPlusString(int size)
    {
        _size = size;
        //...
    }
    CPlusPlusString(const char *p)
    {
        //...
    }
};

int main(){
    CPlusPlusString string1(24);     // 这样是OK的
 //   CPlusPlusString string2 = 10;    // 这样是不行的, 因为explicit关键字取消了隐式转换
//    CPlusPlusString string3;         // 这样是不行的, 因为没有默认构造函数
    CPlusPlusString string4("aaaa"); // 这样是OK的
    CPlusPlusString string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)
//    CPlusPlusString string6 = 'c';   // 这样是不行的, 其实调用的是CxString(int size), 且size等于'c'的ascii码, 但explicit关键字取消了隐式转换
//    string1 = 2;              // 这样也是不行的, 因为取消了隐式转换
//    string2 = 3;              // 这样也是不行的, 因为取消了隐式转换
//    string3 = string1;        // 这样也是不行的, 因为取消了隐式转换, 除非类实现操作符"="的重载

        //隐式转换
        int a = 3;
        double b = 4.5;
        a + b; // a将会被自动转换为double类型，转换的结果和b进行加法操作

        int a1 = true ; // bool 类型被转换为 int 类型
        int * ptr = nullptr; //null被转换为 int *类型

}

