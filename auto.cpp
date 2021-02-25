//
// Created by Jesson on 2021/2/24.
//

//https://www.stroustrup.com/C++11FAQ.html#auto

// the use of auto
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<double, double> result;
    result.insert(pair<double, double>(1.2, 2.2));
    result.insert(pair<double, double>(1.5, 2.8));
    auto it = result.begin(); //看编译器的提示 auto
    for(; it != result.end(); ++it) {
        cout << it->first << "  "  << it->second << endl;
    }
    // use auto
    cout << __func__ << ",use auto ! " << endl;
    for(auto it = result.begin(); it != result.end(); ++it) {
        cout << it->first << "  "  << it->second << endl;
    }

    return 0;
}