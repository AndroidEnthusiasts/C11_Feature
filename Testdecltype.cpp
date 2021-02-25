//
// Created by Jesson on 2021/2/23.
//

#ifndef C__11_FEATURE_TESTDECLTYPE_CPP
#define C__11_FEATURE_TESTDECLTYPE_CPP
#include <cstdio>
#include <cstdlib>

using namespace std;

//decltype 和function 结合
template <typename T1, typename T2>
auto compose(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    int i=0, j=10;
    printf("%d",compose(1,2));
    return 0;
}



#endif //C__11_FEATURE_TESTDECLTYPE_CPP
