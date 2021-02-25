//
// Created by Jesson on 2021/2/25.
//

#include <cstdlib>
#include <cstdio>
#include <list>
#include <iostream>

using namespace std;

void printList(list<int>& mlist) {
    for (auto it = mlist.begin(); it != mlist.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}

bool compare(int v1, int v2) {
    return v1 < v2;
}

int main(){
    list<int> mlist1;
    list<int> mlist2(10, 10); //有参构造
    list<int> mlist3(mlist2);//拷贝构造
    list<int> mlist4(mlist2.begin(), mlist2.end());
    cout << "list init test: " << endl;
    printList(mlist4);
    cout << endl;


    list<int> mlist;
    for (int i = 0; i < 10; i++) {
        mlist.push_back(i);
    }
    printList(mlist);

    //容器元素反转
    mlist.reverse();
    cout << "resverse list test: " << endl;
    printList(mlist);

    mlist.sort(compare);
    printList(mlist);
}